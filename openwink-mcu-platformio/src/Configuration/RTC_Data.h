#ifndef __RTC_BUTTON_DATA_H
#define __RTC_BUTTON_DATA_H

#include "../globals.h"
#include "esp_attr.h"
#include <cstdint>

/// @brief Description:
/// Contains RTC data that needs to persist 
/// through "deep sleep".

// Contains the rtc data of all buttons
// Should only be initialized once
// Getter/Setters for the RTC Data for each button
class RTC_Data {

  public:
    struct RtcButtonData {
      ButtonData rtcData[MAX_BUTTONS];
      bool bypassHeadlightOverride;
    };
    RtcButtonData rtcButton;

    void Insert(int buttonId, ButtonData& buttonData);
    void SetInitialState(int buttonId, ButtonState state);
    void SetHeadlightOverride(bool override);

  protected:

  private:
  };
  extern RTC_Data rtcData;

#endif // RTC_BUTTON_DATA_H
