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

class Drivetrain : public frc::Subsystem
{
private:
  // Master controllers
  WPI_TalonSRX  m_FrontLeftMotorMaster;
  WPI_TalonSRX  m_FrontRightMotorMaster;
  // Slave controllers
  WPI_VictorSPX m_MiddleLeftMotorSlave;
  WPI_VictorSPX m_MiddleRightMotorSlave;

  WPI_VictorSPX m_BackLeftMotorSlave;
  WPI_VictorSPX m_BackRightMotorSlave;

  // Gyro
  AHRS m_AHRS;

  // Curvature drive variables
  double m_QuickStopAccumulator, m_OldWheel, m_IsQuickTurn;

  Drivetrain(); // Prevent instantiation outside of this class
  double CurvatureSinScalar(double wheelNonLinearity, double wheel);
public:
  static Drivetrain& GetInstance();
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
  ~Drivetrain() {}
};
