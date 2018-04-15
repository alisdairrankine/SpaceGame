//
//  RenderSystem.cpp
//  Space
//
//  Created by Ali on 26/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <stdexcept>
#include <sstream>
#include <iostream>

#include "RenderSystem.h"
#include "GameSystem.h"
#include <ctime>
#include <numeric>

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

RenderSystem::RenderSystem(){
    //init window
    
    window = NULL;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    
    int window_width = 640;
    int window_height = 480;
    std::string title = "space";
    
    window = SDL_CreateWindow(title.c_str(),0,0,window_width,window_height,SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        throw std::runtime_error("could not initialise window");
    }
    //render system is now ready to go.
    sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    
    
    menu_renderer = new MenuRenderer();
    
    
}

double RenderSystem::calculateFrameRate(){
    double sum = std::accumulate(frame_rate_sample.begin(), frame_rate_sample.end(), 0.0);
    double mean = sum / frame_rate_sample.size();
    return 1000/mean ;
    
}

RenderSystem::~RenderSystem(){
    
    SDL_DestroyRenderer(sdl_renderer);
    // Close and destroy the window
    SDL_DestroyWindow(window);
    
    // Clean up
    SDL_Quit();
}

void RenderSystem::render(GameMode game_mode){
    
    
    Uint32 start = SDL_GetTicks();
    
    SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);
    
    SDL_SetRenderDrawColor(sdl_renderer, 229, 255, 229, 255);
    SDL_RenderClear(sdl_renderer);
    SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
    
    
    //tidy this up
    if (game_mode == GAMEMODE_MENU){
        if (menu_renderer){
            menu_renderer->setFrameRate(calculateFrameRate());
            menu_renderer->render(sdl_renderer);
        }
    }
    
    
    //if in game mode
    //  render tiles in view to world
    //  update
    
    //update window
    SDL_RenderPresent(sdl_renderer);
    Uint32 duration = SDL_GetTicks() - start;
    if (cap_fps && duration<SCREEN_TICKS_PER_FRAME){
        SDL_Delay(SCREEN_TICKS_PER_FRAME-duration-1);
    }
    if (frame_rate_sample.size()>1000){
        frame_rate_sample.clear();
        menu_renderer->setFrameRate(calculateFrameRate());
    }
    frame_rate_sample.push_back(SDL_GetTicks() - start);
}

void RenderSystem::receiveEvent(Event *event){
    SDL_Event e = event->raw_event;
    if(e.key.keysym.sym == SDLK_f){
        if(e.key.keysym.mod & KMOD_SHIFT){
            std::cout<<"toggle fps cap"<<std::endl;
            cap_fps = !cap_fps;
            frame_rate_sample.clear();
        }
    }
}

void RenderSystem::setupEvents(EventSystem *es){
    es->attachListener(this,"key-down");
    menu_renderer->setupEvents(es);
}