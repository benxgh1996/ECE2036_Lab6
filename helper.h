//
// Created by Gonghan Xu on 4/24/23.
//

#ifndef LAB6_HELPER_H
#define LAB6_HELPER_H

//I am okay with keeping these
//as define statements for the colors
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define LGREY 0xBFBFBF
#define DGREY 0x5F5F5F
#define YELLOW 0xFFFF00
#define BROWN 0x964B00

//Put this as C++ constant inside
//your class that contains the AIBot!!
#define SPRITE_HEIGHT 8
#define SPRITE_WIDTH 11

#define _ BLACK
#define X LGREY
#define R DGREY
#define Y RED

#define WALL_TLX 0
#define WALL_TLY 0
#define WALL_BRX 120
#define WALL_BRY 110

int blank_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_,
        _,_,_,_,_,_,_,_,_,_,_
};

#endif //LAB6_HELPER_H
