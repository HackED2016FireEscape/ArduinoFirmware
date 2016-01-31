#include <Button.h>



void setup() {
  // put your setup code here, to run once:
  initButtons();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int pressed = whatButton();
 Serial.println(pressed);
}
