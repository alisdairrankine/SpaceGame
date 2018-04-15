//
//  MenuRenderer.cpp
//  Space
//
//  Created by Ali on 27/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#include "MenuRenderer.h"
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <iomanip>


bool pointIsInRect( SDL_Rect* rect, int x, int y )
{
    return ( ( x >= rect->x && x <= rect->x + rect->w ) && ( y >= rect->y && y <= rect->y + rect->h ) );
}

MenuRenderer::MenuRenderer(){
    //meh
    
    TTF_Init();
    small_font = TTF_OpenFont("LiberationSans-Regular.ttf", 15);
    framerate = 0;
    SDL_Rect *rect = new SDL_Rect{40,40,200,200};
    Window *win = new Window(
                             rect,
                             "Time to make a game"
                             );
    active_windows.push_back(win);
}

void MenuRenderer::setFrameRate(double frame_rate){
    framerate = frame_rate;
}



void MenuRenderer::render(SDL_Renderer *sdl_renderer){
    for(int i = 0;i<active_windows.size();++i){
        Window *current_window = active_windows.at(i);
        current_window->render(small_font,sdl_renderer);
    }
    renderFramerate(sdl_renderer);
}

void MenuRenderer::renderFramerate(SDL_Renderer *sdl_renderer){
    
    
    std::stringstream fr_text;
    fr_text << std::fixed;
    fr_text << std::setprecision(2);
    fr_text << framerate;
    
    SDL_Surface* title_surface = TTF_RenderUTF8_Blended(small_font, fr_text.str().c_str(), SDL_Color{0,0,0});
    SDL_Texture* message = SDL_CreateTextureFromSurface(sdl_renderer, title_surface);
    SDL_FreeSurface(title_surface);
    int w, h;
    SDL_QueryTexture(message, NULL, NULL, &w, &h);
    SDL_Rect title_rect;
    title_rect.x = 580;
    title_rect.y = 10;
    title_rect.w = w;
    title_rect.h = h;
    
    SDL_RenderCopy(sdl_renderer, message, NULL, &title_rect);
    SDL_DestroyTexture(message);
}




void MenuRenderer::receiveEvent(Event *e){
    if (e->event_name ==  "mouse-down"){
        int win_id = getWindowIdForClick(&e->raw_event.button);
        if (win_id>0){
            win_id -= 1;
            std::cout<< "window at index "<< win_id<<" clicked"<<std::endl;
            Window *win = active_windows.at(win_id);
            win->receiveEvent(e);
            if (!win->isAlive()){
                active_windows.erase(active_windows.begin()+win_id);
            }
        }
        
    }
}

int MenuRenderer::getWindowIdForClick(SDL_MouseButtonEvent *mouse_event){
    
    for(int i = 0;i<active_windows.size();++i){
        Window *current_window = active_windows.at(i);
        
        if (pointIsInRect(current_window->getRectangle(), mouse_event->x, mouse_event->y)){
            return i+1;
        }
    }
    
    return 0;
}

TTF_Font *MenuRenderer::getSmallFont(){
    return small_font;
}

void MenuRenderer::setupEvents(EventSystem *es){
    es->attachListener(this, "mouse-down");
}