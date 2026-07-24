#ifndef __EYE_MANAGER_H
#define __EYE_MANAGER_H

#include "../globals.h"
#include "Eye.h"

/// @brief Description 
/// Manages what the headlights will do.
class Eye_Manager
{
    public:
        Eye_Manager();
        ~Eye_Manager();
        static Eye_Manager &getInstance();
        void HandleCommand(HeadlightCommand theCommand);

    protected:
      // Left Eye Commands
      void LeftOpen();
      void LeftClose();
      void LeftWink();

      // Right Eye Commands
      void RightOpen();
      void RightClose();
      void RightWink();

      // Both Commands
      void Blink();
      void CloseBoth();
      void OpenBoth();
      void SwapBoth();
      void WaveHeadlights();

      // Sleepy Commands
      void IsSleepy();
      void SleepyEye();
      void SleepyReset();

      void ButtonInterrupt();
      void SetAllOff();

      EyeState GetInitialState(Eye& eye);
      void DoInitialState(Eye& eye);

      bool commandSuccess_;

    private:
        Eye leftEye_;
        Eye rightEye_;
};

#endif // __Eye_Manager_H