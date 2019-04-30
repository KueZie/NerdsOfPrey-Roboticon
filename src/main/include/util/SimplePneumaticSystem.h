#pragma once

#include <frc/WPILib.h>

class SimplePneumaticSystem
{
public:
    enum class State { OFF, FORWARD, REVERSE };
    SimplePneumaticSystem() {}
    virtual void Set(State state) = 0;
    virtual State GetState() = 0;
};