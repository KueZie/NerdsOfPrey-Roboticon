#include "commands/HatchGrabSequence.h"

HatchGrabSequence::HatchGrabSequence()
{
  using State = SimplePneumaticSubsystem::State;
  // AddSequential(new ActuatePneumatic(HatchSlider::GetInstance(), State::FORWARD));
  // AddSequential(new frc::WaitCommand(0.2));
  // AddSequential(new ActuatePneumatic(Hatch::GetInstance(), State::FORWARD));
  // AddSequential(new frc::WaitCommand(0.2));
  // AddSequential(new ActuatePneumatic(HatchSlider::GetInstance(), State::REVERSE));
}
