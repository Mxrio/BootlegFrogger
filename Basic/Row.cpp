//
//  Row.cpp
//  glutapp
//
//  Created by Rene Jaimes on 5/8/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include "Row.h"
#include <iostream>

Row::Row(const char* file, float x, float y, float w, float h, int row, float max, float sepFactor)
{
    //change to synergize with Template container instead of vector
    float coordCheck = x;
    int runs = 0;
    //std::cout << "Coordcheck is " << coordCheck << std::endl;
    while(coordCheck <= max)
    {
        textures.push_back(new TexRect(file, x + ((w + sepFactor) * runs), y - (h * row), w, h));
        coordCheck = coordCheck + w + sepFactor;
        runs++;
//        std::cout << "The width is " << w << std::endl;
    }
    rowNum = row;
    
}

void Row::draw()
{
    for (std::vector<TexRect*>::iterator i = textures.begin(); i != textures.end(); ++i)
    {
        //0 = to the "z" parameter of TexRect's draw, change value if needed.
        (*i)->draw(0);
    }
}

void Row::contains()
{
    
}

Row::~Row()
{
    for (std::vector<TexRect*>::iterator i = textures.begin(); i != textures.end(); ++i)
    {
        delete *i;
    }
}
