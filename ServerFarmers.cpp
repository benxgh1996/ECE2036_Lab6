//
// Created by Gonghan Xu
//

#include "ServerFarmers.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;
extern int blank_sprite[];

int ServerFarmers_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,X,X,X,_,_,_,_,
        _,_,X,X,X,X,X,X,X,_,_,
        _,_,_,X,Y,X,Y,X,_,_,_,
        _,_,_,X,X,Y,X,X,_,_,_,
        _,X,X,X,X,X,X,X,X,X,_,
        _,_,_,X,X,X,X,X,_,_,_,
        _,_,_,X,X,_,X,X,_,_,_,
        _,_,X,X,_,_,_,X,X,_,_
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
