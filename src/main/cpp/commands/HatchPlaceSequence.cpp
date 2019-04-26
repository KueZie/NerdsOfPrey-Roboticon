#include "commands/HatchPlaceSequence.h"

HatchPlaceSequence::HatchPlaceSequence() {
  AddSequential(new ExtendHatchSlider());
  AddSequential(new frc::WaitCommand(0.2));
  AddSequential(new ReleaseHatch());
  AddSequential(new frc::WaitCommand(0.2));
  AddSequential(new ToggleHatchSlider());
}
