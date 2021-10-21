/*
author1: Zachary Wolf
author2: none
Modules/Subroutines used:
Corresponding assignment(s): CSE321 Project 2
Inputs: A, B and D from the keypad
Outputs: LCD display
Constraints:
Sources and/or refrences used:
*/

#include "mbed_thread.h"
#include <1802.h>
#include <cstdio> //check if this is supposed to maybe be cstdio.c or cstdio.h
#include <mbed.h>
#include <stdio.h>
//#include "1802.h" //make sure this header file is where it should be
//#include "1802.cp"
// instructions imply that 1802.h or 1802.cp should be included but not both,
// figure out which

// import 1802.cp?

// main() runs in its own thread in the OS

// hopefully by definind them as static before anything else, they should be
// globally accessible by all functions. Might need to move them to main, though
// that seems to not work with the button pressing functions. static int time_set
// = 0;

// Initilaize PB 5,6,8,9

// Set up interrupt from keypad
InterruptIn A(PB_5);
InterruptIn B(PB_6); // Input names are subject to change
InterruptIn C(PB_8);
InterruptIn D(PB_9);

// PB7 is not used because it is the on board LED

Timer time_set;
// initilize a variable for set time
// static int time_remaining = 0;
Timer time_remaining;
static bool started = false;
// This function determines wether or no the timer is started
// false is not started, true is started

// LCD boards use 5 volts

// The following functions should be called when the relevant button trigger an
// interrupt

void A_pressed() {
  // Add compensation for bounce?
  // if timer is not running, start timer
  if (started == false) {
    // start timer
    //time_remaining.start();
  } else {
    // do nothing
  }
}
void B_pressed() {
  // Add compensation for bounce?

  if (started == true) {
    // If timer is running, stop it
    //time_remaining.stop();

  } else {
    // If timer is not running, reset timer
    // time_remaining = time_set;
  }
}

void D_pressed() {
  // Add compensation for bounce?
  // Check if timer is currently running, if not, increment time by 5 seconds.
  // timer is based on system time
}

int main() {
  // Initialize ports
  RCC->AHB2ENR |= 0x2;
  // port b enabled
  // ports for keypad are all inputs which need to be set to 00, therefore,
  // nothing must be done set anyways

  // Set up inputs for keypad (refrence )

  // time_set.reset; //time_set isn't being seen by main

  // int time_remaining=0;
  // initilize a variable for set time
  // Initiliaze a variable for time remaining

  while (true) {
    // Insert interrupts here that trigger when button is pressed
    // Output to LCD
  }
}
