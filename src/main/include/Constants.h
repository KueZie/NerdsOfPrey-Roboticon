#pragma once

namespace constants
{
    constexpr int timeout = 1;
    namespace drivetrain
    {
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
    namespace hatch_intake
    {
        constexpr int SOLENOID_IDS[] = {0, 0};
    }
    namespace cargo_intake
    {
        constexpr int MOTOR_ID = 0;
        constexpr float MAX_OUTPUT = 0.5f;
    }
}