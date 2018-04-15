//
//  Window.cpp
//  Space
//
//  Created by Ali on 29/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#include "Window.h"


Window::Window(SDL_Rect *rect, std::string title){
    m_rectangle = rect;
    m_title = title;
    m_type = WindowType::WINDOW_CLOSABLE;
    m_alive = true;
}

Window::Window(SDL_Rect *rect, std::string title, WindowType type){
    m_rectangle = rect;
    m_title = title;
    m_alive = true;
    m_type = type;
}

SDL_Rect *Window::getRectangle(){
    return m_rectangle;
}

std::string Window::getTitle(){
    return m_title;
}

void Window::render(TTF_Font *small_font, SDL_Renderer *sdl_renderer){
    
    //foreground colours
    Uint8 f_r = 0;
    Uint8 f_g = 0;
    Uint8 f_b = 0;
    
    //background colours
    Uint8 b_r = 0;
    Uint8 b_g = 0;
    Uint8 b_b = 0;
    
    //window background
    SDL_SetRenderDrawColor(sdl_renderer, b_r, b_g, b_b, 100);
    SDL_RenderFillRect(sdl_renderer,m_rectangle);
    
    //window border
    SDL_SetRenderDrawColor(sdl_renderer, f_r, f_g, f_b, 255);
    SDL_RenderDrawRect(sdl_renderer,m_rectangle);
    
    //close window button
    if (m_type & WindowType::WINDOW_CLOSABLE){
        SDL_Rect *exit_button = new SDL_Rect{
            m_rectangle->x + m_rectangle->w - 20,
            m_rectangle->y + 5,
            15,
            15
        };
        SDL_RenderDrawRect(sdl_renderer,exit_button);
        SDL_RenderDrawLine(sdl_renderer, exit_button->x, exit_button->y, exit_button->x+14, exit_button->y+14);
        SDL_RenderDrawLine(sdl_renderer, exit_button->x, exit_button->y+14, exit_button->x+14, exit_button->y);
    }
    
    
    // Draw the window title:
    SDL_Surface* title_surface = TTF_RenderUTF8_Blended(small_font, m_title.c_str(), SDL_Color{f_r,f_g,f_b});
    SDL_Texture* message = SDL_CreateTextureFromSurface(sdl_renderer, title_surface);
    SDL_FreeSurface(title_surface);
    int w, h;
    SDL_QueryTexture(message, NULL, NULL, &w, &h);
    SDL_Rect title_rect;
    title_rect.x = m_rectangle->x+5;
    title_rect.y = m_rectangle->y+3;
    title_rect.w = w;
    title_rect.h = h;
    
    SDL_RenderCopy(sdl_renderer, message, NULL, &title_rect);
    SDL_DestroyTexture(message);
    
    for(int i = 0;i<m_widgets.size();++i){
        Widget *widget = m_widgets.at(i);
        widget->render(sdl_renderer);
    }
    
}

void Window::receiveEvent(Event *e){
    if (e->event_name ==  "mouse-down"){
        if (m_type & WindowType::WINDOW_CLOSABLE){
            SDL_Rect *exit_button = new SDL_Rect{
                m_rectangle->x + m_rectangle->w - 20,
                m_rectangle->y + 5,
                15,
                15
            };
            if (pointIsInRectangle(exit_button, e->raw_event.button.x, e->raw_event.button.y)){
                m_alive = false;
            }
        }
    }
    
}

bool Window::pointIsInRectangle(SDL_Rect *rect,int x, int y){
    return ( ( x >= rect->x && x <= rect->x + rect->w ) && ( y >= rect->y && y <= rect->y + rect->h ) );
}

bool Window::pointIsInWindow(int x, int y){
    return this->pointIsInRectangle(m_rectangle, x, y);
}

bool Window::isAlive(){
    return m_alive;
}