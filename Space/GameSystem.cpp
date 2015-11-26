//
//  GameSystem.cpp
//  Space
//
//  Created by Ali on 26/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//
#include <stdexcept>
#include <iostream>

#include "GameSystem.h"
#include "EventSystem.h"


GameSystem *GameSystem::instance;

GameSystem *GameSystem::getInstance(){
 
    if (GameSystem::instance == nullptr){
        GameSystem::instance  = new GameSystem();
    }
    if (GameSystem::instance == nullptr){
        throw std::runtime_error("could not initialize game system");
    }
    
    return GameSystem::instance;
}

GameSystem::GameSystem(){
    //initialize subsystems
    current_mode = GAMEMODE_MENU;
    
    
}

void GameSystem::setEventSystem(EventSystem *e){
    std::cout << "[GameSystem] adding event system" << std::endl;
    event_system = e;
    e->attachListener(this,"should_receive");
}

void GameSystem::receiveEvent(Event *event){

    if(event->event_name=="quit"){
            
    }
}