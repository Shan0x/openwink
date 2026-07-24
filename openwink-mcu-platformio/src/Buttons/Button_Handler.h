#ifndef __BUTTON_HANDLER_H
#define __BUTTON_HANDLER_H

// Library includes
#include <cstdint>

// Class includes
#include "../globals.h"
#include "Button.h"

// Defines
#define BUTTON_OFF 0  // GPIO Low
#define BUTTON_ON 1   // GPIO High

// Forward declarations


/// @brief Description:
/// Handles the logic and state of a button.
class Button_Handler {
    public:
      // Constructor
      Button_Handler();
      // Destructor
      ~Button_Handler();
      void AddButton(gpio_num_t gpioPin, bool active);
      void ReadOnWakeup();

      Button buttons_[MAX_BUTTONS];
      size_t buttonCount_;

    protected:
      void HandleButtonEvent(const ButtonEvent& event);
      uint64_t debounceTimer_;

    private:
      // Non-copy Constructor
      Button_Handler(const Button_Handler &) = delete;
      Button_Handler &operator=(const Button_Handler &) = delete;
};

#endif // __BUTTON_HANDLER_H