//
//  InputSystem.cpp
//  Space
//
//  Created by Ali on 27/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#include "InputSystem.h"
#include <SDL2/SDL.h>

InputSystem::InputSystem(EventSystem *es){
    event_system = es;
}

void InputSystem::pollAndTriggerEvents(){
    SDL_Event e;
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
            Event quit  = Event{"quit",e};
            event_system->triggerEvent(&quit);
        }
//        if (e.type == SDL_KEYDOWN){
//            Event quit  = Event{"quit",e};
//            event_system->triggerEvent(&quit);
//        }
        if (e.type == SDL_MOUSEBUTTONDOWN){
            Event click  = Event{"mouse-down",e};
            event_system->triggerEvent(&click);
        }
        if (e.type ==  SDL_KEYDOWN){
            Event key = Event{"key-down",e};
            event_system->triggerEvent(&key);
        }
    }
}