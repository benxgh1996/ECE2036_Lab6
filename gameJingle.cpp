//
// Created by Gonghan Xu.
//

#include "gameJingle.h"
#include "speaker.h"

extern Speaker mySpeaker;

void GameJingle::playIntro() {
    mySpeaker.PlayNote(523.25, 0.2, 0.5); // C5
    wait(0.2);

    mySpeaker.PlayNote(587.33, 0.2, 0.5); // D5
    wait(0.2);

    mySpeaker.PlayNote(659.25, 0.2, 0.5); // E5
    wait(0.2);

    mySpeaker.PlayNote(783.99, 0.4, 0.5); // G5
    wait(0.4);

    mySpeaker.PlayNote(783.99, 0.2, 0.5); // G5
    wait(0.2);

    mySpeaker.PlayNote(659.25, 0.2, 0.5); // E5
    wait(0.2);

    mySpeaker.PlayNote(587.33, 0.2, 0.5); // D5
    wait(0.2);

    mySpeaker.PlayNote(523.25, 0.4, 0.5); // C5
    wait(0.4);
}

void GameJingle::playExit() {
    mySpeaker.PlayNote(783.99, 0.2, 0.5); // G5
    wait(0.2);

    mySpeaker.PlayNote(659.25, 0.2, 0.5); // E5
    wait(0.2);

    mySpeaker.PlayNote(587.33, 0.2, 0.5); // D5
    wait(0.2);

    mySpeaker.PlayNote(523.25, 0.4, 0.5); // C5
    wait(0.4);

    mySpeaker.PlayNote(493.88, 0.2, 0.5); // B4
    wait(0.2);

    mySpeaker.PlayNote(440.00, 0.2, 0.5); // A4
    wait(0.2);

    mySpeaker.PlayNote(392.00, 0.2, 0.5); // G4
    wait(0.2);

    mySpeaker.PlayNote(349.23, 0.4, 0.5); // F4
    wait(0.4);
}