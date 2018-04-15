//
//  RenderSystem.h
//  Space
//
//  Created by Ali on 26/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef RenderSystem_h
#define RenderSystem_h

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "MenuRenderer.h"
#include "EventSystem.h"
#include "GameMode.h"
#include <vector>

class RenderSystem:EventListener{
public:
    void render(GameMode game_mode);
    RenderSystem();
    ~RenderSystem();
    double calculateFrameRate();
    void setupEvents(EventSystem *es);
    virtual void receiveEvent(Event *e);
    
private:
    SDL_Window *window;
    SDL_Renderer *sdl_renderer;
    MenuRenderer *menu_renderer;
    std::vector<Uint32> frame_rate_sample;
    bool cap_fps = false;

};


#endif /* RenderSystem_h */
