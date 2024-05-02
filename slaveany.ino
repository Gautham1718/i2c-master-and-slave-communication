#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(9);  // Address the Arduino as a slave with address 9
  Wire.onReceive(receiveEvent);
}

void loop() {
  // Slave does not need a loop as it only responds to commands from the master
  delay(100);  // Adjust delay as needed
}

void receiveEvent(int bytes) {
  if (bytes >= sizeof(int)) {
    int value = 0;
    for (int i = 0; i < sizeof(int); i++) {
      value |= (Wire.read() << (i * 8)); // Read numerical value from master
  }
    Serial.println("Received value from master:");
    Serial.println(value);
  }
}
