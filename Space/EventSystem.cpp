//
//  EventSystem.cpp
//  Space
//
//  Created by Ali on 26/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#include "EventSystem.h"
#include <iostream>

EventSystem::EventSystem(){
    //do nothing?
}

EventSystem::~EventSystem(){
    //do nothing?
}

void EventSystem::triggerEvent(Event *e){

    std::vector<EventListener*> correct_listeners = listeners[e->event_name];
    for (int i = 0; i<correct_listeners.size();++i){
        correct_listeners.at(i)->receiveEvent(e);
    }
}

void EventSystem::attachListener(EventListener *listener, std::string event_name){
    std::vector<EventListener*> correct_listeners = listeners[event_name];
    correct_listeners.push_back(listener);
    listeners[event_name] = correct_listeners;
}