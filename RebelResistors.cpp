//
// Created by Gonghan Xu
//

#include "RebelResistors.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;
extern int blank_sprite[];

int RebelResistors_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,Y,_,_,_,_,_,_,
        _,_,_,_,R,_,_,_,_,_,_,
        _,_,Y,R,Y,R,Y,R,_,_,_,
        _,_,_,_,_,R,R,_,_,_,_,
        _,_,_,_,R,Y,_,_,_,_,_,
        _,_,R,Y,R,R,Y,R,_,_,_,
        _,_,_,_,_,Y,_,_,_,_,_,
        _,_,_,_,_,R,_,_,_,_,_
};

void RebelResistors::erase() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, blank_sprite);
}

void RebelResistors::draw() {
    uLCD.BLIT(getXPos(), getYPos(),
              SPRITE_WIDTH, SPRITE_HEIGHT, RebelResistors_sprite);
}

void RebelResistors::move() {
    erase();
    randMoveX();
    randMoveY();
    draw();
}

int* RebelResistors::getSprite() {return RebelResistors_sprite;}
