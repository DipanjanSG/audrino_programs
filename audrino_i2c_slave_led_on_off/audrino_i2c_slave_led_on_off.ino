#include <Wire.h>

#define LED_PIN 7
#define SLAVE_ADDR 8

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Wire.begin(SLAVE_ADDR);          // Join I2C bus as slave
  Wire.onReceive(receiveEvent);    // Set function to handle incoming data
  Serial.begin(9600);
}

void loop() {
  // Nothing needed here, LED controlled via I2C
}

void receiveEvent(int howMany) {
  if (Wire.available()) {

    
    byte state = Wire.read();  // Read the byte sent by master
    Serial.print("Received state: ");
    Serial.println( state);
    if (state == 1) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
    } else {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
    }
  }
}
