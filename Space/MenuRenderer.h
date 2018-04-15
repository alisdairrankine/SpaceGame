//
//  MenuRenderer.hpp
//  Space
//
//  Created by Ali on 27/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef MenuRenderer_h
#define MenuRenderer_h

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "EventSystem.h"
#include "Window.h"

class MenuRenderer:public EventListener{
public:
    MenuRenderer();
    ~MenuRenderer();
    void setFrameRate(double frame_rate);
    
    void render(SDL_Renderer *sdl_renderer);
    void setupEvents(EventSystem *es);
    virtual void receiveEvent(Event *e);
    TTF_Font *getSmallFont();
    
private:
    void drawWindow(SDL_Renderer *sdl_renderer,Window *window,bool withCloseButton);
    void renderFramerate(SDL_Renderer *sdl_renderer);
    std::vector<Window*> active_windows;
    int getWindowIdForClick(SDL_MouseButtonEvent *mouse_event);
    TTF_Font *small_font;
    double framerate;
};




#endif /* MenuRenderer_h */
