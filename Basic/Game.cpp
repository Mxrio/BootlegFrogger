#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"

Game::Game(){

// Some cross-platform compatimility stuff

    const char* frogFileName;
    const char* purpleTileFileName;
    const char* carFileName;
    
    
    // In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
    // In other environments the image files are in the same folder as the project
    
    #if defined WIN32
    frogFileName = "../frog_NS.png" ;
    purpleTileFileName = "../grass_tile.png";
    carFileName = "../car_white.png";
    #else
    frogFileName = "frog_NS.png";
    purpleTileFileName = "grass_tile.png";
    carFileName = "car_white.png";
    #endif
	// In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
	// In other environments the image files are in the same folder as the project


    frog = new AnimatedRect(frogFileName, 1 , 3, 100, false, false, 0, 0, 0, 0.5);
    car = new TexRect(carFileName, -0.4, -0.25, 0.1, 0.1);
    purpleTile = new TexRect(purpleTileFileName, -1.1 , -0.4, 1.0, 0.5);
    frogLives = new TexRect(frogFileName, 0.5, 0.5, 0.1, 0.1);
    
    frogAlive = true;
    frog -> playLoop();
    
    setRate(1);
    start();
}

void Game::action()
{
    
}

void Game::draw() const
{
	purpleTile -> draw(0.0);
	car -> draw(0.0);
	frog -> draw(-0.5);
	frogLives -> draw(0.0);
    
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    
}

Game::~Game(){
    stop();
    //delete objects
    //delete mushroom;
}
