#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include <memory>
#include "Constants.h"
#include "util/Functions.h"
#include "commands/drivetrain/ArcadeDrive.h"
#include "commands/drivetrain/CurvatureDrive.h"
#include <iostream>

// TODOS
// Implement current and voltage draw method

class Drivetrain : public frc::Subsystem {
private:
  // Master controllers
  std::unique_ptr<TalonSRX>  m_FrontLeftMotorMaster;
  std::unique_ptr<TalonSRX>  m_FrontRightMotorMaster;
  // Slave controllers
  std::unique_ptr<VictorSPX> m_MiddleLeftMotorSlave;
  std::unique_ptr<VictorSPX> m_MiddleRightMotorSlave;

  std::unique_ptr<VictorSPX> m_BackLeftMotorSlave;
  std::unique_ptr<VictorSPX> m_BackRightMotorSlave;

  // Curvature drive variables
  double m_QuickStopAccumulator, m_OldWheel, m_IsQuickTurn;

  // Gyro
  std::unique_ptr<AHRS> m_AHRS;

  static Drivetrain* m_Instance;

  Drivetrain(); // Prevent instantiation outside of this class
  double CurvatureSinScalar(double wheelNonLinearity, double wheel);
public:
  static Drivetrain* GetInstance();
  void Arcade(float throttle, float rotationSpeed);
  void Tank(float left, float right);
  void Curvature(float throttle, float wheel);
  float ResolveDeadband(float power);
  void ResetEncoderPositions();
  void ResetGyro();
  void ResetSensors();
  void SetQuickTurn(bool quickTurn);
  bool IsQuickTurn();
  float GetYaw();
  float GetLeftEncoderPosition();
  float GetRightEncoderPosition();
  float GetCurrentDraw();
  float GetVoltage();
  float GetLeftPercentOutput();
  float GetRightPercentOutput();
  virtual void InitDefaultCommand() override;
  ~Drivetrain() { delete m_Instance; }
};
