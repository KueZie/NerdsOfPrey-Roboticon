/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <WPILib.h>
#include <memory>
#include "Constants.h"

using DigitalInput = frc::DigitalInput;

class Arm : public frc::Subsystem {
private:
  int m_Angle;
  int m_EncoderPosition;
  std::unique_ptr<TalonSRX> m_LeftMotorMaster;
  std::unique_ptr<VictorSPX> m_RightMotorSlave;
  std::unique_ptr<DigitalInput> m_ZeroingLimitSwitch;
  static Arm* m_Instance;
  Arm();
public:
  static Arm* GetInstance();
  ~Arm() { delete m_Instance; }
  float GetEncoderPosition();
};
