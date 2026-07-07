#include "../include/Button_Handler.h"
#include "../include/GPIO_Config.h"

/////////////////////////////////////////////////
/// Main entry point for the open wink module 
/////////////////////////////////////////////////
extern "C" void app_main(void) 
{
    // Setup Logging

    // Setup GPIO pins
    GPIO_Config::Initialize_GPIO_Configs();

    // Setup Physical Buttons
    Button_Handler oem_Button(ButtonConstants::OEM_BUTTON); // Handles the state of the button
    // Button_Handler custom_Button(ButtonConstants::CUSTOM_BUTTON_1); // Example Handler for a future button

    // Initalize BLE
    // Initialize Display

    // StartTasks

}