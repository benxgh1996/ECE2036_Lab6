#ifndef AIBOT_H
#define AIBOT_H

#include "ScreenObject.h"
#include "helper.h"

const int AIBot_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,X,X,X,R,R,_,_,
        _,X,X,X,X,X,X,X,R,X,_,
        X,X,R,X,X,Y,Y,X,X,X,X,
        X,X,X,R,X,Y,Y,X,X,X,_,
        X,R,X,X,X,X,X,X,R,R,R,
        _,_,_,R,X,_,R,R,_,_,_,
        _,_,R,R,_,_,_,R,R,_,_,
        R,R,_,_,_,R,_,_,_,R,R
};

class AIBot: public ScreenObject {
public:
    AIBot(): ScreenObject(100, 100) {}
    AIBot(int x, int y): ScreenObject(x, y) {}

    void draw() override;
    void move() override;
    void erase() override;

    const int* getSprite() override {return AIBot_sprite;}
};

#endif