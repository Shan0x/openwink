#include "Eye.h"
#include "esp_check.h"
#include "../globals.h"

Eye::Eye()
{
    // Default Constructor
}

Eye::Eye(gpio_num_t upPin, gpio_num_t downPin)
{
    upPin_ = upPin;
    downPin_ = downPin;
}

esp_err_t Eye::Open()
{
    // If the headlight is already open
    if (GetCurrentState() == EyeState::OPEN)
    {
        // Start with the headlight closed
        Close();
    }

    // Open headlight
    ESP_RETURN_ON_ERROR(gpio_set_level(upPin_, PinLevel::HIGH), "OpenEye", "Failed to set up pin high");
    ESP_RETURN_ON_ERROR(gpio_set_level(downPin_, PinLevel::LOW), "OpenEye", "Failed to set Down pin low");

    return ESP_OK;
}

esp_err_t Eye::Close()
{
    // If the headlight is already closed
    if (GetCurrentState() == EyeState::CLOSED)
    {
        // Start with the headlight open
        Open();
    }
    
    // Close headlight
    ESP_RETURN_ON_ERROR(gpio_set_level(upPin_, PinLevel::LOW), "CloseEye", "Failed to set up pin low");
    ESP_RETURN_ON_ERROR(gpio_set_level(downPin_, PinLevel::HIGH), "CloseEye", "Failed to set down pin high");

    return ESP_OK;
}

EyeState Eye::GetCurrentState()
{
    int upPinLevel = gpio_get_level(upPin_);
    int downPinLevel = gpio_get_level(downPin_);

    EyeState state;

    if (upPinLevel == PinLevel::HIGH && downPinLevel == PinLevel::LOW)
    {
        // Eye is open
        state = EyeState::OPEN;
    }
    
    if (upPinLevel == PinLevel::LOW && downPinLevel == PinLevel::HIGH)
    {
        // Eye is closed
        state = EyeState::CLOSED;
    }
    
    return state;
}

void Eye::SetInitialState()
{
    initialState_ = GetCurrentState();
}

EyeState Eye::GetInitialState()
{
    return initialState_;
}