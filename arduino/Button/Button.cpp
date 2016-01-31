#include <Arduino.h>
#include "Button.h"

#define numPins 7

int pins[numPins] = {3,4,5,6,7,8,9};

//basically makes sure the input isn't read multiple times.
void debounce(int x) {
  while(!digitalRead(pins[x])) {}
  delay(200);
}

/*
  This function reads all 13 inputs and when a button is 
pressed, the integer value is returned and the function exits.
*/
int whatButton() {
  int index;
  int states[numPins] = {1,1,1,1,1,1,1}; 
  while(true) {
    for (int i = 0; i < numPins; i++) {
      states[i] = digitalRead(pins[i]);
      if (states[i] == 0) {
		debounce(i);
		return i;
      }
    }
  }
}
/*
  This function sets all the values in pins[] to be an input and set
  as an internal pullup.

*/
void initButtons() {
for (int i = 0; i < numPins; i++) {
  pinMode(pins[i], INPUT);
  digitalWrite(pins[i], HIGH);  
  }
}
