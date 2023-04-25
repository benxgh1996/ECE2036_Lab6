//
// Created by Gonghan Xu on 4/25/23.
//

#ifndef LAB6_AIPOISONPILL_H
#define LAB6_AIPOISONPILL_H

#include "ScreenObject.h"

class AIPoisonPill: public ScreenObject {
public:
    AIPoisonPill(): ScreenObject(), vx(10), vy(10) {}
    AIPoisonPill(int x, int y): ScreenObject(x, y), vx(10), vy(10) {}

    virtual void draw();
    virtual void move();
    virtual void erase();

    virtual int* getSprite();
    virtual int getPoints() {return -10;}

    virtual int getDeltaX() {return 10;}
    virtual int getDeltaY() {return 10;}

    virtual void increaseX(int delta = DELTA_X);
    virtual void increaseY(int delta = DELTA_Y);

private:
    // Direction of the object.
    int vx;
    int vy;
};


#endif //LAB6_AIPOISONPILL_H
