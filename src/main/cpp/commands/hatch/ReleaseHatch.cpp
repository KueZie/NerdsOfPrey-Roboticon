#include "commands/hatch/ReleaseHatch.h"

ReleaseHatch::ReleaseHatch() {
  Requires(Hatch::GetInstance());
}

void ReleaseHatch::Initialize()
{
  Hatch::GetInstance()->Release();
}
