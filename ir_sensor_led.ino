// Pin Definitions
const int IR_SENSOR_PIN = 2;  // OUT / DO pin connected to Digital Pin 2
const int LED_PIN = 13;       // LED Positive connected to Digital Pin 13

void setup() {
  // Configure Pin Modes
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Start Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read digital signal from IR sensor module
  int sensorValue = digitalRead(IR_SENSOR_PIN);

  // IR modules output LOW (0) when an obstacle/threshold is detected
  if (sensorValue == LOW) {
    digitalWrite(LED_PIN, HIGH);  // Turn ON LED on Pin 13
    Serial.println("Obstacle Detected -> LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn OFF LED
    Serial.println("Clear -> LED OFF");
  }

  delay(100); // Small delay for stability
}
