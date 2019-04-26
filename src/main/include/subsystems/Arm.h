#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include <memory>
#include "Constants.h"

using DigitalInput = frc::DigitalInput;

class Arm : public frc::Subsystem {
private:
  float m_Angle;
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
  void ResetEncoderPosition();
  void SetAngle(double angle);
  float GetAngle();
};
