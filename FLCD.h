/*
 * FlamingoEda LCD display library.
 *
 * This library provides a simple API for the LCD
 * provided by FlamingoEda.
 * The LCD display uses serial communication and responds
 * to commands written in the format "$COMMAND arguments\r\n".
 * The provided API composed of the follwing commands:
 * - $CLEAR      clear the screen
 * - $GO x y     move the cursor to the x-th line y-th column
 * - $PRINT text print the text
 * - $CURSOR a b enable/disable the cursor display and blinking
 *
 * Library written by Paolo D'Apice <paolo.dapice@gmail.com>
 *
 * This code is in the public domain.
 */

#ifndef FLCD_H
#define FLCD_H

#include <Arduino.h>

/// Functions for using FlamingoEda LCD.
class FLCDClass {
public:

    /// Clear the screen.
    void clear();

    /// Configure cursor.
    void cursor(bool display = true, bool blink = false);

    /// Position the cursor.
    void go(int line, int column = 1);

    /// Print text.
    template <typename T>
    void print(T what);

    /// Append text.
    template <typename T>
    void append(T what);

};

/// Shared instance.
extern FLCDClass FLCD;

template <typename T>
void FLCDClass::print(T what) {
    Serial.print("$PRINT ");
    Serial.print(what);
    Serial.print("\r\n");
}

template <typename T>
void FLCDClass::append(T what) {
    Serial.print(what);
    Serial.print("\r\n");
}

#endif // FLCD_H
