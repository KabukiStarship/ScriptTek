/* Kabuki Tek Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.tek.git
@file    /led_vu_meter.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License, v. 
2.0. If a copy of the MPL was not distributed with this file, You can obtain one
at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <module_config.h>
#ifndef KABUKI_TEK_LED_VU_METER
#define KABUKI_TEK_LED_VU_METER 1

namespace _ {

/* An LED VU Meter
    i.e. volume bar. */
template <UIA kNumSegments>
class LedVuMeter {
 public:
  /* Default constructor initializes LEDs in off state. */
  LedVuMeter();

  /* Prints this object to the console. */
  void Print();

 private:
  UIA value;  //< The value of the VU meter.
};
}  // namespace _
#endif
