/* Kabuki Tek Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.tek.git
@file    /led_vu_meter_array.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License, v. 
2.0. If a copy of the MPL was not distributed with this file, You can obtain one
at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <module_config.h>
#ifndef KABUKI_TEK_LEDVUMETERARAY
#define KABUKI_TEK_LEDVUMETERARAY 1

namespace _ {

/* An array of LEDs used for a VU Meter like on a stereo. */
template <SIC kNumSegments>
class LedVuMeterArray {
 public:
  /* Simple default constructor. */
  LedVuMeterArray() {}

  /* Gets the number of segments. */
  static SIC GetNumSegments() { return kNumSegments; }

  /* Prints this object to a console. */
  void Print() {}
};
}  // namespace _
#endif
