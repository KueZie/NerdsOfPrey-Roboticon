#include "commands/HatchGrabSequence.h"

HatchGrabSequence::HatchGrabSequence() {
  AddSequential(new ExtendHatchSlider());
  AddSequential(new frc::WaitCommand(0.2));
  AddSequential(new GrabHatch());
  AddSequential(new frc::WaitCommand(0.2));
  AddSequential(new ToggleHatchSlider());
}
