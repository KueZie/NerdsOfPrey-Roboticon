#pragma once

#include <frc/WPILib.h>

class SimplePneumaticSubsystem : public frc::Subsystem
{
public:
    enum class State { OFF, FORWARD, REVERSE };
    SimplePneumaticSubsystem(const char* name)
        : Subsystem(name)
    {}
    virtual void Set(State state) = 0;
    virtual State GetState() = 0;
};