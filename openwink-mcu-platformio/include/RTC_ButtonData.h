#ifndef __RTC_BUTTON_DATA_H
#define __RTC_BUTTON_DATA_H

#include "../include/globals.h"
#include "esp_attr.h"
#include <cstdint>

// Default: 1 button - OEM Button
// Increment to match amount of physical buttons
//  that can be controlled.
#define MAX_BUTTONS 1

/// @brief Description:
/// Contains RTC data that needs to persist 
/// through "deep sleep".
struct RTCData {
  std::uint16_t savedButtonState;
  bool bypassHeadlightOverride;
  bool isDirty;
};

// Contains the rtc data of all buttons
// Should only be initialized once
extern RTCData rtc_buttonData[MAX_BUTTONS];

// Getter/Setters for the RTC Data for each button
namespace RTCButton {
  inline RTCData &Get(ButtonConstants::ButtonID button) {
    return rtc_buttonData[button];
  }

  inline std::uint16_t GetSavedState(ButtonConstants::ButtonID button) {
    return rtc_buttonData[button].savedButtonState;
  }

  inline void SetSavedState(ButtonConstants::ButtonID button, uint16_t state) {
    rtc_buttonData[button].savedButtonState = state;
  }

  inline bool IsDirty(ButtonConstants::ButtonID button) {
    return rtc_buttonData[button].isDirty;
  }

  inline void SetDirty(ButtonConstants::ButtonID button, bool state) {
    rtc_buttonData[button].isDirty = state;
  }
}

#endif // RTC_BUTTON_DATA_H
