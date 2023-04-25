//
// Created by Gonghan Xu
//

#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

class ScreenObject {
public:
    static const int DELTA_X;
    static const int DELTA_Y;

    static int randXPos();
    static int randYPos();

    // Constructors
    ScreenObject(): xPos(30), yPos(30) {}
    ScreenObject(int x, int y): xPos(x), yPos(y) {}

    void increaseX(int delta=DELTA_X);
    void increaseY(int delta=DELTA_Y);
    void decreaseX(int delta=DELTA_X);
    void decreaseY(int delta=DELTA_Y);

    int getXPos() const {return xPos;}
    int getYPos() const {return yPos;}

    void setXPos(int x) {xPos = x;}
    void setYPos(int y) {yPos = y;}

    bool overlap(ScreenObject* other);

    void randMoveX();
    void randMoveY();

    virtual void draw() = 0;
    virtual void move() = 0;
    virtual void erase() = 0;
    virtual int* getSprite() = 0;

    virtual int getPoints() {return 0;}
    virtual ~ScreenObject() {};

    virtual int getDeltaX() {return DELTA_X;}
    virtual int getDeltaY() {return DELTA_Y;}

private:
    int xPos;
    int yPos;
};


#endif //SCREENOBJECT_H
