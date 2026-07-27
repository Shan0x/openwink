#include "Buttons/Button.h"
#include "Buttons/Button_Handler.h"
#include "Configuration/GPIO_Config.h"

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

/////////////////////////////////////////////////
/// Main entry point for the open wink module 
/////////////////////////////////////////////////
extern "C" void app_main(void) 
{
    // Setup GPIO
    GPIO_Config::Initialize_GPIO_Configs();

    // Setup Buttons and wakeup sources
    Button_Handler buttonHandler;
    buttonHandler.ReadOnWakeup();

    esp_deep_sleep_start();

    // Initalize BLE 
    // Initialize Display
    // StartTasks

}