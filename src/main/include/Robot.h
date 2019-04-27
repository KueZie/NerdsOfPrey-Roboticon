#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/WPILib.h>

#include "OI.h"
#include "subsystems/Subsystems.h"

class Robot : public frc::TimedRobot {
public:
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

  static Arm*                    m_ArmSubsystem;
  static Cargo*                  m_CargoSubsystem;
  static Hatch*                  m_HatchSubsystem;
  static Climber*                m_ClimberSubsystem;
  static Drivetrain*             m_DrivetrainSubsystem;
  static HatchSlider*            m_HatchSliderSubsystem;
  static OI*                     m_OI;
  static PowerDistributionPanel* m_PDP;
};
