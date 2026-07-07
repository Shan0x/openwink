#ifndef __HEADLIGHT_COMMANDER_H
#define __HEADLIGHT_COMMANDER_H

#include "../include/globals.h"

/// @brief Description 
/// Manages what the headlights will do.
class Headlight_Commander
{
    public:
      Headlight_Commander(const Headlight_Commander &) = delete;
      Headlight_Commander &operator=(const Headlight_Commander &) = delete;
      Headlight_Commander(Headlight_Commander &&) = delete;
      Headlight_Commander &operator=(Headlight_Commander &&) = delete;

      static Headlight_Commander &getInstance();
      bool command(HEADLIGHT_COMMAND command);

    protected:
      bool setLeftHeadlight(int state);
      bool setRightHeadlight(int state);
      // Left Eye Commands
      bool leftUp();
      bool leftDown();
      bool leftWink();

      // Right Eye Commands
      bool rightUp();
      bool rightDown();
      bool rightWink();

      // Both Commands
      bool blink();
      bool bothDown();
      bool bothUp();
      bool bothSwap();
      bool waveHeadlights();

      // Sleepy Commands
      bool isSleepy();
      bool sleepyEye();
      bool sleepyReset();

      bool buttonInterrupt();
      bool setAllOff();

      bool commandSuccess_;

    private:
      Headlight_Commander() = default;
      ~Headlight_Commander() = default;
};

// Get the instance of the headlight manager
inline Headlight_Commander &Headlight_Commander::getInstance() {
  static Headlight_Commander instance;
  return instance;
}

#endif // __HEADLIGHT_COMMANDER_H