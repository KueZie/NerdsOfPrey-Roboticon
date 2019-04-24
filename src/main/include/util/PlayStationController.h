#pragma once

#include <frc/WPILib.h>

class PlayStationController : public frc::Joystick
{
public:
    PlayStationController(const int id);
    std::unique_ptr<frc::JoystickButton> aBtn = std::make_unique<frc::JoystickButton>(new frc::JoystickButton(this, 0));
    std::unique_ptr<frc::JoystickButton> bBtn = std::make_unique<frc::JoystickButton>(new frc::JoystickButton(this, 1));
    std::unique_ptr<frc::JoystickButton> xBtn = std::make_unique<frc::JoystickButton>(new frc::JoystickButton(this, 2));
    std::unique_ptr<frc::JoystickButton> yBtn = std::make_unique<frc::JoystickButton>(new frc::JoystickButton(this, 3));

private:
    int m_ID;
};
