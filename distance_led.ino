/*
  ===================================================================
  Distance Indicator with Serial Monitor Debugging
  ===================================================================
*/

const int RED_LED = 2;
const int YELLOW_LED = 3;
const int GREEN_LED = 4;

const int TRIG_PIN = 7;
const int ECHO_PIN = 6;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600); // Opens communication to read values on computer
}

long measureDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); 

  if (duration == 0) {
    return -1; // -1 indicates timeout / sensor not responding
  }

  return (duration * 0.034) / 2;
}

void safePulse(int pin) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(300);
  digitalWrite(pin, LOW);
  delayMicroseconds(700);
}

void loop() {
  long distance = measureDistanceCM();

  // Print current distance reading to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If sensor is disconnected/failing (reads -1), flash Red as warning
  if (distance == -1) {
    safePulse(RED_LED);
  }
  // Close Distance (< 10 cm) -> RED
  else if (distance > 0 && distance < 10) {
    safePulse(RED_LED);
  }
  // Medium Distance (10 cm to 25 cm) -> YELLOW
  else if (distance >= 10 && distance <= 25) {
    safePulse(YELLOW_LED);
  }
  // Safe Distance (> 25 cm) -> GREEN
  else {
    safePulse(GREEN_LED);
  }
}
