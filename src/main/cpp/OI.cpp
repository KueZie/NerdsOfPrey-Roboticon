/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

OI* OI::m_Instance = nullptr;

OI::OI() {
  m_Controller.reset( new frc::XboxController(constants::controls::CONTROLLER_ID) );
  m_ButtonBox.reset( new frc::Joystick(constants::controls::BUTTON_BOX_ID) );

  m_CargoInBtn.reset( new frc::JoystickButton(m_Controller.get(), constants::controls::CARGO_IN_BTN_ID) );
  m_CargoOutBtn.reset( new frc::JoystickButton(m_Controller.get(), constants::controls::CARGO_OUT_BTN_ID) );
  m_QuickStopBtn.reset( new frc::JoystickButton(m_Controller.get(), constants::controls::QUICK_STOP_BTN_ID ));
  m_AimToTarget.reset( new frc::JoystickButton(m_Controller.get(), constants::controls::AIM_TO_TARGET_BTN_ID ));

  m_CargoInBtn->WhenPressed(new CargoIn());
  m_CargoOutBtn->WhenPressed(new CargoOut());
  
}

OI* OI::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new OI();
  return m_Instance;
}