#include "mbed_thread.h"
#include <stdio.h>
#include <mbed.h>
#include "1802.h" //make sure this header file is where it should be
//#include "1802.cp"

//import 1802.cp? 

// main() runs in its own thread in the OS

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

//hopefully by definind them as static before anything else, they should be globally accessible by all functions.
//Might need to move them to main, though that seems to not work with the button pressing functions. 
static int time_set = 0;
//initilize a variable for set time

static int time_remaining = 0;
//Initiliaze a variable for time remaining 

//The following functions should be called when the relevant button trigger an interrupt

void A_pressed(){
//if timer is not running, start timer

}
void B_pressed(){


if(true){
//If timer is running, stop it

}
else
//If timer is not running, reset timer
time_remaining = time_set;

}

void D_pressed(){
//Check if timer is currently running, if not, increment time by 5 seconds. 

}


int main()
{
//Initialize ports
//Set up inputs for keypad (refrence )
int time_set = 0;
//int time_remaining=0;
//initilize a variable for set time
//Initiliaze a variable for time remaining 


//

    while (true) {
            //Insert interrupts here that trigger when button is pressed
            //Output to LCD
    }
}


