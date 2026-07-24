#include "GPIO_Config.h"
#include "../globals.h"
#include "driver/gpio.h"
#include "esp_sleep.h"

// Outputs from the ESP
void GPIO_Config::ConfigureOutputs() {
  gpio_config_t outputs = {
      .pin_bit_mask = (1ULL << OUT_PIN_LEFT_DOWN) |
                      (1ULL << OUT_PIN_LEFT_UP) |
                      (1ULL << OUT_PIN_RIGHT_DOWN) |
                      (1ULL << OUT_PIN_RIGHT_UP),
      .mode = GPIO_MODE_OUTPUT,
      .pull_up_en = GPIO_PULLUP_DISABLE,
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
      .intr_type = GPIO_INTR_DISABLE};

  ESP_ERROR_CHECK(gpio_config(&outputs));
}

// Inputs into the ESP
void GPIO_Config::ConfigureInputs() {
  gpio_config_t inputs = {
    .pin_bit_mask = (1ULL << OEM_BUTTON_INPUT) |
                    (1ULL << OEM_HEADLIGHT_STATUS_RIGHT) |
                    (1ULL << OEM_HEADLIGHT_STATUS_LEFT),
    .mode = GPIO_MODE_INPUT,
    .pull_up_en = GPIO_PULLUP_DISABLE,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .intr_type = GPIO_INTR_DISABLE};

  ESP_ERROR_CHECK(gpio_config(&inputs));
}

void GPIO_Config::Initialize_GPIO_Configs() {
  ConfigureInputs();
  ConfigureOutputs();
}