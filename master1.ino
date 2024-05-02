#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      Wire.beginTransmission(9); // Slave address
      Wire.write('1'); // Send command to slave
      Wire.endTransmission();
      Serial.println("Command sent to slave");
    }
  }
  delay(100); // Adjust delay as needed
}