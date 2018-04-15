//
//  GameSystem.hpp
//  Space
//
//  Created by Ali on 26/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef GameSystem_h
#define GameSystem_h

#include <string>
#include <map>
#include "EventSystem.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "GameMode.h"

class GameSystem : public EventListener{
public:
    
    GameSystem();
    ~GameSystem();
    
    
    
    //game states + configuration
    void initiateShutdown();
    GameMode getCurrentGameMode();
    void runLoop();
    void loadConfiguration(std::string config_file_name);
    
    //event system
    virtual void receiveEvent(Event *event);
    
    
    
    //getters
    std::string getConfigSetting(std::string setting_name);
    
    
private:
    
    //subsystems
    EventSystem *event_system;
    RenderSystem *renderer;
    InputSystem *input_system;
    
    //states and configuration
    std::map<std::string,std::string> configuration;
    GameMode current_mode;
    bool quit;
};

#endif /* GameSystem_h */
