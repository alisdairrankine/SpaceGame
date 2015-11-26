//
//  GameSystem.hpp
//  Space
//
//  Created by Ali on 26/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef GameSystem_h
#define GameSystem_h

#include "EventSystem.h"

enum GameMode{
    GAMEMODE_MENU,
    GAMEMODE_INGAME,
    GAMEMODE_EDITOR,
    GAMEMODE_SHUTTING_DOWN
};

class GameSystem : public EventListener{
public:
    
    ~GameSystem();
    
    static GameSystem *getInstance();
    
    //game states
    void initiateShutdown();
    
    //event system
    virtual void receiveEvent(Event *event);
    
    //setters
    void setEventSystem(EventSystem *e);
    
    //getters
    
private:
    EventSystem *event_system;
    GameSystem();
    static GameSystem *instance;
    
    GameMode current_mode;
};

#endif /* GameSystem_h */
