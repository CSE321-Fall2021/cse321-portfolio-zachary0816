
/* 
author1: Zachary Wolf
author2: none
Modules/Subroutines used: 
Corresponding assignment(s): Project 3
Inputs: Infared sensor
Outputs: Red LED, Green LED, Vibration motor
Constraints:
Sources and/or refrences used:
https://os.mbed.com/platforms/NUCLEO-L4R5ZI/
STM32L4+ Series advanced Arm®-based 32-bit MCUs - Reference manual
https://www.st.com/resource/en/reference_manual/dm00310109-stm32l4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
https://os.mbed.com/docs/mbed-os/v6.15/apis/watchdog.html
Purpose: Create an device that can act as feedback to the visually impaired by vibrating when near an object.
*/
//#include "Watchdog.h"

#include <stdio.h>
#include "mbed.h"



//Thread program_thread;
/*The above line was supposed to be used to create a thread, however this instance of mbed studio does not
recognize 'Thread' as a valid thing that can be created. Hours of debugging has not rectified this.*/

/*
void infared_detection(){
} */
//This functioin would have handled detection, but cannot be used to do lack of threads, contents have been moved elsewhere in the code.


void not_detected(){
GPIOB->ODR|=(0x10);
GPIOB->ODR&=~(0x20);
printf("not detected\n");
Watchdog::get_instance().kick();

}
//elements that should trigger when system detects something
//enable red LED, disbale green, activates motor (which is on the same path as the red LED)

void detected(){
printf("detected\n");
    GPIOB->ODR&=~(0x10);
    GPIOB->ODR|=(0x20);
    Watchdog::get_instance().kick();
    
}
//these elements should trigger when system stops detecting something

InterruptIn Trigger_input(PB_3);
//This is the signal that will come in when the infared sensor is activated



int main()
{

    printf("program started\n");
    RCC->AHB2ENR |=0x2;
    //Enables ports B by inputting what in binary would be 10
    
    GPIOB->MODER&=~(0x800);
    GPIOB->MODER|=0x400;
    printf("output mode enabled for GPIOB\n");
    //Set PB5 to output mode which is 01. MODER5 uses ports 10 and 11. 
    GPIOB->MODER&=~(0x200); 
    GPIOB->MODER|=0x100;
    //Enable PB4
    not_detected();
    //set LEDs to "not detected" state by default
//set program to output mode, which is 01, these commands via MODER are individually setting those bits in port 14 and 15
const uint32_t Watchdog_timeout = 9000;
Watchdog &Program_watchdog = Watchdog::get_instance();
Program_watchdog.start(Watchdog_timeout);
//The watchdog trigger after a certain period of time if no interrupts are triggered.
//It makes sure the system doesn't get stuck in the object detected state if 
//the trigger to stop detecting somehow fails.



//thread.start(infared_detection());
//cannot activate thread since threads cannot be defined

while(true)
{
    Trigger_input.rise(&not_detected);
    Trigger_input.fall(&detected);
}
 
 //this final section should never execute in the current state, but if a shutdown button were to be added, this would be useful
    GPIOB->ODR&=~(0x20);
    GPIOB->ODR&=~(0x10);
     GPIOB->ODR&=~(0x8);
    //make sure both LEDs and motor is shut off
printf("shutting down\n");

return 0;

}




