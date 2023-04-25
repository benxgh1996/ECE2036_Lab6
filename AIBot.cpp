#include "AIBot.h"
#include "uLCD_4DGL.h"
#include "helper.h"

extern uLCD_4DGL uLCD;
extern Nav_Switch myNav;
extern bool GETOUT;

void AIBot::erase() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, blank_sprite);
}

void AIBot::draw() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, AIBot_sprite);
}

void AIBot::move() {
    if (myNav.up()) increaseY();
    if (myNav.down()) decreaseY();
    if (myNav.left()) increaseX();
    if (myNav.right()) decreaseX();
    if (myNav.fire())  {GETOUT = true;}
}
