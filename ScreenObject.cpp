//
// Created by Gonghan Xu on 4/24/23.
//

#include "ScreenObject.h"
#include "helper.h"
#include <cstdlib>

using namespace std;

const int ScreenObject::DELTA_X = 5;
const int ScreenObject::DELTA_Y = 5;

int ScreenObject::randXPos() {
    return rand() % (WALL_BRX - 2 - SPRITE_WIDTH) + 2;
}

int ScreenObject::randYPos() {
    return rand() % (WALL_BRY - 2 - SPRITE_HEIGHT) + 2;
}

void ScreenObject::increaseX(int delta) {
    if (xPos + delta <= WALL_TLX) {
        xPos = WALL_TLX + 1;
    } else if (xPos + delta + SPRITE_WIDTH - 1 >= WALL_BRX) {
        xPos = WALL_BRX - (SPRITE_WIDTH - 1) - 1;
    } else {
        xPos += delta;
    }
}

void ScreenObject::increaseY(int delta) {
    if (yPos + delta <= WALL_TLY) {
        yPos = WALL_TLY + 1;
    } else if (yPos + delta + SPRITE_HEIGHT - 1 >= WALL_BRY) {
        yPos = WALL_BRY - (SPRITE_HEIGHT - 1) - 1;
    } else {
        yPos += delta;
    }
}

void ScreenObject::decreaseX(int delta) {
    increaseX(-delta);
}

void ScreenObject::decreaseY(int delta) {
    increaseY(-delta);
}

void ScreenObject::randMoveX() {
    int randNum = rand() % 2;
    if (randNum == 0) {
        increaseX(DELTA_X);
    } else {
        increaseX(-DELTA_X);
    }
}

void ScreenObject::randMoveY() {
    int randNum = rand() % 2;
    if (randNum == 0) {
        increaseY(DELTA_Y);
    } else {
        increaseY(-DELTA_Y);
    }
}

bool ScreenObject::overlap(ScreenObject* other) {
    for (int i = 0; i < SPRITE_HEIGHT; i++) {
        for (int j = 0; j < SPRITE_WIDTH; j++) {
            if (getSprite()[i * SPRITE_WIDTH + j] != _
                && (i - other->getYPos() + getYPos()) >= 0
                && (i - other->getYPos() + getYPos()) < SPRITE_HEIGHT
                && (j - other->getXPos() + getXPos()) >= 0
                && (j - other->getXPos() + getXPos()) < SPRITE_WIDTH
                && other->getSprite()
                   [(i - other->getYPos() + getYPos()) * SPRITE_WIDTH
                    + (j - other->getXPos() + getXPos())] != _) {

                return true;
            }
        }
    }
    return false;
}
