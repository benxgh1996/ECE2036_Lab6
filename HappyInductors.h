//
// Created by Gonghan Xu
//

#ifndef HAPPYINDUCTORS_H
#define HAPPYINDUCTORS_H

#include "ScreenObject.h"

class HappyInductors: public ScreenObject {
public:
    HappyInductors(): ScreenObject(), vx(3), vy(3) {}
    HappyInductors(int x, int y): ScreenObject(x, y), vx(3), vy(3) {}

    virtual void draw();
    virtual void move();
    virtual void erase();

    virtual int* getSprite();
    virtual int getPoints() {return 3;}

    virtual int getDeltaX() {return 2;}
    virtual int getDeltaY() {return 2;}

    virtual void increaseX(int delta = DELTA_X);
    virtual void increaseY(int delta = DELTA_Y);

private:
    int vx;
    int vy;
};


#endif //HAPPYINDUCTORS_H
