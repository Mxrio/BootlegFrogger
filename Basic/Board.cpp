//
//  Board.cpp
//  glutapp
//
//  Created by Rene Jaimes on 5/9/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include "Board.h"
#include <string>

Board::Board(std::vector<std::string> files, float x, float y, float w, float h, int rowN, float max, float sepCoeff)
{
    for (int i = 0; i < rowN; i++)
    {
        std::string temp = files[i];
        rows.push_back(new Row(temp.c_str(), x, y, w, h, i, max, sepCoeff));
    }
}

void Board::draw()
{
    for (std::vector<Row*>::iterator i = rows.begin(); i != rows.end(); ++i)
    {
        (*i)->draw();
    }
}

Board::~Board()
{
    for (std::vector<Row*>::iterator i = rows.begin(); i != rows.end(); ++i)
    {
        delete *i;
    }
}
