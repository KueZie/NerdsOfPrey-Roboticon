#include "commands/cargo/CargoOut.h"

CargoOut::CargoOut()
{
  Requires(&Cargo::GetInstance());
}

// Called once when the command executes
void CargoOut::Initialize() 
{
  Cargo::GetInstance().Out();
}
