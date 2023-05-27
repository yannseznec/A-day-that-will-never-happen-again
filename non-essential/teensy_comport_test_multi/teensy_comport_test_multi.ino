
#include "SPI.h"

const  int numAnalogs = 4;
const  int numDigitals = 1;
const int numDigitalOuts = 5;


  int newVal[numAnalogs];
  int currentVal[numAnalogs];

  int fromPD = 0;
  String analogInput[] = {
  "analog0 ", "analog1 ", "analog2 ", "analog3 ", "analog4 ", "analog5 ", "analog6 ", "analog7 ", "analog8 ", "analog9 ", "analog10 ", "analog11 ", "analog12 ",
};

  String digitalInput[] = {
  "digital0 ", "digital1 ", "digital2 ", "digital3 ", "digital4 ", "digital5 ", "digital6 ", "digital7 ", "digital8 ", "adigital9 ", "digital10 ", "digital11 ", "digital12 ",
};

  int analogPins[] = {
    14,15,16,17,18,19,20,21,22,23,24,25,26
  };
    int digitalPins[] = {
    2,3,4,5,6,7,8,9,10,11,12,13
  };

void setup() {

  for (int i = 0; i < numAnalogs; i++) {
    pinMode(analogPins[i], INPUT_PULLUP);
  }

  for (int i = 0; i < numDigitals; i++) {
    pinMode(digitalPins[i], INPUT_PULLUP);
  }

    pinMode(13, OUTPUT);
    
    Serial.begin(9600);
      while (!Serial) {
    ; 
  }
  
}

void loop() {

  for (int i = 0; i < numAnalogs; i++) {
    newVal[i] = analogRead(analogPins[i]);

    if (abs(newVal[i] - currentVal[i])>1) { 
    
    Serial.print(analogInput[i]);
    Serial.print(analogRead(analogPins[i]));
    Serial.print(" ");
    Serial.println(0);
    currentVal[i] = newVal[i];
    }
  }

for (int i = 0; i < numDigitals; i++) {

    Serial.print(digitalInput[i]);
    Serial.print(digitalRead(digitalPins[i]));
    Serial.print(" ");
    Serial.println(0);
}


// turn the following into an array!!

if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    fromPD = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (fromPD == 10) {
      digitalWrite(13, HIGH);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (fromPD == 11) {
      digitalWrite(13, LOW);
    }
  }
    delay(5);
}
