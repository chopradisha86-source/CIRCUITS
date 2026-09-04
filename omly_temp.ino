#include <DHT.h>

// A0 pin ko digital pin 14 ki tarah access kiya jata hai,
// lekin hum direct A0 bhi likh sakte hain.
#define DHTPIN A0     
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Test on Pin A0");
  dht.begin();
}

void loop() {
  // Reading temperature and humidity takes about 250 milliseconds!
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();

  // Check if any reads failed
  if (isnan(humidity) || isnan(tempC)) {
    Serial.println("DHT11 sensor se data read nahi ho raha!");
    delay(2000);
    return;
  }

  // Serial Monitor Output
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" *C");

  delay(2000); // DHT11 needs at least 2 seconds between readings
}
