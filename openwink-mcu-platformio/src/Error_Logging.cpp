#include "Error_Logging.h"

void LOG_ERROR(esp_err_t err, const char* errorTag)
{
    if (err != ESP_OK) {
    ESP_LOGE(errorTag, "%s", esp_err_to_name(err));
    }
}