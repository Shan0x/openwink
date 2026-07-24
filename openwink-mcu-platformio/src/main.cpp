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

    // Setup Button Handler and Buttons
    Button_Handler buttonHandler;

    //  Setup wakeup sources
    buttonHandler.ReadOnWakeup();

    // Initalize BLE 
    // Initialize Display
    // StartTasks

}