#pragma once

#include <memory>
#include <frc/WPILib.h>
#include "Constants.h"
#include "commands/Commands.h"

class OI {
private:
  static OI* m_Instance;
  OI();
public:
  static OI* GetInstance();
  std::unique_ptr<frc::XboxController> m_Controller;
  std::unique_ptr<frc::Joystick> m_ButtonBox;

  std::unique_ptr<frc::JoystickButton> m_HatchBtn;
  std::unique_ptr<frc::JoystickButton> m_HatchSliderBtn;
  std::unique_ptr<frc::JoystickButton> m_CargoOutBtn;
  std::unique_ptr<frc::JoystickButton> m_CargoInBtn;
  std::unique_ptr<frc::JoystickButton> m_QuickStopBtn;
};
