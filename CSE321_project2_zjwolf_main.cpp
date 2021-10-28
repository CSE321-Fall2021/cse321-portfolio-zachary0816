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

#include "PeripheralNames.h"
#include "mbed_thread.h"
#include "1802.h"
#include <cstdio>
#include <mbed.h>
#include <stdio.h>

// main() runs in its own thread in the OS

// hopefully by definind them as static before anything else, they should be
// globally accessible by all functions. Might need to move them to main, though
// that seems to not work with the button pressing functions. Consider revisions
//static int time_set = 0;

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
//Put any function prototypes here 

//Note: LCD boards require 5 volts. Using 3 volt may cause issues. 

// The following functions should be called when the relevant button triggers an interrupt

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
CSE321_LCD objName( 16, 2, LCD_5x10DOTS, PB_9, PB_8); //Either LCD_5x10DOTS or LCD_5x8DOTS
//Possible error in instructions SLA should be SCL 
//Check if I2C needs to be anabled 
//PB8 and PB9 are on I2C ports
//Pins shoudl be set automatically for interrupt? Api should handle it
//Double check I2C_1 and not 
int main() {
  // Initialize ports
  RCC->AHB2ENR |= 0x2;
  // port b enabled
  // ports for keypad are all inputs which need to be set to 00, therefore,
  // nothing must be done set anyways

  // Set up inputs for keypad (refrence )

  // time_set.reset; //time_set isn't being seen by main, resolve that

  // int time_remaining=0;
  // initilize a variable for set time
  // Initiliaze a variable for time remaining

  while (true) {
    // Insert interrupts here that trigger when button is pressed
    // Output to LCD
  }
}
