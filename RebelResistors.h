//
// Created by Gonghan Xu
//

#ifndef REBELRESISTORS_H
#define REBELRESISTORS_H

#include "ScreenObject.h"

class RebelResistors: public ScreenObject {
public:
    RebelResistors(): ScreenObject() {}
    RebelResistors(int x, int y): ScreenObject(x, y) {}

    virtual void draw();
    virtual void move();
    virtual void erase();

    virtual int* getSprite();
    virtual int getPoints() {return 1;}

    virtual int getDeltaX() {return 1;}
    virtual int getDeltaY() {return 1;}
};


#endif //REBELRESISTORS_H
