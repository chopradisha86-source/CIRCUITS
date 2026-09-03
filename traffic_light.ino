/*
  ===================================================================
  Traffic Light System on Breadboard (No External Resistors)
  ===================================================================
  Connections:
  - Red LED (+)    --> Digital Pin 2
  - Yellow LED (+) --> Digital Pin 3
  - Green LED (+)  --> Digital Pin 4
  - All LEDs (-)   --> Breadboard Blue (-) Rail --> Arduino GND
  ===================================================================
*/

const int RED_LED = 2;
const int YELLOW_LED = 3;
const int GREEN_LED = 4;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

// Software current-limiting function using rapid pulsing
void safeLight(int pin, int durationMs) {
  unsigned long startTime = millis();
  while (millis() - startTime < (unsigned long)durationMs) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(300); // Brief ON time
    digitalWrite(pin, LOW);
    delayMicroseconds(700); // OFF time protects LEDs without physical resistors
  }
}

void loop() {
  // RED Light - 5 Seconds
  safeLight(RED_LED, 5000);

  // YELLOW Light - 2 Seconds
  safeLight(YELLOW_LED, 2000);

  // GREEN Light - 5 Seconds
  safeLight(GREEN_LED, 5000);
}
