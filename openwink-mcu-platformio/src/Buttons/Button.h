#ifndef __BUTTON_H
#define __BUTTON_H

#include <cstdint>

#include "../globals.h"

class Button
{
    public:
        Button();
        Button(gpio_num_t gpioPin, bool active);
        ~Button();

        bool IsDirty();
        bool IsCustomCommandActive() const;
        void SetMainTimer(std::uint64_t time);
        void SetButtonTimer(std::uint64_t time);
        bool IsInstalled();
        void ConfigureWakeup();

        gpio_num_t GetGpioPin() const;
        std::uint64_t GetMainTimer();
        std::uint16_t GetState() const;
        std::uint16_t buttonPressCounter_; //

    protected:
        std::uint64_t mainTimer_;          //
        std::uint64_t buttonTimer_;        //
        std::uint16_t wakeupButtonState_;  // Previous state of button
        std::uint16_t currentButtonState_; // Current state of button
        bool          customCommandActive_;//

        void SetDefaultCommand();
        void SetCustomCommand();
        void EnableCustomCommand(bool state);
        // Update the wakeup condition for this button
        void EnableButton(bool state);
        // Handle what a single press does
        void SinglePress();
        // Handle what a double press does
        void DoublePress();
        // Handle what multipe presses does
        void MultiPress();

    private:
        gpio_num_t gpioPin_;
        bool installed_;
};

#endif // __BUTTON_H