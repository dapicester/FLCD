FLCD
====

This library provides a simple API for the LCD display provided by FlamingoEda.
The display uses serial communication at 9600 baud/sec and responds to commands i
written in the format:

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

The library wraps such commands in the class `FLCD`:

- `clear()`
- `go(int line, int column)`
- `print()` and `FLCD.append()`
- `cursor(bool display, bool blink)`

Library written by Paolo D'Apice <paolo.dapice@gmail.com>

