#ifndef __GLOBALS_H
#define __GLOBALS_H

#include "driver/gpio.h"
#include "esp_sleep.h"
#include <array>
#include <string>
#include <vector>

// Outputs for headlight movement
#define OUT_PIN_LEFT_DOWN GPIO_NUM_10
#define OUT_PIN_LEFT_UP GPIO_NUM_11
#define OUT_PIN_RIGHT_DOWN GPIO_NUM_12
#define OUT_PIN_RIGHT_UP GPIO_NUM_13

// OEM Wiring inputs to detect intial state of headlights
#define OEM_BUTTON_INPUT GPIO_NUM_9

// Headlight feedback pins
#define OEM_HEADLIGHT_STATUS_LEFT GPIO_NUM_3
#define OEM_HEADLIGHT_STATUS_RIGHT GPIO_NUM_46

#define SLEEP_TIME_US 15 * 1000 * 1000
#define AWAKE_TIME_DEFAULT_MS 1.5 * 1000
#define AWAKE_TIME_INTR_MS 5 * 60 * 1000

#define BUTTON_DEBOUNCE_US 50 * 1000

using namespace std;

enum HEADLIGHT_COMMAND
{
    NO_ACTION = -1,
    MOVE_TO_BUTTON,
    BOTH_UP,
    BOTH_DOWN,
    BOTH_BLINK,
    LEFT_UP,
    LEFT_DOWN,
    LEFT_WINK,
    RIGHT_UP,
    RIGHT_DOWN,
    RIGHT_WINK,
    WAVE_LEFT,
    WAVE_RIGHT,
    SLEEPY,
};

typedef struct CustomCommand
{
    vector<HEADLIGHT_COMMAND> commands;
} CustomCommand;

class Settings
{
    public:
    static gpio_num_t LEFT_DOWN_OUT;
    static gpio_num_t LEFT_UP_OUT;
    static gpio_num_t RIGHT_DOWN_OUT;
    static gpio_num_t RIGHT_UP_OUT;
    static gpio_num_t BUTTON_INPUT;
    static gpio_num_t HEADLIGHT_STATUS_LEFT;
    static gpio_num_t HEADLIGHT_STATUS_RIGHT;

    static int16_t multi_press_timeout;
    static bool custom_press_enabled;
    static bool bypass_headlight_restriction;

    static float wave_move_delay;

    static float left_sleepy_percentage;
    static float right_sleepy_percentage;

    static array<CustomCommand, 10> button_press_responses;

    static int64_t left_move_time;
    static int64_t right_move_time;

    static void save_to_flash();
    static void load_from_flash();

    // static void init()
    // {
    // }
};


enum LEVEL
{
    LOW = 0,
    HIGH = 1,
};


enum WAVE_START_SIDE
{
    LEFT,
    RIGHT,
};

namespace ButtonConstants
{
    enum ButtonID {
      OEM_BUTTON = 0,       // OEM Button
      // CUSTOM_BUTTON_1,   // Future/Custom Button
      // CUSTOM_BUTTON_2,   // Future/Custom Button
      TOTAL_BUTTONS         // Total amount of Buttons
    };
}

#endif // __GLOBALS_H