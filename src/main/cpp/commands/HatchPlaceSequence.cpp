#include "commands/HatchPlaceSequence.h"

HatchPlaceSequence::HatchPlaceSequence()
{
  using State = SimplePneumaticSystem::State;
  AddSequential(new ActuatePneumatic(HatchSlider::GetInstance(), State::FORWARD));
  AddSequential(new frc::WaitCommand(0.2));
  AddSequential(new ActuatePneumatic(Hatch::GetInstance(), State::REVERSE));
  AddSequential(new frc::WaitCommand(0.2));
  AddSequential(new ActuatePneumatic(HatchSlider::GetInstance(), State::REVERSE));
}
