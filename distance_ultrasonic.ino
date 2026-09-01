/*
  Project 2: Ultrasonic Sensor Distance Measurement
  Description: Measures distance in centimeters using HC-SR04
               and prints the output to the Serial Monitor.
*/

const int trigPin = 9;  // HC-SR04 Trig pin connected to Digital Pin 9
const int echoPin = 10; // HC-SR04 Echo pin connected to Digital Pin 10

void setup() {
  pinMode(trigPin, OUTPUT);  // Trig pin sends ultrasonic waves
  pinMode(echoPin, INPUT);   // Echo pin receives reflected waves
  Serial.begin(9600);        // Start serial monitor
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  // Speed of sound = 0.0343 cm/microsecond (Distance = Duration * 0.0343 / 2)
  float distanceCm = duration * 0.0343 / 2.0;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  delay(500);  // Delay between readings
}
