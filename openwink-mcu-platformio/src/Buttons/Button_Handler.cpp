#include "Button_Handler.h"

#include "../Eye_Control/Eye_Manager.h"
#include "../Error_Logging.h"
#include "esp_timer.h"

Button_Handler::Button_Handler() 
  : buttonCount_(0)
  , debounceTimer_(0) {
    AddButton(OEM_BUTTON_INPUT, true);
    AddButton(AUX_1_BUTTON_INPUT, false);
    AddButton(AUX_2_BUTTON_INPUT, false);
}

Button_Handler::~Button_Handler() {
    // Deconstructor
}

void Button_Handler::AddButton(gpio_num_t gpioPin, bool active) {
  // Initializes a button
  Button aButton(gpioPin, active);
  // Add the button to the list of buttons
  if (buttonCount_ < MAX_BUTTONS) {
    buttons_[buttonCount_++] = aButton;
  }
}

void Button_Handler::ReadOnWakeup() {
  // Disable any previous wakeup sources
  esp_err_t err = esp_sleep_disable_wakeup_source(ESP_SLEEP_WAKEUP_ALL);
  LOG_ERROR(err, DISABLE_WAKE);

  // Loop through all added buttons for configuration of wakeup
  for (size_t i = 0; i < buttonCount_; ++i)
  {
    Button& theButton = buttons_[i];
    // TODO: Check if button is installed
    if (theButton.IsActive())
    {
      theButton.UpdateButtonWakeup();
      err = esp_sleep_enable_timer_wakeup(15 * 1000 * 1000);
      LOG_ERROR(err, TIMER_WAKE);
    }
    // if (theButton.IsCustomCommandActive())
    // {
    //   const uint64_t now = esp_timer_get_time() / 1000;
    //   theButton.SetMainTimer(now);
    //   if (theButton.IsDirty())
    //   {
    //     theButton.buttonPressCounter_++;
    //     theButton.SetButtonTimer(now);
    //     debounceTimer_ = now;
    //   }
    // }
  }

}

void Button_Handler::HandleButtonEvent(const ButtonEvent& event)
{
    // Button Event contains the button id and whether the 
    // button was pressed or released
}



