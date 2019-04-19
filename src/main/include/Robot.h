/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "OI.h"
#include "subsystems/Arm.h"
#include "subsystems/Cargo.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Hatch.h"
#include "subsystems/HatchSlider.h"

class Robot : public frc::TimedRobot {
public:
  //Arm* m_ArmSystem;
  /*static Cargo       m_CargoSystem     = Cargo::GetInstance();
  static Hatch       m_HatchSystem       = Hatch::GetInstance();
  static Drivetrain  m_DrivetrainSystem  = Drivetrain::GetInstance();
  static HatchSlider m_HatchSliderSystem = HatchSlider::GetInstance();
  static OI          m_OI                = OI::GetInstance();*/

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc::Command* m_autonomousCommand = nullptr;
  frc::SendableChooser<frc::Command*> m_chooser;
};
