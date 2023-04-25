//
// Created by Gonghan Xu on 4/25/23.
//

#include "HappyInductors.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;
extern int blank_sprite[];

int HappyInductors_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,Y,Y,Y,Y,Y,Y,Y,_,_,
        _,_,Y,Y,_,_,_,_,_,_,_,
        _,_,R,R,R,R,R,R,R,_,_,
        _,_,_,_,_,_,_,R,R,_,_,
        _,_,Y,Y,Y,Y,Y,Y,Y,_,_,
        _,_,Y,Y,_,_,_,_,_,_,_,
        _,_,R,R,R,R,R,R,R,_,_,
        _,_,Y,Y,Y,Y,Y,Y,Y,_,_
};

void HappyInductors::erase() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, blank_sprite);
}

void HappyInductors::draw() {
    uLCD.BLIT(getXPos(), getYPos(),
              SPRITE_WIDTH, SPRITE_HEIGHT, HappyInductors_sprite);
}

void HappyInductors::move() {
    erase();
    increaseX(vx);
    increaseY(vy);
    draw();
}

int* HappyInductors::getSprite() {return HappyInductors_sprite;}

void HappyInductors::increaseX(int delta) {
    if (getXPos() + delta <= WALL_TLX) {
        setXPos(WALL_TLX + 1);
        vx = -(2 * vx % 3 + 1);
    } else if (getXPos() + delta + SPRITE_WIDTH - 1 >= WALL_BRX) {
        setXPos(WALL_BRX - (SPRITE_WIDTH - 1) - 1);
        vx = -(2 * vx % 3 + 1);
    } else {
        setXPos(getXPos() + delta);
    }
}

void HappyInductors::increaseY(int delta) {
    if (getYPos() + delta <= WALL_TLY) {
        setYPos(WALL_TLY + 1);
        vy = -(2 * vy % 3 + 1);
    } else if (getYPos() + delta + SPRITE_HEIGHT - 1 >= WALL_BRY) {
        setYPos(WALL_BRY - (SPRITE_HEIGHT - 1) - 1);
        vy = -(2 * vy % 3 + 1);
    } else {
        setYPos(getYPos() + delta);
    }
}
