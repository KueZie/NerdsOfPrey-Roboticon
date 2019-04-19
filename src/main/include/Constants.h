#pragma once

namespace constants
{
    constexpr int TIMEOUT_MS = 10;
    namespace controls
    {
        constexpr int CONTROLLER_ID = 0;
        constexpr int BUTTON_BOX_ID = 1;
        constexpr int THROTTLE_AXIS_ID = 0;
        constexpr int ROTATION_AXIS_ID = 1;
        constexpr int HATCH_SLIDER_BTN_ID = 0;
        constexpr int HATCH_BTN_ID = 0;
        constexpr int CARGO_IN_BTN_ID = 0;
        constexpr int CARGO_OUT_BTN_ID = 0;
    }
    namespace drivetrain
    {
        constexpr float MAX_THROTTLE = 0.5f;
        constexpr float MAX_TURN_SPEED = 0.25f;
        namespace left
        {
            constexpr int FRONT_MOTOR_ID  = 0;
            constexpr int MIDDLE_MOTOR_ID = 0;
            constexpr int BACK_MOTOR_ID   = 0;
        }
        namespace right
        {
            constexpr int FRONT_MOTOR_ID  = 0;
            constexpr int MIDDLE_MOTOR_ID = 0;
            constexpr int BACK_MOTOR_ID   = 0;
        }
    }
    namespace arm
    {
        constexpr int LEFT_MOTOR_ID = 0;
        constexpr int RIGHT_MOTOR_ID = 0;
    }
    namespace hatch_intake
    {
        constexpr int SOLENOID_IDS[] = {0, 0};
    }
    namespace hatch_slider
    {
        constexpr int SOLENOID_IDS[] = {0, 0};
    }
    namespace cargo_intake
    {
        constexpr int MOTOR_ID = 0;
        constexpr float MAX_OUTPUT = 0.5f;
    }
}