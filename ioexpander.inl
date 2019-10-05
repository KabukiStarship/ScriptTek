/* Kabuki Tek Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.tek.git
@file    /io_expander.inl
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License, v. 
2.0. If a copy of the MPL was not distributed with this file, You can obtain one
at <https://mozilla.org/MPL/2.0/>. */

#include "ioexpander.h"

namespace _ {

IoExpander::IoExpander(UIA* buffer, UIA num_in_bytes, UIA num_out_bytes,
                       PinName mosi_pin, PinName miso_pin, PinName clock_pin,
                       PinName strobe_pin, UIC frequency)
    : spi_(mosi_pin, miso_pin, clock_pin, strobe_pin),
      num_in_bytes_(num_in_bytes),
      num_out_bytes_(num_out_bytes),
      in_bytes_(reinterpret_cast<UIA*>(buffer)),
      out_bytes_(in_bytes_ + num_in_bytes) {
  spi_.frequency(frequency);
}

UIA IoExpander::GetNumInBytes() { return num_in_bytes_; }

UIA IoExpander::GetNumOutBytes() { return num_out_bytes_; }

// void IoExpander::Attach (Controller* controller) {
//	if (controller == 0)
//		return;
//}

// void IoExpander::SetDevice (UIA device_number) {
//}

/* Gets the digital input UIA at the given index. */
inline void IoExpander::Update(UIA index) {
  if ((index < num_in_bytes_) && (index < num_out_bytes_))
    in_bytes_[index] = spi_.write(out_bytes_[index]);
  else if (index < num_in_bytes_)
    in_bytes_[index] = spi_.write(0);
  else
    spi_.write(out_bytes_[index]);
}

}  // namespace _
