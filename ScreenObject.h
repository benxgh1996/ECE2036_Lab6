//
// Created by Gonghan Xu on 4/24/23.
//

#ifndef LAB6_SCREENOBJECT_H
#define LAB6_SCREENOBJECT_H

class ScreenObject {
public:
    static const int X_DELTA
    static const int Y_DELTA

    ScreenObject(): xpos(50), ypos(50) {copyX(); copyY();}
    inline void copyX(){ xOLDpos = xpos;}
    inline void copyY() {yOLDpos = ypos;}

    inline void increaseX() {xPos += X_DELTA;}
    inline void increaseY() {yPos += Y_DELTA;}
    inline void decreaseX() {xPos -= X_DELTA;}
    inline void decreaseY() {yPos -= Y_DELTA;}

    int getXPos() const {return xPos;}
    int getYPos() const {return yPos;}
    int getXOldPos() const {return xOldPos;}
    int getYOldPos() const {return yOldPos;}

    void setXPos(int x) {xPos = x;}
    void setYPos(int y) {yPos = y;}
    void setXOldPos(int x) {xOldPos = x;}
    void setYOldPos(int y) {yOldPos = y;}

    // Checking if the object is overlapping with the given coordinate.
    virtual bool overlap(int x, int y) = 0;
    virtual void draw(int x, int y) = 0;
    virtual void move() = 0;
    virtual void erase() = 0;

private:
    int xPos;
    int yPos;
    int xOldPos;
    int yOldPos;
};


#endif //LAB6_SCREENOBJECT_H
