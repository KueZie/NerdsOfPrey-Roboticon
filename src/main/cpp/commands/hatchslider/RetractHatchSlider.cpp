#include "commands/hatchslider/RetractHatchSlider.h"

RetractHatchSlider::RetractHatchSlider() {
  Requires(HatchSlider::GetInstance());
}

// Called once when the command executes
void RetractHatchSlider::Initialize()
{
  HatchSlider::GetInstance()->In();
}
