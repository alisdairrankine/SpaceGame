//
//  EventSystem.hpp
//  Space
//
//  Created by Ali on 26/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef EventSystem_h
#define EventSystem_h

#include <string>
#include <map>
#include <vector>
#include <SDL2/SDL.h>

typedef struct Event {
    std::string event_name;
    SDL_Event raw_event;
} Event;

class EventListener{
public:
    virtual void receiveEvent(Event *event){/* do nothing*/}
};

class EventSystem{
    
private:
    std::map<std::string,std::vector<EventListener*>> listeners;
    
public:
    EventSystem();
    ~EventSystem();
    
    void attachListener(EventListener *listener,std::string event_name);
    void triggerEvent(Event *e);
};

#endif /* EventSystem_h */
