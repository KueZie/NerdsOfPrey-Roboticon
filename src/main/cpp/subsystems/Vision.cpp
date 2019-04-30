#include "subsystems/Vision.h"

Vision* Vision::m_Instance = nullptr;

Vision::Vision() : Subsystem("ExampleSubsystem")
{
  m_Limelight = std::make_shared<Limelight>("limelight");
  m_Limelight->SetCam(Limelight::CAM_MODE::VISION_PROCESSING);
  m_Limelight->SetLEDs(Limelight::LED_MODE::ON);
  m_Limelight->SetPipeline(0);
}

Vision* Vision::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new Vision();
  return m_Instance;
}

// Returns custom Limelight wrapper available in util
std::shared_ptr<Limelight> Vision::GetLimelight()
{
  return m_Limelight;
}

void Vision::InitDefaultCommand()
{}