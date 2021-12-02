
/* 
author1: Zachary Wolf
author2: none
Modules/Subroutines used: 
Corresponding assignment(s): Project 3
Inputs: 
Outputs: Red LED, Green LED, Vibration motor
Constraints:
Sources and/or refrences used:
Purpose: Create an device that can act as feedback to the visually impaired by vibrating when near an object.
*/
#include "mbed_thread.h"
#include <stdio.h>
#include <mbed.h>

/* To add
Need watchdog timer
need synchronization
need something bitwise
at least 1 DMA configuration 
at least 1 direct bitwise driver configuration 
There's two PB4s, make red LED and vibrator both on PB4, reuse PB3 for ultrasonic? 
Don't have a superloop, have threads
One thread for checking the ultrasonic, one for handling outputs
Ul
I found some schematics about the ultrasonic sensor on the internet, check the folder for refrence info. 

*/




//
bool triggered_state = false;
//this bool describes wether or not the sensor is detecting something

void detected(){
printf("A\n");
GPIOB->ODR|=(0x20);
GPIOB->ODR&=~(0x10);
printf("detected\n");

}
//elements that should trigger when system detects something
//enable red LED, disbale red, activate motor

void not_detected(){
printf("not detected\n");
    GPIOB->ODR&=~(0x20);
    GPIOB->ODR|=(0x10);
}
//elements that should trigger when system stops detecting something

void trigger_sensor(){
//send power to trigger pin, triggers the thing to activate
//According to the data sheet for ultrasonic, must trigger for at least 10 microseonds to activate
GPIOB->ODR|=(0x8);
thread_sleep_for(20);    
GPIOB->ODR&=~(0x8);
}

int main()
{
    printf("program started\n");
    RCC->AHB2ENR |=0x2;
    //Enables ports B by inputting 10 (for refrence, 0x6 would enable ports B and C if necessary)
    
    GPIOB->MODER&=~(0x800);
    GPIOB->MODER|=0x400;
    printf("output mode enabled for GPIOB\n");
    //Set PB5 to output mode which is 01. MODER5 uses ports 10 and 11. 
    GPIOB->MODER&=~(0x200); 
    GPIOB->MODER|=0x100;
    //Enable PB4
    GPIOB->MODER&=~(0x80); 
    GPIOB->MODER|=0x40;
    //enable PB3
    
//set program to output mode, which is 01, these commands via MODER are individually setting those bits in port 14 and 15

//every time you do a trig pulse, it returns the time
int i = 0;

//Loop should turn the LED plugged into PB5 on and off in a repeeating cycle
while(i<4){
    i++;


    detected();
    //Turn on PB5
    //trigger_sensor();
    thread_sleep_for(500);
   
    not_detected();
    //Turn off PB5
    thread_sleep_for(500);
    /*It was mentioned by a TA that wait_ms() should be used in place of thread_sleep_for().
    However wait_ms() command does not appear to be recognized and thread_sleep_for() is functional so it was not used.*/
    

}
    GPIOB->ODR&=~(0x20);
    GPIOB->ODR&=~(0x10);
        GPIOB->ODR&=~(0x8);
    //make sure both LEDs and motor is shut off
printf("shutting down\n");

return 0;

}

