#include "TMCStepper.h"


// Constructor using the FULL hardware SPI pinout for Rambo 1.1b
// Arguments: (CS, RSENSE, MOSI, MISO, SCK)
TMC2130Stepper TMC2130X = TMC2130Stepper(X_ENABLE_PIN,  X_DIR_PIN, X_STEP_PIN, X_CS_PIN); // it is a x-motion 
TMC2130Stepper TMC2130Y = TMC2130Stepper(Y_ENABLE_PIN,  Y_DIR_PIN, Y_STEP_PIN, Y_CS_PIN); // it is a y-motion 
TMC2130Stepper TMC2130Z = TMC2130Stepper(Z_ENABLE_PIN,  Z_DIR_PIN, Z_STEP_PIN, Z_CS_PIN); // it is a z-motion 

//global variable
bool dir = true;

void initializeStepper(){
    TMC2130X.begin(); // Initiate pins and registeries
    TMC2130X.SilentStepStick2130(600); // Set stepper current in mA
    TMC2130X.stealthChop(1); // Enable extremely quiet stepping, if 0, it is LOUD. Probably would worn down the internal gears?
    TMC2130Y.begin();
    TMC2130Y.SilentStepStick2130(600); 
    TMC2130Y.stealthChop(1); 
    TMC2130Z.begin();
    TMC2130Z.SilentStepStick2130(600); 
    TMC2130Z.stealthChop(1); 
    digitalWrite(X_ENABLE_PIN, LOW);
    digitalWrite(Y_ENABLE_PIN, LOW);
    digitalWrite(Z_ENABLE_PIN, LOW);
}

void testingTMCstepper(bool enabled){
    // this does work!
    if (enabled){
        digitalWrite(X_STEP_PIN, HIGH);
        delayMicroseconds(10); //These delay controls the speed. lower = faster.  
        digitalWrite(X_STEP_PIN, LOW);
        delayMicroseconds(10);
        uint32_t ms = millis();
        static uint32_t last_time = 0;
        if ((ms - last_time) > 1000) {
            if (dir) {
                Serial.println("Dir -> 0");
                TMC2130X.shaft_dir(0);
            } else {
                Serial.println("Dir -> 1");
                TMC2130X.shaft_dir(1);
            }
            dir = !dir;
            Serial.println(TMC2130X.GCONF(), BIN);
            last_time = ms;
        }
    }
}

