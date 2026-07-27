#include "RTC_Data.h"

RTC_DATA_ATTR RTC_Data rtcData = {};

void RTC_Data::Insert(int buttonId, ButtonData& data) {
  rtcButton.rtcData[buttonId].buttonPin = data.buttonPin;
  rtcButton.rtcData[buttonId].initialState = data.initialState;
}

void RTC_Data::SetInitialState(int buttonId, ButtonState state)
{
  rtcButton.rtcData[buttonId].initialState = state;
}

void RTC_Data::SetHeadlightOverride(bool override)
{
  rtcButton.bypassHeadlightOverride = override;
}