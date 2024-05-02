#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  if (Serial.available() > 0) {
    int value  = Serial.parseInt(); // Read numerical value from serial monitor
      Wire.beginTransmission(9); // Slave address
      Wire.write((byte*)&value, sizeof(value)); // Send value to slave as bytes
      Wire.endTransmission();
      Serial.println("Value sent to slave");
  }
  delay(100); // Adjust delay as needed
}