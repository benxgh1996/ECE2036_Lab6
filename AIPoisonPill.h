//
// Created by Gonghan Xu
//

#ifndef AIPOISONPILL_H
#define AIPOISONPILL_H

#include "ScreenObject.h"

class AIPoisonPill: public ScreenObject {
public:
    AIPoisonPill(): ScreenObject(), vx(2), vy(2) {}
    AIPoisonPill(int x, int y): ScreenObject(x, y), vx(2), vy(2) {}

    virtual void draw();
    virtual void move();
    virtual void erase();

    virtual int* getSprite();
    virtual int getPoints() {return -10;}

    virtual int getDeltaX() {return 2;}
    virtual int getDeltaY() {return 2;}

    virtual void increaseX(int delta = DELTA_X);
    virtual void increaseY(int delta = DELTA_Y);

private:
    // Direction of the object.
    int vx;
    int vy;
};


#endif //AIPOISONPILL_H
