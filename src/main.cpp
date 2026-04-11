#include <Arduino.h>
#include <SPI.h>
#include <TMC2130Stepper.h>

#include "TMCStepper.h"


void setup() {
  Serial.begin(115200);
  initializeStepper();
}



void loop() {
  testingTMCstepper(true);
}

