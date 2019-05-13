//
//  Row.hpp
//  glutapp
//
//  Created by Rene Jaimes on 5/8/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef Row_h
#define Row_h

#include <stdio.h>
#include "TexRect.h"
#include <vector>

class Row
{
    std::vector<TexRect*> textures;
    int rowNum;
    
public:
    
    Row(const char*, float, float, float, float, int, float, float);
    
    virtual void draw();
    
    float getConstY();
    
    virtual ~Row();
};

#endif /* Row_h */
