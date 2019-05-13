//
//  Board.h
//  glutapp
//
//  Created by Rene Jaimes on 5/9/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <stdio.h>
#include <vector>
#include "Row.h"

class Board
{
    std::vector<Row*> rows;
    
public:
    
    Board(std::vector<std::string>, float, float, float, float, int, float, float);
    
    virtual void draw();
    
    float getRowY(int);
    
    ~Board();
};

#endif /* Board_h */
