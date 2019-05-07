#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"

Game::Game(){

	// Some cross-platform compatimility stuff

	//const char* shroomFileName;
    //const char* fireballFileName;

    
    setRate(1);
    start();
}

void Game::action()
{
    
}

void Game::draw() const
{
    
}

void Game::handleKeyDown(unsigned char key, float x, float y)
{
    
}

Game::~Game(){
    stop();
    //delete objects
    //delete mushroom;
}
