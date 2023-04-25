#include <cstdlib>
#include <vector>
#include "ScreenObject.h"
#include "BatteryChargers.h"
#include "mbed.h"
#include "TMP36.h"
#include "uLCD_4DGL.h"
#include "PinDetect.h"
#include "speaker.h"
#include "joystick.h"
#include "gameJingle.h"
#include "AIBot.h"
#include "helper.h"

using namespace std;

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
    AIBot buzz1;
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

    vector<ScreenObject *> screenObjectPtrs;
    screenObjectPtrs[0] = new AIBot();
    screenObjectPtrs[1] = new BatteryChargers();
    
    int points = 0;

    //NOTE: The locate function coordinates are not in units of pixels
    //but in units of the size of the character printed.
    uLCD.text_width(1); //You can change the size of your text if you want
    uLCD.text_height(1); //using these member functions for uLCD
    uLCD.locate(1,14); //units are not pixels but character sizes
    uLCD.printf("%i",points);
    //This will print out the points at bottom of screen

    int color = WHITE;
    
    while(!GETOUT) {
        for (ScreenObject * screenObjectPtr: screenObjectPtrs) {
            screenObjectPtr->erase();
            screenObjectPtr->move();
            screenObjectPtr->draw();
        }

        for (int i = 1; i < screenObjectPtrs.size(); i++) {
            if (screenObjectPtrs[0]->overlap(screenObjectPtrs[i])) {
                mySpeaker.PlayNote(450.0, 0.1, 0.2);
                screenObjectPtrs[i]->erase();

                screenObjectPtrs[i]->setXPos(ScreenObject::randXPos());
                screenObjectPtrs[i]->setYPos(ScreenObject::randYPos());
                screenObjectPtrs[i]->draw();

                points += screenObjectPtrs[i]->getPoints();

                //now update the score. Looks like a cut-and-paste job...
                //make make it a function!!
                uLCD.locate(1, 14);
                uLCD.text_width(1);
                uLCD.text_height(1);
                uLCD.printf("%i", points);
            }
        }
    }

    for (ScreenObject * screenObjectPtr: screenObjectPtrs) {
        delete screenObjectPtr;
    }

    //Print a final farewell to indicate win or loss.
    //Also have a nice closing jingle for
    //your game!
    uLCD.cls();
    uLCD.printf("\n\n\n\n\n       Happy \n   Summer \n      Break!!");
}
