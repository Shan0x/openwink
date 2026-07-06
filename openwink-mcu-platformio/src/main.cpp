#include "../include/GPIO_Config.h"
#include "../include/ButtonHandler.h"

/////////////////////////////////////////////////
/// Main entry point for the open wink module 
/////////////////////////////////////////////////
extern "C" void app_main(void) 
{
    // Setup GPIO pins
    GPIO_Config::Initialize_GPIO_Configs();

    // Initialize Buttons
    // Enable wakeup sources on startup; By default enables both GPIO wakeup AND Timer wakeup
    Button_Handler oem_Button(ButtonConstants::OEM_BUTTON);

}