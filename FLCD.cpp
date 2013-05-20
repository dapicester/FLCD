/*
  FLCD.cpp - FlamingoEda LCD display library.

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

#include "FLCD.h"

FLCD::FLCD(byte pin) : serial(0, pin) {
    serial.begin(9600); // only this speed is supported
}

FLCD::~FLCD() {}

void FLCD::clear() {
    serial.print("$CLEAR\r\n");
}

void FLCD::cursor(bool display, bool blink) {
    serial.print("$CURSOR ");
    serial.print(display ? "1" : "0");
    serial.print(" ");
    serial.print(blink ? "1" : "0");
    serial.print("\r\n");
}

void FLCD::go(int line, int column) {
    serial.print("$GO ");
    serial.print(line);
    serial.print(" ");
    serial.print(column);
    serial.print("\r\n");
}

