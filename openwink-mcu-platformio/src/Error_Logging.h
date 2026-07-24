#ifndef __ERROR_LOGGING
#define __ERROR_LOGGING

#include "globals.h"
#include "esp_log.h"

#define BLE_FAILED "BLE failed"
#define BUTTON_FAILED "Button failed"
#define GPIO_WAKE "GPIO Failed"
#define GPIO_UPDATE "Updaate Button Wakeup failed"
#define DISABLE_WAKE "GPIO Failed"
#define TIMER_WAKE "GPIO Failed"
#define INIT_FAILED "Initialization failed"
#define INPUT_FAILED "Input failed"
#define OUTPUT_FAILED "Output failed"
#define LEFT_OPEN "Failed to open left eye"
#define LEFT_CLOSE "Failed to close left eye"
#define RIGHT_OPEN "Failed to open right eye"
#define RIGHT_CLOSE "Failed to close right eye"

void LOG_ERROR(esp_err_t err, const char *errorTag);

#endif // __ERROR_LOGGING