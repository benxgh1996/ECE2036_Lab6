//
// Created by Gonghan Xu
//

#ifndef SERVERFARMERS_H
#define SERVERFARMERS_H

#include "ScreenObject.h"

class ServerFarmers: public ScreenObject {
public:
    ServerFarmers(): ScreenObject() {}
    ServerFarmers(int x, int y): ScreenObject(x, y) {}

    virtual void draw();
    virtual void move();
    virtual void erase();

    virtual int* getSprite();
    virtual int getPoints() {return 10;}

    virtual int getDeltaX() {return 10;}
    virtual int getDeltaY() {return 10;}
};


#endif //SERVERFARMERS_H
