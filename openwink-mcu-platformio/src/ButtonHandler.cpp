#include <ButtonHandler.h>

#include "esp_log.h"

Button_Handler::Button_Handler(ButtonConstants::ButtonID button)
    : mainTimer_(0)
    , buttonTimer_(0)
    , wakeupValue_(0)
    , inputValue_(0)
    , selectedButton_(button) {
  // Constructor - initialize timers.
}

Button_Handler::~Button_Handler() {
    // Deconstructor
}

void Button_Handler::ReadOnWakeup() {
  RTCData &btn = RTCButton::Get(selectedButton_);
  wakeupValue_ = btn.savedButtonState;
  inputValue_ = gpio_get_level(OEM_BUTTON_INPUT);
  btn.savedButtonState = inputValue_;

  if (ButtonStateDiffers()) {
    // There was a button press and state has changed
    buttonPressCounter_++;

    // TODO: Handle customButtonStatusEnabled
    if (inputValue_ == BUTTON_PRESSED) {
      // TODO: Create BothUp method
      // BOTH_UP;
    } else {
      // TODO: Create BothDown method
      // BOTH_DOWN;
    }
    // TODO: Set All Off Method - Disable all pins
  }
}

bool Button_Handler::ButtonStateDiffers() {
  return wakeupValue_ != inputValue_;
}

RTCData &Button_Handler::GetButtonRTCData() {
  return RTCButton::Get(selectedButton_);
}
