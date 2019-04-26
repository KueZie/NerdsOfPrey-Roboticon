#include "commands/ToggleHatch.h"

ToggleHatch::ToggleHatch() {
  Requires(Hatch::GetInstance());
}

void ToggleHatch::Initialize()
{
  Hatch::GetInstance()->Toggle();
}
