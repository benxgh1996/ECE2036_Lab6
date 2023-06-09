//
// Created by Gonghan Xu
//

#include "ServerFarmers.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;
extern int blank_sprite[];

int ServerFarmers_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,R,R,R,_,_,_,_,
        _,_,R,R,R,R,R,R,R,_,_,
        _,_,_,R,Y,R,Y,R,_,_,_,
        _,_,_,R,R,R,R,R,_,_,_,
        _,R,R,R,R,R,R,R,R,R,_,
        _,_,_,R,R,R,R,R,_,_,_,
        _,_,_,R,R,_,R,R,_,_,_,
        _,_,R,R,_,_,_,R,R,_,_
};

void ServerFarmers::erase() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, blank_sprite);
}

void ServerFarmers::draw() {
    uLCD.BLIT(getXPos(), getYPos(),
              SPRITE_WIDTH, SPRITE_HEIGHT, ServerFarmers_sprite);
}

void ServerFarmers::move() {
    erase();
    randMoveX();
    randMoveY();
    draw();
}

int* ServerFarmers::getSprite() {return ServerFarmers_sprite;}
