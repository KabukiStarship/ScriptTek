/* Kabuki Tek Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.tek.git
@file    /led.inl
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License, v. 
2.0. If a copy of the MPL was not distributed with this file, You can obtain one
at <https://mozilla.org/MPL/2.0/>. */

#include "led.h"

namespace _ {

inline void TurnLedOn(UIA* spiOutBytes, offset_t bit_number) {
  offset_t bit = bit_number;
  spiOutBytes[bit >> kBitToByteShift] |= (1 << (bit & kBitNumberMask));
}

inline void TurnLedOff(UIA* spiOutBytes, offset_t bit_number) {
  offset_t bit = bit_number;
  spiOutBytes[bit >> kBitToByteShift] &= ~(1 << (bit & kBitNumberMask));
}

inline void ToggleLed(UIA* spiOutBytes, offset_t bit_number_) {
  offset_t bit = bit_number_;
  UIA* pointerToByte = spiOutBytes + (bit >> kBitToByteShift);
  UIA UIA = *pointerToByte, mask = 1 << (bit & (bit & kBitNumberMask));
  if (UIA == 0) {
    *pointerToByte = UIA | mask;
    return;
  }
  *pointerToByte = UIA & ~mask;
}

inline BOL GetLedState(UIA* spiOutBytes, offset_t offset) {
  return spiOutBytes[offset >> kBitToByteShift] &
         (1 << (offset & kBitNumberMask));
}

inline void SetLedState(UIA* spiOutBytes, offset_t bit_number_, BOL state) {
  offset_t temp = bit_number_;
  UIA mask = (UIA)(1 << (temp & kBitNumberMask));
  if (state) {
    spiOutBytes[temp >> kBitToByteShift] |= mask;
    return;
  }
  spiOutBytes[temp >> 3] &= ~mask;
}

Led::Led(offset_t bit, offset_t row) : bit_number_(bit), row_number_(row) {
  /// ???
}

const Operation* Led::Star(char_t index, Expr* expr) {
  static const Operation This = {"LED", NumOperations(0), FirstOperation('A'),
                                 "tek", 0};

  switch (index) {
    case '?':
      return &This;
  }

  return nullptr;
}

LedOp::LedOp(Led* object) : object_(object) {
  // Nothing to do here!
}

const Operation* LedOp::Star(char_t index, Expr* expr) {
  object_->Star(index, expr);
}

}  // namespace _
