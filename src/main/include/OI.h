#pragma once

#include <memory>
#include <frc/WPILib.h>
#include "Constants.h"
#include "commands/Commands.h"

class OI {
private:
  OI();
public:
  static OI& GetInstance();
  frc::XboxController controller {constants::controls::CONTROLLER_ID};
  frc::Joystick buttonBox        {constants::controls::BUTTON_BOX_ID};

  frc::JoystickButton hatchBtn       {&controller, constants::controls::HATCH_BTN_ID};
  frc::JoystickButton hatchSliderBtn {&controller, constants::controls::HATCH_SLIDER_BTN_ID};
  frc::JoystickButton cargoOutBtn    {&controller, constants::controls::CARGO_OUT_BTN_ID};
  frc::JoystickButton cargoInBtn     {&controller, constants::controls::CARGO_IN_BTN_ID};
  frc::JoystickButton quickStopBtn   {&controller, constants::controls::QUICK_STOP_BTN_ID};
  frc::JoystickButton aimToTargetBtn {&controller, constants::controls::AIM_TO_TARGET_BTN_ID};
};
