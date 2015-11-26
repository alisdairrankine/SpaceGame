//
//  main.cpp
//  Space
//
//  Created by Ali on 24/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "GameSystem.h"
#include "EventSystem.h"

int main(int argc, const char * argv[]) {
    
    
    GameSystem *game_system = GameSystem::getInstance();
    EventSystem *event_system = new EventSystem();
    game_system->setEventSystem(event_system);
    Event event = Event{"should_not_receive",""};
    event_system->triggerEvent(&event);
    Event event2 = Event{"should_receive",""};
    event_system->triggerEvent(&event2);
    
    
    
    SDL_Window *window;                    // Declare a pointer
    
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
    
    // Create an application window with the following settings:
    window = SDL_CreateWindow(
                              "An SDL2 window",                  // window title
                              0,           // initial x position
                              0,           // initial y position
                              640,                               // width, in pixels
                              480,                               // height, in pixels
                              SDL_WINDOW_SHOWN                  // flags - see below
                              );
    
    
    
    
    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    SDL_SetWindowTitle(window, "Groblins in space");
    bool quit = false;
    int imgFlags = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    
    if( !( IMG_Init( imgFlags ) & imgFlags ) ){
        printf("Image library errored with:  %s\n",IMG_GetError());
        quit = true;
    } else {
        SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 0, 0, 0));
        SDL_Surface *image_surface = IMG_Load("spaceship.jpg");
        
        printf("loaded image\n");
        SDL_BlitSurface(image_surface,NULL,window_surface,NULL);
    }
    
    
    
    
    // The window is open: could enter program loop here (see SDL_PollEvent())
    
    SDL_Event e;
    
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                //                quit = true;
            }
        }
        
        SDL_UpdateWindowSurface(window);
    }
    
    // Close and destroy the window
    SDL_DestroyWindow(window);
    
    // Clean up
    SDL_Quit();
    return 0;
}
