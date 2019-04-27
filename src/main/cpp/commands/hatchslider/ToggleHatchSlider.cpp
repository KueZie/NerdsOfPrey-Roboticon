#include "commands/hatchslider/ToggleHatchSlider.h"

ToggleHatchSlider::ToggleHatchSlider() {
  Requires(HatchSlider::GetInstance());
}

void ToggleHatchSlider::Initialize() 
{
  HatchSlider::GetInstance()->Toggle();
}
