#include <Keyboard.h>

int i = 0;

void setup() {
  delay(5000);
  Keyboard.begin();
  delay(4000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("C:\\Users\\dipanjan\\Desktop\\temp.txt");
  delay(500);

  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);

}


void loop() {

  

  Keyboard.print("Temperature: ");
  Keyboard.print(i);
  Keyboard.write('\n');
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();

  delay(2000);
  i++;
}



