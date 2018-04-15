//
//  GameSystem.cpp
//  Space
//
//  Created by Ali on 26/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//
#include <stdexcept>
#include <iostream>
#include <SDL2/SDL.h>

#include "GameSystem.h"
#include "EventSystem.h"
#include "RenderSystem.h"

GameSystem::GameSystem(){
    std::cout << "Starting Game system"<<std::endl;
    //initialize subsystems
    current_mode = GAMEMODE_MENU;
    renderer = new RenderSystem();
    event_system = new EventSystem();
    event_system->attachListener(this,"quit");
    input_system = new InputSystem(event_system);
    renderer->setupEvents(event_system);
    quit = false;
    
}

void GameSystem::runLoop(){
    
    
    //todo: put events into the input system
    while (!quit){
        input_system->pollAndTriggerEvents();
        renderer->render(current_mode);
    }

}

void GameSystem::receiveEvent(Event *event){

    if(event->event_name=="quit"){
        printf("quit event received\n");
        quit = true;
    }
}

std::string GameSystem::getConfigSetting(std::string setting_name){
    return "";
}

void GameSystem::initiateShutdown(){
    current_mode = GAMEMODE_SHUTTING_DOWN;

    delete renderer;
}