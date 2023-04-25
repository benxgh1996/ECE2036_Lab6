//
// Created by Gonghan Xu
//

#ifndef CARINGCAPACITORS_H
#define CARINGCAPACITORS_H


class CaringCapacitors: public ScreenObject {
public:
    CaringCapacitors(): ScreenObject() {}
    CaringCapacitors(int x, int y): ScreenObject(x, y) {}

    virtual void draw();
    virtual void move();
    virtual void erase();

    virtual int* getSprite();
    virtual int getPoints() {return 2;}

    virtual int getDeltaX() {return 2;}
    virtual int getDeltaY() {return 2;}
};


#endif //CARINGCAPACITORS_H
