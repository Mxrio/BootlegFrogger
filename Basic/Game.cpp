#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"

Game::Game()
{
    
    std::string assetDirectory = "/Users/mxrio/Desktop/SHIT/school/semester6/CSE165/Frogger/FroggerAssets/";
    
    std::string purpleTile = assetDirectory + "grass_tile.png";
    std::string voidTile = assetDirectory + "void_tile.png";
    std::string riverTile = assetDirectory + "river_tile.png";
    std::string grassBackrow = "";
    std::string grassMidRow = "";
    std::string grassFrontRow = "";

//    frog = new AnimatedRect(frogFileName, 1 , 3, 100, false, false, 0, 0, 0, 0.5);
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
    
    
    frogAlive = true;
    
    setRate(1);
    start();
}

void Game::action()
{
    
}

void Game::draw() const
{
    gameBoard->draw();
    
//    frog -> draw(-0.5);
//    frogLives -> draw(0.0);
    
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    
}

Game::~Game(){
    stop();
    //delete objects
    
    delete gameBoard;
}
