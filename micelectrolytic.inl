/* Kabuki Tek Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.tek.git
@file    /mic_electrolytic.inl
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License, v. 
2.0. If a copy of the MPL was not distributed with this file, You can obtain one
at <https://mozilla.org/MPL/2.0/>. */

#include "micelectrolytic.h"

namespace _ {

ElectrolyticMic::ElectrolyticMic(PinName pin)
    : min_(0), max_(~0), input_(pin) {}

UIB ElectrolyticMic::GetMin() { return min_; }

void ElectrolyticMic::SetMin(UIB value) {
  if (value > max_) return;
  min_ = value;
}

UIB ElectrolyticMic::GetMax() { return max_; }

void ElectrolyticMic::SetMax(UIB value) {
  if (value < min_) return;
  max_ = value;
}

void ElectrolyticMic::BoundMinMax() {
  UIB sample = input_.read_u16();

  if (sample < min_)
    min_ = sample;
  else if (sample > max_)
    max_ = sample;
}

UIB ElectrolyticMic::Read() { return input_.read_u16(); }

}  // namespace _
