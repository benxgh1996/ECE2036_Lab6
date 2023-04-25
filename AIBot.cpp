#include "AIBot.h"
#include "uLCD_4DGL.h"
#include "helper.h"
#include "joystick.h"

extern uLCD_4DGL uLCD;
extern Nav_Switch myNav;
extern bool GETOUT;
extern int blank_sprite[];

int AIBot_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,X,X,X,R,R,_,_,
        _,X,X,X,X,X,X,X,R,X,_,
        X,X,R,X,X,Y,Y,X,X,X,X,
        X,X,X,R,X,Y,Y,X,X,X,_,
        X,R,X,X,X,X,X,X,R,R,R,
        _,_,_,R,X,_,R,R,_,_,_,
        _,_,R,R,_,_,_,R,R,_,_,
        R,R,_,_,_,R,_,_,_,R,R
};

void AIBot::erase() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, blank_sprite);
}

void AIBot::draw() {
    uLCD.BLIT(getXPos(), getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, AIBot_sprite);
}

void AIBot::move() {
    if (myNav.up()) {
        erase();
        increaseY();
        draw();
    } else if (myNav.down()) {
        erase();
        decreaseY();
        draw();
    } else if (myNav.left()) {
        erase();
        increaseX();
        draw();
    } else if (myNav.right()) {
        erase();
        decreaseX();
        draw();
    } else if (myNav.fire()) {
        GETOUT = true;
    }
}

int* AIBot::getSprite() {return AIBot_sprite;}
