/*
  FlamingoEda LCD - Usage example

  Demonstrates how to use the 16x2 LCD display by FlamingoEda.
  The LCD display uses serial communication and provides a
  basic api composed of the following commands:
  - $CLEAR      clear the screen
  - $GO x y     move the cursor to the x-th line y-th column
  - $PRINT text print the text
  - $CURSOR a b enable/disable the cursor display and blinking

  Library written by Paolo D'Apice <paolo.dapice@gmail.com>

  This example code is in the public domain
*/

// include the library code
#include <FLCD.h>
// include required library
#include <SoftwareSerial.h>

FLCD lcd(5); // initialize serial transmission on pin 5

void setup() {
}

void loop() {
  lcd.clear(); // clear the screen
  lcd.cursor(true, true); // enable cursor and make it blink

  lcd.go(1); // go to first line
  lcd.print("Hello World!");
  lcd.go(2); // go to the second line
  lcd.print("This is a long line"); // long lines won't be fully displayed
  delay(2000);

  lcd.clear();
  lcd.cursor(false); // do not show cursor
  lcd.go(1);
  lcd.print("ASCII characters:");
  for (int c = 0; c < 128; ++c) {
    lcd.go(2, 3); // go to second line, third character
    lcd.print("test: ");
    lcd.print((char)c);
    delay(500);
  }
}
