#pragma once

#include <exception>

class TargetOutOfRange : public std::exception
{
public:
    const char* what() const throw ()
    {
        return "Given target was out of range.";
    }
};

class TunablePID
{
public:
    TunablePID(double kF, double kP, double kI, double kD, double dt);
    ~TunablePID();
    void SetConstraints(double min, double max);
    void SetTarget(double target);
    void SetProcess(double process);
    double Calculate();
private:
    double m_kF, m_kP, m_kI, m_kD, m_Min, m_Max, m_TimeStep; // Controller constants
    double m_ProcessVariable, m_Target, m_Error, m_Control;  // Controller variables
};