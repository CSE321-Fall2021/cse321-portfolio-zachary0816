/*
author1: Zachary Wolf
author2: none
Modules/Subroutines used:
Corresponding assignment(s): CSE321 Project 2
Inputs: 4 x 4 Matrix Array 16 key membrane switch keypad
Outputs: LCD display
Constraints:
Sources and/or refrences used:
  JHD1804Y_YG( Black on Yellow) 1.1.ppt [兼容模式]
  https://os.mbed.com/platforms/NUCLEO-L4R5ZI/
  STM32 Nucleo-144 boards (MB1312) - User manual


*/
//Warning: 1802.h must be included outside in the main folder of the program.
//If it's in the same subfolder as main, it will not be found. 
#include "PeripheralNames.h"
#include "mbed_power_mgmt.h"
#include "mbed_thread.h"
#include "1802.h"
#include <cstdio>
#include "mbed.h"
#include <stdio.h>
//add import for printf statements? 
void A_pressed(void);
void B_pressed(void);
void D_pressed(void);


// main() runs in its own thread in the OS

// Initilaize PB 3,4,5,12

// Set up interrupt from keypad
InterruptIn A(PB_3);
InterruptIn B(PB_5);
InterruptIn D(PB_4);
//The order of 3,5,4 is used due to the order that they appear on the nucelo.
//doing 3,4,5 would end up with more crossed cables


Timer time_set;
// initilize a variable for set time
// static int time_remaining = 0;
Timer time_remaining;
//Time_set is the time that is set by the user, and time remaining is how much of that time is left

bool started = false; 
//started says if the timer has been started at some point and not reset
bool running = false; 
//running says if timer is currently running or not
int row = 0;
//In main function, rows of the keypad will be iterated through, specific are being worked on


//Put any function prototypes here 

//Note: LCD boards require 5 volts. Using 3 volt may cause issues. 

//LCD can be accessessed using the following command with attributes in this order: col, row, dots, SDA, SLA
//PB8 and PB9 are on I2C ports, they are chosen for this purpose

CSE321_LCD LCD_screen( 16, 2, LCD_5x10DOTS, PB_9, PB_8); //Either LCD_5x10DOTS or LCD_5x8DOTS
//If the LCD object file is underlined in red, it is likely because 1802.h is in the wrong spot. 
//Please move 1802.h to the main folder of the program and not a subfolder to fix. 



int main() {
    printf("Program started\n");
    bool started = false;
    bool running = false; 
    //set both timer booleans to false as timer cannot be running or started on bootup. 
  // Initialize ports
  RCC->AHB2ENR |= 0x2;
  // port b enabled
  // ports for keypad are all inputs which need to be set to 00, therefore,
  // nothing must be done set anyways



  // time_set.reset; //time_set isn't being seen by main, resolve that
begin(LCD_screen);
LCD_screen.begin();

  // int time_remaining=0;
  // initilize a variable for set time
  // Initiliaze a variable for time remaining
    //if need to go through each colum, can maybe make an iterator with a modulo operation to go through characters
     // Set up inputs for keypad (refrence ) 
    A.rise(&A_pressed); 
    B.rise(&B_pressed);
    D.rise(&D_pressed);
    LCD_screen.setCursor(0, 0);
    LCD_screen.print("Input a time:");
    LCD_screen.setCursor(0, 1);
    LCD_screen.print("0:00");
  while (true) {


    // Implementations for iterating throw rows would go here if there was time to redesign code
    // Output to LCD

 
  }
  return 0;
}
// The following functions should be called when the relevant button triggers an interrupt
void A_pressed() {
    printf("A has been pressed\n");
    //thread_sleep_for(5);
  //Sleep is to compensate for bounce
  //thread_sleep_for is not recognize on build, must rectify 
  // if timer is not running, start timer
  if (running == false) {
    // start timer
    running = true;
    started = true;
    LCD_screen.setCursor(0, 0);
    LCD_screen.print("Time Remaining:");


    //time_remaining.start();
  } 
    // do nothing if already running
  
}
void B_pressed() {
    printf("B has been pressed\n");
    //thread_sleep_for(5);
  //Sleep is to compensate for bounce
  //thread_sleep_for is not recognize on build, must rectify 

  if ((started == true) && (running == true)) {
    // If timer is running, stop it
    //time_remaining.stop();
    running = false;

  } 
  else if ((started == true) && (running == false)){
      //double check that else if is actualy a thing in C++ 
      //timer has started but is currently stopped. Therefore, reset timer
    // time_remaining = time_set;
      started = false; 

  }
    //if B is pressed and timer is already in the unstarted state, nothing happens.
}

void D_pressed() {
    printf("D has been pressed\n");
    //thread_sleep_for(1);
      //Sleep is to compensate for bounce
      //thread_sleep_for is not recognize on build, must rectify 
    if(started == false){
        //increment timer by 5 seconds
    }
  // Check if timer is currently running, if not, increment time by 5 seconds.
  // timer is based on system time
  //If timer has started, do nothing
}
