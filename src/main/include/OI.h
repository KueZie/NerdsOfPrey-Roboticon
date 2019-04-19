/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <memory>
#include <frc/WPILib.h>
#include "Constants.h"
#include "commands/Commands.h"

class OI {
public:
  std::unique_ptr<frc::Joystick> m_Controller;
  std::unique_ptr<frc::Joystick> m_ButtonBox;

  std::unique_ptr<frc::JoystickButton> m_HatchBtn;
  std::unique_ptr<frc::JoystickButton> m_HatchSliderBtn;
  std::unique_ptr<frc::JoystickButton> m_CargoOutBtn;
  std::unique_ptr<frc::JoystickButton> m_CargoInBtn;
  
  OI();
};
