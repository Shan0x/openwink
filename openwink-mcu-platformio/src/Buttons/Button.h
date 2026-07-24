#ifndef __BUTTON_H
#define __BUTTON_H

#include <cstdint>

#include "../globals.h"

enum ButtonEventType
{
    BUTTON_PRESSED,
    BUTTON_RELEASED
};

struct ButtonEvent
{
    int buttonId;
    ButtonEventType type;
}; 

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
        bool IsActive();
        void UpdateButtonWakeup();

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
        void EnableButton(bool state);
        void SinglePress();
        void DoublePress();
        void TriplePress();

    private:
        gpio_num_t gpioPin_;
        bool isActive_;
};

#endif // __BUTTON_H