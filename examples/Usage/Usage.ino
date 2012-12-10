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
  
  This example code is in the public domain.  
*/

// include the library code
#include <FLCD.h>

void setup() {
  // initialize serial communication
  Serial.begin(9600);
}

void loop() {
  FLCD.clear(); // clear the screen
  FLCD.cursor(true, true); // enable cursor and make it blink
  
  FLCD.go(1); // go to first line
  FLCD.print("Hello World!");
  FLCD.go(2); // go to the second line
  FLCD.print("This is a long line"); // long lines won't be fully displayed
  delay(2000);

  FLCD.clear();
  FLCD.cursor(false); // do not show cursor
  FLCD.go(1);
  FLCD.print("ASCII characters:");
  for (int c = 0; c < 128; ++c) {
    FLCD.go(2, 3); // go to second line, third character
    FLCD.print("test: ");
    FLCD.print((char)c);
    delay(500);
  }
}
