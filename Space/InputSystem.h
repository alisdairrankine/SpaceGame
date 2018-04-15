//
//  InputSystem.hpp
//  Space
//
//  Created by Ali on 27/11/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef InputSystem_h
#define InputSystem_h

#include <stdio.h>
#include "EventSystem.h"

class InputSystem{
public:
    InputSystem(EventSystem *es);
    void pollAndTriggerEvents();
    
    
private:
    EventSystem *event_system;
};

#endif /* InputSystem_h */
