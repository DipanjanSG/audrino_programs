#include <Regexp.h>

int pinNumber = 0;
int onOrOffSignal = 0;
String command = "";
char SEPARATOR_CHAR_IN_COMMAND = '-';
int pinMap[13] = {0,2,3,4,5,6,7,8,9,10,11,12,13};
int TOTAL_NUMBER_OF_RELAYS = 12;
MatchState ms;
const char *pattern = "([0-9]+)-([01])";
char buf[10]; 


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

    extractValuesFromCommand();

    if(pinNumber > 0 && pinNumber <= TOTAL_NUMBER_OF_RELAYS )
    {
      digitalWrite(pinMap[pinNumber], onOrOffSignal);
      sendStatusToConsole(String("turned relay ")+ pinNumber + " " + onOrOffSignal);

    }
    else
    {
      setOrUnsetAllPins();
    }
    

  }

}

void sendStatusToConsole(String msg)
{
  Serial.println(msg);
}

void setOrUnsetAllPins()
{
  for(int relayNum = 1; relayNum <= TOTAL_NUMBER_OF_RELAYS; relayNum++)
  {
       digitalWrite(pinMap[relayNum], onOrOffSignal);
  }

}


void extractValuesFromCommand()
{

  ms.Target(command.c_str());
  int x =  ms.Match(pattern) ;
  Serial.println(x);
  if( ms.Match(pattern) > 0)
  {
       int indexOfSeparator = command.indexOf(SEPARATOR_CHAR_IN_COMMAND);
       ms.GetCapture(buf, 1);
       pinNumber = String(buf).toInt(); 
       ms.GetCapture(buf, 2);
       onOrOffSignal = String(buf).toInt()  == 0 ? LOW: HIGH;

  } 
  else{

   sendStatusToConsole("ERROR: Input is wrong should be in format <pin number>-<0 or 1> ...Ex- 5-0 to turn relay 5 off 5-1 to turn relay 5 on ");
  }
 
}