#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include <memory>
#include "Constants.h"

using DigitalInput = frc::DigitalInput;

class Arm : public frc::Subsystem
{
private:
  float m_Angle;
  int m_EncoderPosition;
  WPI_TalonSRX  m_LeftMotorMaster;
  WPI_VictorSPX m_RightMotorSlave;
  // DigitalInput  m_ZeroingLimitSwitch;
  Arm();
public:
  static Arm& GetInstance();
  ~Arm() {}
  float GetEncoderPosition();
  void ResetEncoderPosition();
  void SetAngle(double angle);
  float GetAngle();
};
