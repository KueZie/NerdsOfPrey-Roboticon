#include "subsystems/Vision.h"

Vision::Vision()
  : Subsystem("ExampleSubsystem"), m_Limelight("limelight")
{
  m_Limelight.SetCam(Limelight::CAM_MODE::VISION_PROCESSING);
  m_Limelight.SetLEDs(Limelight::LED_MODE::ON);
  m_Limelight.SetPipeline(0);
}

Vision& Vision::GetInstance()
{
  static Vision instance;
  return instance;
}

// Returns custom Limelight wrapper available in util
Limelight& Vision::GetLimelight()
{
  return m_Limelight;
}

void Vision::InitDefaultCommand()
{}