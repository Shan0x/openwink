#ifndef __GPIO_CONF_H
#define __GPIO_CONF_H

/// @brief Description:
/// Handles the configuration of the
/// GPIO pins for the ESP32 board.
class GPIO_Config {
public:
  static void Initialize_GPIO_Configs();
  static void SetupInput();

protected:
  static void ConfigureOutputs();
  static void ConfigureInputs();

private:
};

#endif // __GPIO_CONF_H