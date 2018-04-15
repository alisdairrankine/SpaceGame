//
//  main.cpp
//  Space
//
//  Created by Ali on 24/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#include "GameSystem.h"
#include "EventSystem.h"

int main(int argc, const char * argv[]) {
    
    
    GameSystem *game_system = new GameSystem();
    game_system->runLoop();
    game_system->initiateShutdown();
    
    return 0;
}
