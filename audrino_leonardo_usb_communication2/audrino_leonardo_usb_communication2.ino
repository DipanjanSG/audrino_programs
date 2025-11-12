#include <HID-Project.h>
#include <HID-Settings.h>

const int LED_PIN = 7;
uint8_t hidBuffer[64]; 

void setup() {
  pinMode(LED_PIN, OUTPUT);

  RawHID.begin(hidBuffer, sizeof(hidBuffer));
}

void loop() {


  Serial.println(RawHID.available());


  if(RawHID.available() == sizeof(hidBuffer) )
  {
    int bytesRead = RawHID.read(); 

    if (bytesRead > 0) {
      uint8_t command = hidBuffer[0]; 
      Serial.print("command ");
      Serial.print(command);
      if (command == 1) {
        digitalWrite(LED_PIN, HIGH);
      } else if (command == 2) {
        digitalWrite(LED_PIN, LOW);
      }

      while(RawHID.available() > 0)
      {
        RawHID.read();
      }
      
    }
  }

  delay(20);
}
