#include "commands/hatchslider/ExtendHatchSlider.h"

ExtendHatchSlider::ExtendHatchSlider() {
  Requires(HatchSlider::GetInstance());
}

// Called once when the command executes
void ExtendHatchSlider::Initialize()
{
  HatchSlider::GetInstance()->Out();
}
