#include "RotaryEncoder.h" // add encoder library
RotaryEncoder encoder(A2, A3);  // define encoder pins

// define encoder steps and max / min positions
#define STEPS  5
#define MINPOS 0
#define MAXPOS 255

int ledBrightness, position;

void setup() {
   pinMode(11, OUTPUT);           // define LED pin 
   
   Serial.begin(9600);
   encoder.setPosition(10 / STEPS);
}


void loop() {
   // check encoder rotor position
   encoder.tick();
   position = encoder.getPosition() * STEPS;

   // output position to serial monitor
   Serial.println(position);
   

   // normalize position values on led values range
   if (position < MINPOS) { 
     encoder.setPosition(MINPOS / STEPS); 
     position = MINPOS;
   }
   else if (position > MAXPOS) { 
     encoder.setPosition(MAXPOS / STEPS); 
     position = MAXPOS; 
   }
  
  // 
   if (ledBrightness != position) {
      ledBrightness = position;
   }

   Serial.println(ledBrightness);
   analogWrite(11, ledBrightness);
   
}
