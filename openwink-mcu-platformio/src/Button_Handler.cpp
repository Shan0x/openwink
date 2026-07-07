#include <Button_Handler.h>

#include "../include/Headlight_Commander.h"

#include "esp_log.h"

Button_Handler::Button_Handler(ButtonConstants::ButtonID buttonId)
    : mainTimer_(0)
    , buttonTimer_(0)
    , wakeupButtonState_(0)
    , currentButtonState_(0)
    , buttonId_(buttonId) {
}

Button_Handler::~Button_Handler() {
    // Deconstructor
}

void Button_Handler::ReadOnWakeup() {
  RTCData &btn = RTCButton::Get(buttonId_);
  wakeupButtonState_ = btn.savedButtonState;
  
  switch (buttonId_) {
    case ButtonConstants::OEM_BUTTON:
      currentButtonState_ = gpio_get_level(OEM_BUTTON_INPUT);
      break;
      // case ButtonConstants::CUSTOM_BUTTON_1:
      // currentButtonState_ = gpio_get_level(CUSTOM_BUTTON_INPUT);
      // break;
    default:
      // Do nothing
      break;
  }

  if (ButtonStateDiffers()) {
    // The button was pressed
    buttonPressCounter_++;
    bool cmdSuccess = false;
    // TODO: Handle customButtonStatusEnabled
    if (currentButtonState_ == BUTTON_ON) {
      cmdSuccess = Headlight_Commander::getInstance().command(HEADLIGHT_COMMAND::BOTH_UP);
    } else {
      cmdSuccess = Headlight_Commander::getInstance().command(HEADLIGHT_COMMAND::BOTH_DOWN);
    }

    if (cmdSuccess) {
      btn.savedButtonState = currentButtonState_; // Save off button state
    } else {
      // Log error and do nothing
    }
    // TODO: Set All Off Method - Disable all pins
  }
}

bool Button_Handler::ButtonStateDiffers() {
  return wakeupButtonState_ != currentButtonState_;
}
