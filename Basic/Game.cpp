#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdlib>

#include "Game.h"

Game::Game()
{
    srand (static_cast <unsigned> (time(0)));
    assetDirectory = "/Users/mxrio/Desktop/SHIT/school/semester6/CSE165/Frogger/FroggerAssets/";
    
    std::string purpleTile = assetDirectory + "grass_tile.png";
    std::string voidTile = assetDirectory + "void_tile.png";
    std::string riverTile = assetDirectory + "river_tile.png";
    //std::string grassTile = assetDirectory + "grass_goal.png";
    
    std::string frogN = assetDirectory + "Frog_N.png";
    std::string frogWE = assetDirectory + "Frog_WE.png";
    std::string frogS = assetDirectory + "Frog_S.png";
    
    std::string whiteCar = assetDirectory + "car_white.png";
    std::string purpleCar = assetDirectory + "car_purple.png";
    std::string log = assetDirectory + "log.png";
    std::string truck = assetDirectory + "truck.png";
    std::string yellowCar = assetDirectory + "car_yellow.png";
    std::string raceCar = assetDirectory + "car_race.png";
    

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
    obstacleSpawner = new SpawnMachine();
    
    obstacleSpawner->AddSpawner(new SpawnRow(log, 1.7, gameBoard->getRowY(1), 0.42, 0.14, 20, 3));
    obstacleSpawner->AddSpawner(new SpawnRow(log, 1.7, gameBoard->getRowY(2), 0.42, 0.14, 40, 4));
    obstacleSpawner->AddSpawner(new SpawnRow(log, 1.7, gameBoard->getRowY(3), 0.42, 0.14, 25, 4));
    obstacleSpawner->AddSpawner(new SpawnRow(log, 1.7, gameBoard->getRowY(4), 0.42, 0.14, 15, 5));
    obstacleSpawner->AddSpawner(new SpawnRow(log, 1.7, gameBoard->getRowY(5), 0.42, 0.14, 30, 6));
    
    obstacleSpawner->AddSpawner(new SpawnRow(truck, -1.7, gameBoard->getRowY(7), 0.42, 0.14, 50, 5));
    obstacleSpawner->AddSpawner(new SpawnRow(yellowCar, 1.7, gameBoard->getRowY(8), 0.14, 0.14, 25, 7));
    obstacleSpawner->AddSpawner(new SpawnRow(raceCar, -1.7, gameBoard->getRowY(9), 0.14, 0.14, 15, 10));
    obstacleSpawner->AddSpawner(new SpawnRow(purpleCar, 1.7, gameBoard->getRowY(10), 0.14, 0.14, 35, 8));
    obstacleSpawner->AddSpawner(new SpawnRow(whiteCar, -1.7, gameBoard->getRowY(11), 0.14, 0.14, 25, 7));
    
    frog = new AnimatedRect(frogN.c_str(), 1, 3, 16, true, false, -0.02, gameBoard->getRowY(12), 0.16, 0.16);
    
    currFrogRow = 12;
    
    frogAlive = true;
    spawnerCount = 0;
    
    setRate(30);
    start();
}

void Game::action()
{
    float yPos = frog->getY();
    if (up)
    {
        if (frog->getY() < gameBoard->getRowY(0) && frog->getY() != gameBoard->getRowY(currFrogRow))
        {
            frog->setY(gameBoard->getRowY(currFrogRow));
            frog->reset();
            up = false;
        }
    }
    else if (down)
    {
        if (frog->getY() > gameBoard->getRowY(12) && frog->getY() != gameBoard->getRowY(currFrogRow))
        {
            frog->setY(gameBoard->getRowY(currFrogRow));
            frog->reset();
            down = false;
        }
    }
    else if (left)
    {
        if (frog->getX() > -1.7)
        {
            frog->setX(frog->getX() - 0.13);
            left = false;
            frog->reset();
        }
    }
    else if (right)
    {
        if (frog->getX() < 1.7)
        {
            frog->setX(frog->getX() + 0.13);
            right = false;
            frog->reset();
        }
    }
    //frog->reset();
}

void Game::draw() const
{
    gameBoard->draw();
    frog -> draw(0.1);
    obstacleSpawner->draw();
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    if (key == 'w')
    {
        std::string temp = assetDirectory + "Frog_N.png";
        frog = new AnimatedRect(temp.c_str(), 1, 3, 40, true, false, frog->getX(), frog->getY(), frog->getW(), frog->getH());
        
        if (currFrogRow > 0)
        {
            currFrogRow--;
            frog->playOnce();
            up = true;
        }
    }
    else if (key == 's')
    {
        std::string temp = assetDirectory + "Frog_S.png";
        frog = new AnimatedRect(temp.c_str(), 1, 3, 40, true, false, frog->getX(), frog->getY(), frog->getW(), frog->getH());
        
        if (currFrogRow < 12)
        {
            currFrogRow++;
            frog->playOnce();
            down = true;
        }
    }
    else if (key == 'a')
    {
        std::string temp = assetDirectory + "Frog_WE.png";
        frog = new AnimatedRect(temp.c_str(), 1, 3, 40, true, false, frog->getX(), frog->getY(), frog->getW(), frog->getH());
        frog->flip();
        frog->playOnce();
        left = true;
    }
    else if (key == 'd')
    {
        std::string temp = assetDirectory + "Frog_WE.png";
        frog = new AnimatedRect(temp.c_str(), 1, 3, 40, true, false, frog->getX(), frog->getY(), frog->getW(), frog->getH());
        frog->playOnce();
        right = true;
    }
}

Game::~Game(){
    stop();
    //delete objects
    
    delete gameBoard;
    delete frog;
    delete obstacleSpawner;
}
