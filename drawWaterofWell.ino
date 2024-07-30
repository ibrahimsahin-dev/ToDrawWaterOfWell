int sensorPin = 9; // Pin to which the sensor's digital output pin is connected
int relayPin = 7;  // Pin to which the relay module is connected
int is_there_water;

void setup() {
  // Set pin 7, to which the relay is connected, as an output pin
  pinMode(relayPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Wait 12 hours for the first check
  delay(43200000); // 12 hours (12*60*60*1000 milliseconds)
  delay(1000);
  // Control loop until water runs out
  while (true) {
    is_there_water = digitalRead(sensorPin);

    // Print sensor data to the serial monitor
    Serial.print("Water detected: ");
    Serial.println(is_there_water);

    // Turn on the relay when water is detected, turn off the relay when water is gone, and break the loop
    if (is_there_water == LOW) {
      digitalWrite(relayPin, LOW); // Turn on the relay
      Serial.println("Relay ON"); // Motor runs
    } else {
      digitalWrite(relayPin, HIGH); // Turn off the relay
      Serial.println("Relay OFF"); // Motor stops
      break; // Exit the loop when water is gone
    }

    // Wait 1 second
    delay(1000);
  }
}
