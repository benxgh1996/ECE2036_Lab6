//
// Created by Gonghan Xu on 4/24/23.
//

#ifndef LAB6_BATTERYCHARGERS_H
#define LAB6_BATTERYCHARGERS_H

#include "ScreenObject.h"
#include "helper.h"

const int BatteryChargers_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,X,X,X,_,_,_,_,
        _,_,X,X,X,X,X,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,X,X,X,X,X,_,_
};

class BatteryChargers: public ScreenObject {
public:
    BatteryChargers(): ScreenObject() {}
    BatteryChargers(int x, int y): ScreenObject(x, y) {}

    void draw() override;
    void move() override;
    void erase() override;

    const int* getSprite() override {return BatteryChargers_sprite;}
    int getPoints() override {return 1;}
};


#endif //LAB6_BATTERYCHARGERS_H
