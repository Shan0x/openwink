#include "Button.h"
#include <esp_err.h>
#include "../Error_Logging.h"

Button::Button()
{
    // Default Constructor
}

Button::Button(gpio_num_t gpioPin, bool active)
    : buttonPressCounter_(0)
    , mainTimer_(0)
    , buttonTimer_(0)
    , wakeupButtonState_(0)
    , currentButtonState_(0)
    , customCommandActive_(false)
    , gpioPin_(gpioPin)
    , isActive_(active)
{

}
Button::~Button()
{
    // Empty
}
void Button::EnableCustomCommand(bool state)
{
    customCommandActive_ = state;
}

bool Button::IsCustomCommandActive() const
{
    return customCommandActive_;
}

inline std::uint16_t Button::GetState() const
{
    return gpio_get_level(gpioPin_);
}

gpio_num_t Button::GetGpioPin() const
{
    return gpioPin_;
}

std::uint64_t Button::GetMainTimer()
{
    return mainTimer_;
}

void Button::SetMainTimer(std::uint64_t time)
{
    mainTimer_ = time;
}

void Button::SetButtonTimer(std::uint64_t time)
{
    buttonTimer_ = time;
}

bool Button::IsDirty()
{
    return wakeupButtonState_ != currentButtonState_;
}

bool Button::IsActive()
{
    return isActive_;
}

void Button::EnableButton(bool state)
{
    isActive_ = state;
}

void Button::UpdateButtonWakeup()
{
    esp_err_t err = gpio_wakeup_enable(
        gpioPin_,
        GetState() == BUTTON_PRESSED ? 
        GPIO_INTR_LOW_LEVEL : GPIO_INTR_HIGH_LEVEL);
    LOG_ERROR(err, GPIO_UPDATE);
}