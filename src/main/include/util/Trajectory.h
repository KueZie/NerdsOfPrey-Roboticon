#pragma once

#include "pathfinder.h"

struct Trajectory
{
    Segment* segments;
    unsigned int length;
    Trajectory(TrajectoryCandidate& preparedTrajectoryCandidate);
    ~Trajectory();
};