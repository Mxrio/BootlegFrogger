//
//  SpawnMachine.hpp
//  glutapp
//
//  Created by Rene Jaimes on 5/12/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef SpawnMachine_hpp
#define SpawnMachine_hpp

#include <stdio.h>
#include "SpawnRow.h"

class SpawnMachine
{
    std::vector<SpawnRow*> spawners;
    
    public:
    
    SpawnMachine();
    
    void draw();
    
    void AddSpawner(SpawnRow*);
    
    void startTimers();
    
    void stopTimers();
    
    ~SpawnMachine();
};

#endif /* SpawnMachine_hpp */
