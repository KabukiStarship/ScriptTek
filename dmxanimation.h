/* Kabuki Tek Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.tek.git
@file    /dmx_animation.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License, v. 
2.0. If a copy of the MPL was not distributed with this file, You can obtain one
at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <module_config.h>
#ifndef KABUKI_TEK_DMX_ANIMATION
#define KABUKI_TEK_DMX_ANIMATION 1

namespace _ {

/*< @fn    UpdateHandler  (UIC, UIC, UIA);
@brief C function Update handler for DMXAnimation.
@code
UIC ExampleAnimation1  (num_channels, num_chases, num_variants);
@endcode */
typedef void (*UpdateHandler)(UIC Chase, UIC Frame, UIA Scene);

// inline BOL IsInvalidFrame  (UIC Index);

/* A simple DMX animation with variant.

*/
class DmxAnimation {
 public:
  enum {
    FPS = 30  //< The target frames per second.
  };

  /* Simple default constructor. */
  DmxAnimation(UIC num_channels, UIC num_chases, UIC num_variants);

  /* Resets the animation to the first frame */
  void ResetAnimation();

  /* Sets the currentChase to the given Index. */
  void SetChaseNumber(UIC Index);

  /* Function sends out DMX data for the given channel. */
  void SetChannelData(UIB Channel, UIA value);

  /* Function sets an RGB color starting at the given channel. */
  void SetRGBColor(UIB Channel, CRGBAUI4 value);

  /* Randomizes the currentVariant */
  void RandomizeVariant();

  void SendScene();
  void SetChase(UIA chaseNumber);
  void RandomizeSceneVariant();
  void SetColor(UIB channel, UIA red, UIA green, UIA blue);
  void SetColor(UIB channel, CRGBAUI4 color);
  void SetAllColors(CRGBAUI4 color);
  CRGBAUI4 IncreaseBrightness(CRGBAUI4 color, UIA brightness_change);
  CRGBAUI4 DecreaseBrightness(CRGBAUI4 color, UIA brightness_change);

 protected:
  UIA param1_,                //< Animation parameter 1/Red.
      param2_,                //< Animation parameter 2/Green.
      param3_,                //< Animation parameter 3/Blue.
      param4_;                //< Animation parameter 4/White.
  UIC current_chase_,         //< Current chase number.
      current_chase_length_,  //< Length of the current chase.
      current_variant_,       //< Current variant.
      channel_count_,         //< The number of DMX channels.
      num_chases_,            //< The number of DMX chases.
      num_variants_;          //< The number of variations of the animation.
  UIA* data_;                 //< Pointer to the DMX data for the current scene.
};
}  // namespace _
#endif
