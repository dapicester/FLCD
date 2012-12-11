/*
  FLCD.h - FlamingoEda LCD display library.

  Copyright (c) 2012 Paolo D'Apice <paolo.dapice@gmail.com>.
  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
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
