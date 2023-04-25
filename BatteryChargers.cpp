//
// Created by Gonghan Xu on 4/24/23.
//

#include "BatteryChargers.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;

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



