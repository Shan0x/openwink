#include "RTC_ButtonData.h"

// TODO: Find a better spot for this?
// Maybe other non-volatile/persisted data can live here.
RTC_DATA_ATTR RTCData rtc_buttonData[MAX_BUTTONS] = {};