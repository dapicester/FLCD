/*
 * Library written by Paolo D'Apice <paolo.dapice@gmail.com>
 *
 * This code is in the public domain.
 */

#include "FLCD.h"

void FLCDClass::clear() {
    Serial.print("$CLEAR\r\n");
}

void FLCDClass::cursor(bool display, bool blink) {
    Serial.print("$CURSOR ");
    Serial.print(display ? "1" : "0");
    Serial.print(" ");
    Serial.print(blink ? "1" : "0");
    Serial.print("\r\n");
}

void FLCDClass::go(int line, int column) {
    Serial.print("$GO ");
    Serial.print(line);
    Serial.print(" ");
    Serial.print(column);
    Serial.print("\r\n");
}

FLCDClass FLCD;
