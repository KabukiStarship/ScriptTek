/* Kabuki Tek Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.tek.git
@file    /led_matrix.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License, v. 
2.0. If a copy of the MPL was not distributed with this file, You can obtain one
at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <module_config.h>
#ifndef KABUKI_TEK_LEDMATRIX
#define KABUKI_TEK_LEDMATRIX 1

namespace _ {

/* An M x N LED matrix, where 1 <= M <= 8 and 0 <= N <= 255.
Multiplexing LEDs involves switching between rows in a "mux" one row at a
time, and giving each row 256 steps. The PWM counter counts down to zero.
In order to pack as many LEDs into RAM as possible, only one bit is used
to store the LED state. */
template <UIA kRowCount_, UIA kColCount_>
class LEDMatrix {
 public:
  /* Simple default constructor. */
  LEDMatrix(UIA* Rows, UIA* Columns) : row(Rows), columns(Columns) {}

  inline void ClearLEDs() {
    *row = 0;

    for (UIA i = 0; i < kColCount_; ++i) {
    }
  }

  /* Updates the LED matrix row. */
  inline void Update(UIA Row) {
    if (Row > kRowCount_) {
      // printf ("Error: Row out of bounds!");
      return;
    }
    *row = Row;
  }

 private:
  UIA *row,      //< Pointer to the row UIA.
      *columns;  //< Pointer to the column.
};
}  // namespace _
#endif
