#include "subsystems/Climber.h"

Climber::Climber()
  : Subsystem("ExampleSubsystem")
{}

Climber& Climber::GetInstance()
{
  static Climber instance;
  return instance;
}
