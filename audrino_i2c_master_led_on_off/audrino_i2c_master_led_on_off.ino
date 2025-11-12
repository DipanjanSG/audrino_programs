#include <Wire.h>

#define SLAVE_ADDR 8  //slave 1 
#define SLAVE2_ADDR 9 //slave 2
int ledState = 0;

void setup() {
  Wire.begin();        
  Serial.begin(9600);
  Serial.println("Leonardo Master Ready. Type 1 or 0 to control Mega LED.");
}
void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '1' || c == '0') {
      ledState = c - '0';
      Wire.beginTransmission(SLAVE_ADDR);
      Wire.write(ledState);
      Wire.endTransmission();
      Serial.print("Sent: ");
      Serial.println(ledState);

      Wire.beginTransmission(SLAVE2_ADDR);
      int otherLedState = ledState == 1 ? 0 : 1;
      Wire.write(otherLedState);
      Wire.endTransmission();

      Serial.print("Sent other slave: ");
      Serial.println(otherLedState);
      delay(100);
    }
  }
}
