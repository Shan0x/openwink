#include "Eye_Manager.h"

#include "../globals.h"
#include "../Error_Logging.h"

Eye_Manager::Eye_Manager()
{
    leftEye_ = Eye(OUT_PIN_LEFT_UP, OUT_PIN_LEFT_DOWN);
    rightEye_ = Eye(OUT_PIN_RIGHT_UP, OUT_PIN_RIGHT_DOWN);
}



EyeState Eye_Manager::GetInitialState(Eye& eye)
{
    return eye.GetCurrentState();
}

void Eye_Manager::DoInitialState(Eye& eye)
{
    if (eye.GetInitialState() != eye.GetCurrentState())
    {
        switch(eye.GetInitialState())
        {
            case EyeState::CLOSED:
                eye.Close();
                break;
            case EyeState::OPEN:
                eye.Open();
                break;
            default:
                break;
        }        
    }
}

void Eye_Manager::LeftOpen()
{
    esp_err_t err = leftEye_.Open();
    LOG_ERROR(err, LEFT_OPEN);
}

void Eye_Manager::LeftClose()
{
    esp_err_t err = leftEye_.Close();
    if (err != ESP_OK)
    LOG_ERROR(err, LEFT_CLOSE);
}

void Eye_Manager::LeftWink()
{
    LeftOpen();
    RightClose();
}

void Eye_Manager::RightOpen()
{
    esp_err_t err = rightEye_.Open();
    LOG_ERROR(err, RIGHT_OPEN);
}

void Eye_Manager::RightClose()
{
    esp_err_t err = rightEye_.Close();
    LOG_ERROR(err, RIGHT_CLOSE);
}

void Eye_Manager::RightWink()
{
    rightEye_.SetInitialState();
    RightClose();
    RightOpen();
    DoInitialState(rightEye_);
}

void Eye_Manager::OpenBoth()
{
    RightOpen();
    LeftOpen();
}

void Eye_Manager::HandleCommand(HeadlightCommand theCommand) {
    switch (theCommand) {
        case HeadlightCommand::BOTH_UP:
            OpenBoth();
            break;
        case HeadlightCommand::BOTH_DOWN:
            break;
        case HeadlightCommand::BLINK:
            break;
        case HeadlightCommand::LEFT_UP:
            LeftOpen();
            break;
        case HeadlightCommand::LEFT_DOWN:
            RightOpen();
            break;
        case HeadlightCommand::RIGHT_DOWN:
            break;
        case HeadlightCommand::RIGHT_UP:
            break;
        case HeadlightCommand::RIGHT_WINK:
            break;
        case HeadlightCommand::LEFT_WINK:
            break;
        case HeadlightCommand::WAVE_LEFT:
            break;
        case HeadlightCommand::WAVE_RIGHT:
            break;
        case HeadlightCommand::SLEEPY:
            break;
        case HeadlightCommand::NO_ACTION:
            break;
        default:
            // Do Nothing
            break;
    }
}