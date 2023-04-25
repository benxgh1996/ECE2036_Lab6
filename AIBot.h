#ifndef AIBOT_H
#define AIBOT_H

#include "ScreenObject.h"

class AIBot: public ScreenObject {
public:
    AIBot(): ScreenObject(100, 100) {}
    AIBot(int x, int y): ScreenObject(x, y) {}

    virtual void draw();
    virtual void move();
    virtual void erase();

    virtual int* getSprite();
};

#endif
