#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"

Game::Game()
{
    
    assetDirectory = "/Users/mxrio/Desktop/SHIT/school/semester6/CSE165/Frogger/FroggerAssets/";
    
    std::string purpleTile = assetDirectory + "grass_tile.png";
    std::string voidTile = assetDirectory + "void_tile.png";
    std::string riverTile = assetDirectory + "river_tile.png";
    std::string grassBackrow = "";
    std::string grassMidRow = "";
    std::string grassFrontRow = "";
    
    std::string frogN = assetDirectory + "Frog_NS.png";
    std::string frogWE = assetDirectory + "Frog_WE.png";

//    frogLives = new TexRect(frogFileName, 0.5, 0.5, 0.1, 0.1);
    
    std::vector<std::string> rowFiles;
    
    rowFiles.push_back(purpleTile);
    
    rowFiles.push_back(riverTile);
    rowFiles.push_back(riverTile);
    rowFiles.push_back(riverTile);
    rowFiles.push_back(riverTile);
    rowFiles.push_back(riverTile);
    
    rowFiles.push_back(purpleTile);
    
    rowFiles.push_back(voidTile);
    rowFiles.push_back(voidTile);
    rowFiles.push_back(voidTile);
    rowFiles.push_back(voidTile);
    rowFiles.push_back(voidTile);
    
    rowFiles.push_back(purpleTile);
    
    gameBoard = new Board(rowFiles, -1.7, 1, 0.13, 0.13, 13, 2, 0);
    
    frog = new AnimatedRect(frogN.c_str(), 1, 3, 16, true, false, -0.02, gameBoard->getRowY(12), 0.16, 0.16);
    currFrogRow = 12;
    
    frogAlive = true;
    
    setRate(1);
    start();
}

void Game::action()
{
    float yPos = frog->getY();
    if (up)
    {
        if (frog->getY() != gameBoard->getRowY(0) && frog->getY() != gameBoard->getRowY(currFrogRow))
        {
            yPos -= 0.01;
            frog->setY(gameBoard->getRowY(yPos));
        }
        else
        {
            //up = false;
        }
    }
    else if (down)
    {
        if (frog->getY() != gameBoard->getRowY(12) && frog->getY() != gameBoard->getRowY(currFrogRow))
        {
            yPos += 0.01;
            frog->setY(gameBoard->getRowY(currFrogRow));
        }
        else
        {
            down = false;
        }
    }
    else if (left)
    {
        left = false;
    }
    else if (right)
    {
        right = false;
    }
    //frog->reset();
}

void Game::draw() const
{
    gameBoard->draw();
    frog -> draw(0.2);
//    frogLives -> draw(0.0);
    
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    if (key == 'w')
    {
        std::string temp = assetDirectory + "Frog_NS.png";
        frog = new AnimatedRect(temp.c_str(), 1, 3, 50, true, false, frog->getX(), frog->getY(), frog->getW(), frog->getH());
        
        if (currFrogRow < 0)
        {
            currFrogRow--;
            frog->playOnce();
            up = true;
        }
    }
    else if (key == 's')
    {
        currFrogRow++;
        if (currFrogRow > 12)
        {
            currFrogRow++;
            frog->playOnce();
            down = true;
        }
    }
    else if (key == 'a')
    {
        std::string temp = assetDirectory + "Frog_WE.png";
        frog = new AnimatedRect(temp.c_str(), 1, 3, 200, true, false, frog->getX(), frog->getY(), frog->getW(), frog->getH());
        frog->flip();
        frog->playOnce();
        left = true;
    }
    else if (key == 'd')
    {
        right = true;
    }
}

Game::~Game(){
    stop();
    //delete objects
    
    delete gameBoard;
    delete frog;
}
