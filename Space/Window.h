//
//  Window.hpp
//  Space
//
//  Created by Ali on 29/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef Window_h
#define Window_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2_ttf/SDL_ttf.h>
#include "EventSystem.h"
#include "Widget.h"

enum WindowType{
    WINDOW_CLOSABLE = 1,
    WINDOW_NOTCLOSABLE = 2
};

class Window{
    
public:
    Window(SDL_Rect *rect, std::string title);
    Window(SDL_Rect *rect, std::string title,WindowType type);
    
    SDL_Rect *getRectangle();
    std::string getTitle();
    
    void render(TTF_Font *small_font,SDL_Renderer *renderer);
    
    bool pointIsInWindow(int x, int y);
    
    void receiveEvent(Event *event);
    
    bool isAlive();
    
private:
    
    bool pointIsInRectangle(SDL_Rect *rect,int x, int y);
    
    SDL_Rect *m_rectangle;
    std::string m_title;
    WindowType m_type;
    bool m_alive = true;
    std::vector<Widget*> m_widgets;
    
};



#endif /* Window_h */
