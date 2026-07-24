#ifndef __RTC_BUTTON_DATA_H
#define __RTC_BUTTON_DATA_H

#include "../globals.h"
#include "esp_attr.h"
#include <cstdint>

/// @brief Description:
/// Contains RTC data that needs to persist 
/// through "deep sleep".
struct RTCData {
  gpio_num_t pinNum;
  std::uint16_t savedButtonState;
  bool bypassHeadlightOverride;
};

// Contains the rtc data of all buttons
// Should only be initialized once
extern RTCData rtc_buttonData[MAX_BUTTONS];

// Getter/Setters for the RTC Data for each button
namespace RTCButton {
  inline RTCData &Get(gpio_num_t button) {
    return rtc_buttonData[button];
  }

  inline std::uint16_t GetSavedState(gpio_num_t button) {
    return rtc_buttonData[button].savedButtonState;
  }

  inline void SetSavedState(gpio_num_t button, uint16_t state) {
    rtc_buttonData[button].savedButtonState = state;
  }

  inline void SetGpioPinNum(gpio_num_t button) {
    rtc_buttonData[button].pinNum = static_cast<gpio_num_t>(button);
  }
}

#endif // RTC_BUTTON_DATA_H
