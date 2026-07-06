#ifndef __BUTTON_HANDLER_H
#define __BUTTON_HANDLER_H

#include "../include/RTC_ButtonData.h"
#include "../include/globals.h"

#include <cstdint>

#define BUTTON_PRESSED 1   // GPIO High
#define BUTTON_RELEASED 0  // GPIO Low

/// @brief Description:
/// Handles the logic and state of each button created.
class Button_Handler {
    public:
      // Constructor
      Button_Handler(ButtonConstants::ButtonID button);
      // Destructor
      ~Button_Handler();

      std::uint64_t GetMainTimer();
      std::uint64_t GetButtonTimer();
      std::uint16_t GetButtonPressCount();

  protected:
      // Reads the state of the button on start
      void ReadOnWakeup();

      // Returns true if on wakeup the state of the button differs
      //  from the last saved state.
      bool ButtonStateDiffers();

      // Return the persisted data of the selected button
      RTCData &GetButtonRTCData();

      std::uint64_t mainTimer_;             //
      std::uint64_t buttonTimer_;           //
      std::uint16_t buttonPressCounter_;    //
      std::uint16_t wakeupValue_;           // Wakeup state of button
      std::uint16_t inputValue_;            // Input state of button
      ButtonConstants::ButtonID selectedButton_; // The button that was pressed

    private:
      // Non-copy Constructor
      Button_Handler(const Button_Handler &) = delete;
      Button_Handler &operator=(const Button_Handler &) = delete;
};

#endif // __BUTTON_HANDLER_H