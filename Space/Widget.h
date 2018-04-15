//
//  Widget.hpp
//  Space
//
//  Created by Ali on 29/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef Widget_h
#define Widget_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include "EventSystem.h"

class Widget{
public:
    void setRectangle(SDL_Rect *rectangle){};
    void render(SDL_Renderer *renderer){};
    void receiveEvent(Event *e){};
private:
    SDL_Rect *m_rectangle;
};

#endif /* Widget_h */
