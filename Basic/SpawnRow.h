//
//  SpawnRow.h
//  glutapp
//
//  Created by Rene Jaimes on 5/12/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef SpawnRow_h
#define SpawnRow_h

#include <stdio.h>
#include <string>
#include "TexRect.h"
#include <vector>
#include "Timer.h"

class SpawnRow : private Timer
{
    std::string spawnFile;
    float startingPoint, rowsY, w, h;
    
    std::vector<TexRect*> obstacles;
    
    bool LeftToRight;
    
public:
    
    SpawnRow(std::string, float, float, float, float, int, int);
    
    virtual void draw();
    
    void newSpawn();
    
    void action();
    
    bool VecContains(float, float, float, float);
    
    virtual ~SpawnRow();
    
};

#endif /* SpawnRow_h */
