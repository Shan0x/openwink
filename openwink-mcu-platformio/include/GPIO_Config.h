#ifndef __GPIO_CONF_H
#define __GPIO_CONF_H

/// @brief Description:
/// Handles the configuration of the
/// GPIO pins for the ESP32 board.
class GPIO_Config {
public:
  static void Initialize_GPIO_Configs();

protected:
  static void OutputsConf();
  static void InputsConf();

private:
};

#endif // __GPIO_CONF_H