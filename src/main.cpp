#include <Arduino.h>
#include <SPI.h>
#include <TMC2130Stepper.h>

// Rambo v1.1 X-Axis Pin Map
#define X_STEP_PIN    37
#define X_DIR_PIN     48
#define X_ENABLE_PIN  29
#define X_CS_PIN      41 

// Constructor using the FULL hardware SPI pinout for Rambo 1.1b
// Arguments: (CS, RSENSE, MOSI, MISO, SCK)
TMC2130Stepper TMC2130 = TMC2130Stepper(X_ENABLE_PIN,  X_DIR_PIN, X_STEP_PIN, X_CS_PIN);

void setup() {
  Serial.begin(115200);
    TMC2130.begin(); // Initiate pins and registeries
    TMC2130.SilentStepStick2130(600); // Set stepper current in mA
    TMC2130.stealthChop(1); // Enable extremely quiet stepping, if 0, it is LOUD. Probably would worn down the internal gears?
    
    digitalWrite(X_ENABLE_PIN, LOW);
}

bool dir = true;

void loop() {
  digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(10); //These delay controls the speed. lower = faster.  
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(10);
    uint32_t ms = millis();
    static uint32_t last_time = 0;
    if ((ms - last_time) > 1000) {
        if (dir) {
            Serial.println("Dir -> 0");
            TMC2130.shaft_dir(0);
        } else {
            Serial.println("Dir -> 1");
            TMC2130.shaft_dir(1);
        }
        dir = !dir;
        Serial.println(TMC2130.GCONF(), BIN);
        last_time = ms;
    }   
}