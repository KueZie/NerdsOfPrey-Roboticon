#include "commands/GrabHatch.h"

GrabHatch::GrabHatch() {
  Requires(Hatch::GetInstance());
}

void GrabHatch::Initialize()
{
  Hatch::GetInstance()->Grab();
}
