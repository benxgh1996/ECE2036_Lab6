#include <cstdlib>
#include <vector>

#include "ScreenObject.h"
#include "AIBot.h"
#include "BatteryChargers.h"
#include "ServerFarmers.h"
#include "CaringCapacitors.h"
#include "RebelResistors.h"
#include "AIPoisonPill.h"
#include "HappyInductors.h"

#include "mbed.h"
#include "TMP36.h"
#include "uLCD_4DGL.h"
#include "PinDetect.h"
#include "speaker.h"
#include "joystick.h"
#include "gameJingle.h"


using namespace std;

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

uLCD_4DGL uLCD(p9, p10, p11); // create a global lcd object
TMP36 myTMP36(p17);

DigitalIn pb1(p21);
DigitalIn pb2(p22);
DigitalIn pb3(p23);

Speaker mySpeaker(p25);

Nav_Switch myNav(p16, p13, p14, p12, p15); //pin order on Sparkfun breakout
bool GETOUT = false;

int main() {

    //Please have a startup and ending jingle. I provided
    //a wimpy one note startup jingle
    GameJingle Jingle;
    Jingle.playIntro();

    uLCD.cls();
    //You can use this following command if you want landscape setup
    //uLCD.display_control(LANDSCAPE);

    //This time(0) should return the number of seconds that the mbed
    //has been powered on.
    srand(time(0));

    //if you are not getting random numbers after each reset try debugging with
    //uLCD.printf("Time(0)=%i\n",time(0));

    //setup push buttons
    pb1.mode(PullUp);
    pb2.mode(PullUp);
    pb3.mode(PullUp);
    wait(0.3);  //This can make the system more stable as it sets up the pins

    //If you don't have this your system will be really slow.
    //This sets the communication rate between the uLCD and the
    //mbed system.
    uLCD.baudrate(300000);
    wait(0.3);  //Always good to wait as mbed system set itself up!


    //let's draw a border around the screen in a festive GREEN
    //NOTE: In your program make sure the AIBot is prevented from
    //going outside the bounds set by this boarder!!
    uLCD.cls(); //This clears the screen
    // uLCD.rectangle(WALL_TLX, WALL_TLY, WALL_BRX, WALL_BRY, GREEN);

    vector<ScreenObject *> screenObjectPtrs;
    screenObjectPtrs.push_back(new AIBot());
    screenObjectPtrs.push_back(new BatteryChargers());
    screenObjectPtrs.push_back(new ServerFarmers());
    screenObjectPtrs.push_back(new CaringCapacitors());
    screenObjectPtrs.push_back(new RebelResistors());
    screenObjectPtrs.push_back(new AIPoisonPill());
    screenObjectPtrs.push_back(new HappyInductors());


    int points = 0;

    //NOTE: The locate function coordinates are not in units of pixels
    //but in units of the size of the character printed.
    uLCD.text_width(1); //You can change the size of your text if you want
    uLCD.text_height(1); //using these member functions for uLCD
    uLCD.locate(1,14); //units are not pixels but character sizes
    uLCD.printf("%s: %d           ", "Score:", points);
    //This will print out the points at bottom of screen

    screenObjectPtrs[0]->draw();
    bool gameover = false;
    while(!GETOUT) {
        if (!pb1) {
            while (pb2) {
                wait(0.1);
            }
        }

        uLCD.rectangle(WALL_TLX, WALL_TLY, WALL_BRX, WALL_BRY, GREEN);
        // Move screen objects.
        for (int i = 0; i < screenObjectPtrs.size(); i++) {
            if (i == 0) {
                screenObjectPtrs[i]->move();
            } else {
                screenObjectPtrs[i]->erase();
                screenObjectPtrs[i]->move();
                screenObjectPtrs[i]->draw();
            }
        }

        // Check overlap.
        for (int i = 1; i < screenObjectPtrs.size(); i++) {
            if (screenObjectPtrs[0]->overlap(screenObjectPtrs[i])) {
                mySpeaker.PlayNote(1318.51, 0.05, 0.01); // E6
                wait(0.05);
                mySpeaker.PlayNote(987.77, 0.05, 0.01); // B5
                wait(0.05);
                mySpeaker.PlayNote(1318.51, 0.05, 0.01); // E6
                wait(0.05);
                mySpeaker.PlayNote(987.77, 0.05, 0.01); // B5
                wait(0.05);

                screenObjectPtrs[i]->erase();

                screenObjectPtrs[i]->setXPos(ScreenObject::randXPos());
                screenObjectPtrs[i]->setYPos(ScreenObject::randYPos());
                screenObjectPtrs[i]->draw();

                screenObjectPtrs[0]->draw();

                points += screenObjectPtrs[i]->getPoints();

                //now update the score. Looks like a cut-and-paste job...
                //make make it a function!!
                uLCD.locate(1, 14);
                uLCD.text_width(1);
                uLCD.text_height(1);
                uLCD.printf("%s %d           ", "Score:", points);

                uLCD.locate(1, 15);
                uLCD.printf("%s %d          ", "Change:",
                            screenObjectPtrs[i]->getPoints());

                if (points >= 50) {
                    uLCD.cls();
                    uLCD.printf("\n\n\n\n\n     You Won!\n\n"
                                "     AI Robot\n\n"
                                "   FULLY CHARGED!!");
                    wait(8);
                    gameover = true;
                    break;
                } else if (points < 0) {
                    uLCD.cls();
                    uLCD.printf("\n\n\n\n\n     You Lost!\n\n"
                                "     AI Robot\n\n"
                                "   OUT OF POWER!!");
                    wait(8);
                    gameover = true;
                    break;
                }
            }
        }
        if (gameover) break;
//        wait(0.1);
    }

    for (int i = 0; i < screenObjectPtrs.size(); i++) {
        delete screenObjectPtrs[i];
    }

    // Print a final farewell to indicate win or loss.
    uLCD.cls();
    uLCD.printf("\n\n\n\n\n      AI Robot\n\n"
                "        Will\n\n"
                "     Come Back!!");
    Jingle.playExit();
}
