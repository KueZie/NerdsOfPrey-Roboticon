#include "subsystems/Climber.h"

Climber* Climber::m_Instance = nullptr;

Climber::Climber() : Subsystem("ExampleSubsystem")
{}

Climber* Climber::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new Climber();
  return m_Instance;
}
