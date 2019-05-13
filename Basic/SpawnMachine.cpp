//
//  SpawnMachine.cpp
//  glutapp
//
//  Created by Rene Jaimes on 5/12/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include "SpawnMachine.h"
#include "SpawnRow.h"
#include <vector>

SpawnMachine::SpawnMachine(){}

void SpawnMachine::draw()
{
    for (std::vector<SpawnRow*>::iterator i = spawners.begin(); i != spawners.end(); ++i)
    {
        (*i)->draw();
    }
}

void SpawnMachine::AddSpawner(SpawnRow* spawn)
{
    spawners.push_back(spawn);
}

void SpawnMachine::startTimers()
{
    for (std::vector<SpawnRow*>::iterator i = spawners.begin(); i != spawners.end(); ++i)
    {
        (*i)->StartIt();
    }
}

void SpawnMachine::stopTimers()
{
    for (std::vector<SpawnRow*>::iterator i = spawners.begin(); i != spawners.end(); ++i)
    {
        (*i)->StopIt();
    }
}

SpawnMachine::~SpawnMachine()
{
    for (std::vector<SpawnRow*>::iterator i = spawners.begin(); i != spawners.end(); ++i)
    {
        delete *i;
    }
}
