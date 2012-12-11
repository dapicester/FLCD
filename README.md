FLCD
====

This library provides a simple API for the LCD display provided by FlamingoEda.
The display uses serial communication and responds to commands written in the
format:

    "$COMMAND arguments\r\n"

Available commands are:

- `$CLEAR`
   clear the screen
- `$GO x y` 
   move the cursor to the x-th line y-th column
- `$PRINT text`
   print the text
- `$CURSOR display blink` 
   enable (`1`) or disable (`0`) the cursor displaying and blinking

The library wraps such commands:

- `FLCD.clear()`
- `FLCD.go(int line, int column)`
- `FLCD.print()` and `FLCD.append()`
- `FLCD.cursor(bool display, bool blink)`

Library written by Paolo D'Apice <paolo.dapice@gmail.com>

