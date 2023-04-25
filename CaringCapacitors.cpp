//
// Created by Gonghan Xu
//

#include "CaringCapacitors.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;
extern int blank_sprite[];

int CaringCapacitors_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,R,R,R,R,R,R,R,R,R,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,R,R,R,R,R,R,R,R,R,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_
};

void CaringCapacitors::erase() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, blank_sprite);
}

void CaringCapacitors::draw() {
    uLCD.BLIT(getXPos(), getYPos(),
              SPRITE_WIDTH, SPRITE_HEIGHT, CaringCapacitors_sprite);
}

void CaringCapacitors::move() {
    erase();
    randMoveX();
    randMoveY();
    draw();
}

int* CaringCapacitors::getSprite() {return CaringCapacitors_sprite;}

