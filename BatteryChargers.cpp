//
// Created by Gonghan Xu
//

#include "BatteryChargers.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;
extern int blank_sprite[];

int BatteryChargers_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,X,X,X,_,_,_,_,
        _,_,X,X,X,X,X,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,Y,Y,Y,X,X,_,_,
        _,_,X,X,X,X,X,X,X,_,_
};

void BatteryChargers::erase() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, blank_sprite);
}

void BatteryChargers::draw() {
    uLCD.BLIT(getXPos(), getYPos(),
              SPRITE_WIDTH, SPRITE_HEIGHT, BatteryChargers_sprite);
}

void BatteryChargers::move() {
    erase();
    randMoveX();
    randMoveY();
    draw();
}

int* BatteryChargers::getSprite() {return BatteryChargers_sprite;}
