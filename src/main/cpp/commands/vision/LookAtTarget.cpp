#include "commands/vision/LookAtTarget.h"

LookAtTarget::LookAtTarget()
{
  Requires(Drivetrain::GetInstance());
  Requires(Vision::GetInstance());
}

// Called just before this Command runs the first time
void LookAtTarget::Initialize() 
{}

// Called repeatedly when this Command is scheduled to run
void LookAtTarget::Execute()
{
  using namespace constants::vision::limelight;
  m_CurrentError = Vision::GetInstance()->GetLimelight()->GetHorizontalOffsetFromTarget();
  double turnPower = m_CurrentError * steering::turning::kP;
  Drivetrain::GetInstance()->Arcade(0.0f, turnPower);
}

// Make this return true when this Command no longer needs to run execute()
bool LookAtTarget::IsFinished()
{
  if (m_CurrentError < constants::vision::limelight::MAXIMUM_OFFSET_ERROR)
    return true;
  return false;
}

// Called once after isFinished returns true
void LookAtTarget::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LookAtTarget::Interrupted() {}
