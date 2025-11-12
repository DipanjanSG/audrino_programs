

int pinNumber = 0;
int onOrOffSignal = 0;
String command = "";
char SEPARATOR_CHAR_IN_COMMAND = '-';
int pinMap[13] = {0,2,3,4,5,6,7,8,9,10,11,12,13};
int TOTAL_NUMBER_OF_RELAYS = 12;


void setup() {



  for (int i = 1; i <= TOTAL_NUMBER_OF_RELAYS; i++) 
  {
      pinMode(pinMap[i], OUTPUT);
  }


  Serial.begin(9600);
}

void loop() {


  if (Serial.available() > 0) 
  {

    command = Serial.readStringUntil('\n');
    command.trim();
    extractValuesFromCommand(command);

    Serial.print(pinNumber);
    Serial.print("-");
    Serial.print(onOrOffSignal);
    Serial.println();


    if(pinNumber > 0 && pinNumber <= TOTAL_NUMBER_OF_RELAYS )
    {
      digitalWrite(pinMap[pinNumber], onOrOffSignal);
    }
    else
    {
      setOrUnsetAllPins();
    }
    

  }

}


void setOrUnsetAllPins()
{
  for(int relayNum = 1; relayNum <= TOTAL_NUMBER_OF_RELAYS; relayNum++)
  {
       digitalWrite(pinMap[relayNum], onOrOffSignal);
  }

}


void extractValuesFromCommand(String command)
{
  int indexOfSeparator = command.indexOf(SEPARATOR_CHAR_IN_COMMAND);
  pinNumber = command.substring(0,indexOfSeparator).toInt();
  onOrOffSignal = command.substring(indexOfSeparator+1).toInt() == 0 ? LOW: HIGH;
}