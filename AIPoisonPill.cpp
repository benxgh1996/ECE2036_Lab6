//
// Created by Gonghan Xu
//

#include "AIPoisonPill.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;
extern int blank_sprite[];

int AIPoisonPill_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,Y,Y,Y,Y,Y,_,_,_,
        _,Y,Y,Y,Y,Y,Y,Y,Y,Y,_,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        _,Y,Y,Y,Y,Y,Y,Y,Y,Y,_,
        _,_,_,Y,Y,Y,Y,Y,_,_,_
};

void AIPoisonPill::erase() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, blank_sprite);
}

void AIPoisonPill::draw() {
    uLCD.BLIT(getXPos(), getYPos(),
              SPRITE_WIDTH, SPRITE_HEIGHT, AIPoisonPill_sprite);
}

void AIPoisonPill::move() {
    erase();
    increaseX(vx);
    increaseY(vy);
    draw();
}

int* AIPoisonPill::getSprite() {return AIPoisonPill_sprite;}

void AIPoisonPill::increaseX(int delta) {
    if (getXPos() + delta <= WALL_TLX) {
        setXPos(WALL_TLX + 1);
        vx = -vx;
    } else if (getXPos() + delta + SPRITE_WIDTH - 1 >= WALL_BRX) {
        setXPos(WALL_BRX - (SPRITE_WIDTH - 1) - 1);
        vx = -vx;
    } else {
        setXPos(getXPos() + delta);
    }
}

void AIPoisonPill::increaseY(int delta) {
    if (getYPos() + delta <= WALL_TLY) {
        setYPos(WALL_TLY + 1);
        vy = -vy;
    } else if (getYPos() + delta + SPRITE_HEIGHT - 1 >= WALL_BRY) {
        setYPos(WALL_BRY - (SPRITE_HEIGHT - 1) - 1);
        vy = -vy;
    } else {
        setYPos(getYPos() + delta);
    }
}