#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(9); // Address the Arduino as a slave with address 9
  Wire.onReceive(receiveEvent);
}

void loop() {
  // Slave does not need a loop as it only responds to commands from the master
  delay(100); // Adjust delay as needed
}

void receiveEvent(int bytes) {
  while (Wire.available()) {
    char command = Wire.read();
    if (command == '1') {
      Serial.println("Received command 1 from master");
    }
  }
}
