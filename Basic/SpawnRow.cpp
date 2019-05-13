//
//  SpawnRow.cpp
//  glutapp
//
//  Created by Rene Jaimes on 5/12/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include "SpawnRow.h"
#include <random>
#include <cstdlib>

SpawnRow::SpawnRow(std::string file, float startX, float rowY, float wid, float hei, int rate, int RectNum)
{
    LeftToRight = startX < 0.0;
    
    spawnFile = file;
    startingPoint = startX;
    rowsY = rowY;
    w = wid;
    h = hei;
    
    int attempts = 0;
    
    float randomFloat = ((float) rand()) / (float) RAND_MAX;
    randomFloat = ((float) rand()) / (float) RAND_MAX;
    randomFloat *= (startX - w) * 2;
    randomFloat += (startX - w);
    
    for (int L = 0; L < RectNum; L++)
    {
        while (VecContains(randomFloat, rowY, wid, hei) && attempts < 14)
        {
            randomFloat = ((float) rand()) / (float) RAND_MAX;
            randomFloat *= (startX - w) * 2;
            randomFloat += (startX - w);
            attempts++;
        }
        
        if (attempts < 14)
        {
            obstacles.push_back(new TexRect(spawnFile.c_str(), randomFloat, rowsY, w, h));
        }
        else
        {
            attempts = 0;
        }
    }
    
    setRate(rate);
    
    start();
}

void SpawnRow::draw()
{
    for (std::vector<TexRect*>::iterator i = obstacles.begin(); i != obstacles.end(); ++i)
    {
        (*i)->draw(0.1);
    }
}

void SpawnRow::action()
{
    float buffer = startingPoint * (-1);
    
    if (!LeftToRight)
    {
        buffer -= w;
    }
    
    for (std::vector<TexRect*>::iterator i = obstacles.begin(); i != obstacles.end(); ++i)
    {
        float xPos = (*i)->getX();
        
        if ((xPos >= buffer && LeftToRight) || (xPos <= buffer && !LeftToRight))
        {
            if (LeftToRight)
            {
                (*i)->setX(startingPoint - w);
            }
            else
            {
                (*i)->setX(startingPoint);
            }
            continue;
        }
        
        if((*i)->getX() < buffer && LeftToRight)
        {
            xPos += 0.01;
            (*i)->setX(xPos);
        }
        else if ((*i)->getX() > buffer && !LeftToRight)
        {
            xPos -= 0.01;
            (*i)->setX(xPos);
        }
    }
}

void SpawnRow::newSpawn()
{
    float buffer = startingPoint;
    
    if (LeftToRight)
    {
        buffer -= w;
    }
    
    obstacles.push_back(new TexRect(spawnFile.c_str(), buffer, rowsY, w, h));
}

bool SpawnRow::VecContains(float x, float y, float w, float h)
{
    for (std::vector<TexRect*>::iterator i = obstacles.begin(); i != obstacles.end(); ++i)
    {
        if ((*i)->contains(x, y) || (*i)->contains(x + w, y) || (*i)->contains(x, y + h) || (*i)->contains(x + w, y + h))
        {
            return true;
        }
    }
    return false;
}

SpawnRow::~SpawnRow()
{
    for (std::vector<TexRect*>::iterator i = obstacles.begin(); i != obstacles.end(); ++i)
    {
        delete *i;
    }
}
