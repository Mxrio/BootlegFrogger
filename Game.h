#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Row.h"
#include "Board.h"

class Game: public AppComponent, private Timer{
//    TexRect* frogLives;
//    TexRect* car;
    
    std::string assetDirectory;
    AnimatedRect* frog;
    int currFrogRow;
    
    Board* gameBoard;
    
    bool up;
    bool down;
    bool left;
    bool right;
    
    bool hit;
    bool frogAlive;
public:
    
    Game();
    
    void draw() const ;
    void handleKeyDown(unsigned char, float, float);
    
    void action();

    ~Game();

};

#endif 
