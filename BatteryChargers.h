//
// Created by Gonghan Xu
//

#ifndef BATTERYCHARGERS_H
#define BATTERYCHARGERS_H

#include "ScreenObject.h"

class BatteryChargers: public ScreenObject {
public:
    BatteryChargers(): ScreenObject() {}
    BatteryChargers(int x, int y): ScreenObject(x, y) {}

    virtual void draw();
    virtual void move();
    virtual void erase();

    virtual int* getSprite();
    virtual int getPoints() {return 5;}
};


#endif //BATTERYCHARGERS_H
