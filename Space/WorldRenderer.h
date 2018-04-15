//
//  WorldRenderer.hpp
//  Space
//
//  Created by Ali on 02/12/2015.
//  Copyright © 2015 Siege Perilous Studios. All rights reserved.
//

#ifndef WorldRenderer_h
#define WorldRenderer_h

#include <SDL2/SDL.h>
#include <map>
#include <string>
#include "WorldState.h"
#include "Sprite.h"

class WorldRenderer{
public:
    WorldRenderer(WorldState *world_state);
    void Render(SDL_Renderer *renderer);
private:
    WorldState *m_world_state;
    std::map<std::string,Sprite> m_sprite_map;
    
};

#include <stdio.h>

#endif /* WorldRenderer_h*/
