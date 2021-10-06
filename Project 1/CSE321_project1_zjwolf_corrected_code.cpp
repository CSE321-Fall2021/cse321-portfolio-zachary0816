#include "mbed.h"
/*

Author 1: Unkown
Author 2: None or Unkown
Modules/Subroutines used: 
Corresponding assignment(s): Project 1, part 6
Inputs: Button1
Outputs: LED2
Constraints:
Sources and/or refrences used:
Purpose:
Create a thread to drive an LED to have an on time of 2000ms and off time
 500ms

*/


Thread controller;
//This function will be trigger upon the the occurence of a given event

void Instance(); 

DigitalOut Output(LED2); // establish blue led as an output
int Iterator=0; InterruptIn Button(BUTTON1); void Button_is_Pressed(); int Flag = 0;
void Button_is_Released();


int main() {
  // start the allowed execution of the thread
  printf("Program start\n");
	printf("Starting state of thread: %d\n", controller.get_state());
  controller.start(Instance);
			printf("State of thread right after start: %d\n", controller.get_state());
  Button.rise(Button_is_Pressed);
	Button.fall(Button_is_Released);

  return 0;
}

// make the handler
void Instance() {
while (true) {



if(Iterator==0){
Output = !Output; //Invert Output 
printf("Output inverted, the program will now sleep for 2000 units\n"); 
thread_sleep_for(2000); //Thread_sleep is a time delay function, causes a 2000 unit delay
Output = !Output; //Invert Output again
printf("Output has been restored to previous state, sleeping for 500 units\n"); thread_sleep_for(500);
 //Thread_sleep is a time delay function, causes a 500 unit delay
    }
  }
}

void Button_is_Pressed() {
 // togle the state of the thread by setting Flag to 1
	Flag=1; 
}

void Button_is_Released() {
  if (Flag==1){
      //if the interrupt Flag is enabled, it will be disable and interated
      //Variable alternates between 1 and 0 every time the Flag is activated
    Iterator++; 
    Iterator %= 2; 
    Flag=0;
}}