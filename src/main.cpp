#include <Arduino.h>
// #include <MobaTools.h>
#include <SERIAL_SWITCH.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  //int result = myFunction(2, 3);
  pinMode(LED_BUILTIN,OUTPUT); //Built-in LED on pin 13

}

void loop() {
  int i = 5;
  while (i > 0) {
     // put your main code here, to run repeatedly:
    digitalWrite(LED_BUILTIN, HIGH); // LED on
    delay(4000); // 1 sec via 1k ms
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000); //prevent
  }
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
} 