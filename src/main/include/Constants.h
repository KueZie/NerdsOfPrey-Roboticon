#pragma once


namespace constants
{
    constexpr double PI      = 3.14159265359f;
    constexpr int TIMEOUT_MS = 10;
    namespace controls
    {
        constexpr int CONTROLLER_ID        = 0;
        constexpr int BUTTON_BOX_ID        = 1;
        constexpr int THROTTLE_AXIS_ID     = 0;
        constexpr int ROTATION_AXIS_ID     = 1;
        constexpr int HATCH_SLIDER_BTN_ID  = 0;
        constexpr int HATCH_BTN_ID         = 0;
        constexpr int CARGO_IN_BTN_ID      = 0;
        constexpr int CARGO_OUT_BTN_ID     = 0;
        constexpr int QUICK_STOP_BTN_ID    = 1;
        constexpr int AIM_TO_TARGET_BTN_ID = 2;                                      
    }
    namespace drivetrain
    {
        constexpr float MAX_THROTTLE   = 0.5f;
        constexpr float MAX_TURN_SPEED = 0.2f;
        constexpr float DEADBAND       = 0.08f;
        constexpr float SENSITIVITY    = 0.3f;
        namespace left
        {
            constexpr int FRONT_MOTOR_ID  = 1;
            constexpr int MIDDLE_MOTOR_ID = 0;
            constexpr int BACK_MOTOR_ID   = 0;
        }
        namespace right
        {
            constexpr int FRONT_MOTOR_ID  = 2;
            constexpr int MIDDLE_MOTOR_ID = 0;
            constexpr int BACK_MOTOR_ID   = 0;
        }
    }
    namespace arm
    {
        constexpr int LEFT_MOTOR_ID             = 0;
        constexpr int RIGHT_MOTOR_ID            = 0;
        constexpr float ANGLE_CONVERSION_FACTOR = 0.0f;
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
        constexpr int MOTOR_ID     = 0;
        constexpr float MAX_OUTPUT = 0.5f;
    }
    namespace vision
    {
        // Standard units in the metric system
        constexpr float VISION_TARGET_HEIGHT = 0.0f;
        namespace limelight
        {
            constexpr float MAXIMUM_OFFSET_ERROR  = 0.5f;
            constexpr float MOUNTING_ANGLE        = 0.0f;
            constexpr float DISTANCE_FROM_FLOOR   = 0.0f;
            constexpr float DISTANCE_FROM_BUMPERS = 0.0f;
            const     float HORIZONTAL_FOV        = 1.0402162341886205f;
            const     float VERTICAL_FOV          = 0.7976154681614086f;
            namespace steering
            {
                namespace throttle
                {
                    constexpr float kF = 0.0f;
                    constexpr float kP = 0.0f;
                    constexpr float kI = 0.0f;
                    constexpr float kD = 0.0f;
                }
                namespace turning
                {
                    constexpr float kF = 0.0f;
                    constexpr float kP = 0.0f;
                    constexpr float kI = 0.0f;
                    constexpr float kD = 0.0f;
                }
            }
        }
    }
}