#ifndef TESTTMCSTEPPER_H
#define TESTTMCSTEPPER_H

#include <Arduino.h>
#include <TMC2130Stepper.h>

// RAMBo v1.2b X-Axis Pin Map
#define X_STEP_PIN    37 // on Atmega 2560 slot
#define X_DIR_PIN     48 // PD5
#define X_ENABLE_PIN  29 // NC7-GND
#define X_MS1_PIN     64 // Microstepping 1
#define X_CS_PIN     41 // Microstepping 2 (Formerly X_CS_PIN)

// RAMBo v1.2b Y-Axis Pin Map
#define Y_STEP_PIN    36 
#define Y_DIR_PIN     49
#define Y_ENABLE_PIN  28 
#define Y_MS1_PIN     69 
#define Y_CS_PIN     39 

// RAMBo v1.2b Z-Axis Pin Map
#define Z_STEP_PIN    35 
#define Z_DIR_PIN     47
#define Z_ENABLE_PIN  27 
#define Z_MS1_PIN     68 
#define Z_CS_PIN      67

void initializeStepper();
void testingTMCstepper(bool enabled);

#endif