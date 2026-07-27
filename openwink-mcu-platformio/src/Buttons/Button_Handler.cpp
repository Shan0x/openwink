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
    // TODO: Check if button is installed and enable/disable it.
    if (theButton.IsInstalled())
    {
      theButton.ConfigureWakeup();
    }
  }

  err = esp_sleep_enable_timer_wakeup(15 * 1000 * 1000);
  LOG_ERROR(err, TIMER_WAKE);
  err = esp_sleep_enable_gpio_wakeup();
  LOG_ERROR(err, SLEEP_ENABLE);
}

void Button_Handler::ReadWakeupCause()
{
  esp_sleep_wakeup_cause_t wakeupCause = esp_sleep_get_wakeup_cause();
  switch(wakeupCause)
  {
    case ESP_SLEEP_WAKEUP_GPIO:
      printf("woke from gpio\n");
      break;
    case ESP_SLEEP_WAKEUP_TIMER:
      printf("woke from timer.\n");
      break;
    default:
      printf("Woke from %d\n", wakeupCause);
      break;
  }
}

void Button_Handler::HandleButtonWakeup()
{
  // Read which buttons have changed

}

void Button_Handler::HandleButtonEvent(const ButtonData& data)
{
  // Handle what to do after button event
}



