#include "commands/hatch/ToggleHatch.h"

ToggleHatch::ToggleHatch() {
  Requires(Hatch::GetInstance());
}

void ToggleHatch::Initialize()
{
  Hatch::GetInstance()->Toggle();
}
