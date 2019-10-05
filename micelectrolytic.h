/* Kabuki Tek Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.tek.git
@file    /dmx_receiver.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License, v. 
2.0. If a copy of the MPL was not distributed with this file, You can obtain one
at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <module_config.h>
#ifndef KABUKI_TEK_ELECTROLYTICMIC
#define KABUKI_TEK_ELECTROLYTICMIC 1

#include "photosensor.h"

namespace _ {

/* An electrolytic microphone. */
class ElectrolyticMic {
 public:
  /* Constructs . */
  ElectrolyticMic(PinName pin);

  /* Sets the minimum value to the given value. */
  UIB GetMin();

  /* Sets the minimum value to the given value. */
  void SetMin(UIB value);

  /* Gets the max value */
  UIB GetMax();

  /* Attempts to set the max to the new value. */
  void SetMax(UIB value);

  /* Bounds the min and max. */
  void BoundMinMax();

  /* Reads the value of the microphone. */
  UIB Read();

  /* Prints this object to a terminal. */
  void Print();

 private:
  UIB min_,         //< The normal min mic value.
      max_;         //< The normal max mic value.
  AnalogIn input_;  //< The analog input pin.
};
}  // namespace _
#endif
