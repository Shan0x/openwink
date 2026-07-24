#ifndef __EYE_H
#define __EYE_H

#include "driver/gpio.h"
#include <esp_err.h>

enum EyeState
{
    CLOSED = 0,
    OPENING,
    OPEN,
    CLOSING,
    STOPPED
};

// This is a single eye/headlight
class Eye
{
    public:

        /// @brief Initialize an "eye" (headlight)
        /// @param upPin The out pin representing an open eye
        /// @param downPin The out pin representing a closed eye
        Eye(gpio_num_t upPin, gpio_num_t downPin);

        /// @brief Default Constructor
        Eye();

        /// @brief Opens a headlight
        /// @return Success if headlight successfully opened
        esp_err_t Open();

        /// @brief Closes a headlight
        /// @return Success on headlight close
        esp_err_t Close();

        EyeState GetCurrentState();
        EyeState GetInitialState();
        void SetInitialState();
        
    protected:

    private:
        gpio_num_t upPin_;
        gpio_num_t downPin_;
        EyeState initialState_;
};

#endif // __EYE_H