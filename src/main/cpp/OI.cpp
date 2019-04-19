/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

OI::OI() {
  m_Controller.reset( new frc::Joystick(constants::controls::CONTROLLER_ID) );
  m_ButtonBox.reset( new frc::Joystick(constants::controls::BUTTON_BOX_ID) );

}
