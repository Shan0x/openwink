#include "../include/Headlight_Commander.h"
#include "../include/globals.h"

#define HEADLIGHT_DOWN 0
#define HEADLIGHT_UP 1

bool Headlight_Commander::command(HEADLIGHT_COMMAND theCommand) {
    commandSuccess_ = false;
    switch (theCommand) {
        case BOTH_UP:
            break;
        case BOTH_DOWN:
            break;
        case BLINK:
            break;
        case LEFT_UP:
          commandSuccess_ = setLeftHeadlight(HEADLIGHT_UP);
          break;
        case LEFT_DOWN:
          commandSuccess_ = setLeftHeadlight(HEADLIGHT_DOWN);
          break;
        case RIGHT_DOWN:
            break;
        case RIGHT_UP:
            break;
        case RIGHT_WINK:
            break;
        case LEFT_WINK:
            break;
        case WAVE_LEFT:
            break;
        case WAVE_RIGHT:
            break;
        case SLEEPY:
            break;
        case NO_ACTION:
            break;
        default:
            // Do Nothing
            break;
    }
    return commandSuccess_;
}

bool Headlight_Commander::setLeftHeadlight(int state) {
  bool success = false;
  // set_gpio_level(LEFT_HEADLIGHT_PIN, state)
  // if no err, commandSuccess_ = true;
  return success;
}

bool Headlight_Commander::setRightHeadlight(int state) {
  bool success = false;
  // set_gpio_level(RIGHT_HEADLIGHT_PIN, state)
  // if no error, commandSuccess_ = true;
  return success;
}

bool Headlight_Commander::bothUp() {
  bool success = false;
  success = setLeftHeadlight(HEADLIGHT_UP);
  success = setRightHeadlight(HEADLIGHT_UP);
  return success;
}

bool Headlight_Commander::bothDown() {
  int success = false;
  success = setLeftHeadlight(HEADLIGHT_DOWN);
  success = setRightHeadlight(HEADLIGHT_DOWN);
  return success;
}

bool Headlight_Commander::blink() {
  bool success = false;
  // Start with both open
  success = bothUp();
  // Close
  success = bothDown();
  // Open
  success = bothUp();

  return success;
}
