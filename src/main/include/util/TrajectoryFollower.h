#pragma once

#include <pathfinder.h>

#include "util/Trajectory.h"

class TrajectoryFollower
{
public:
    bool isFinished();
    TrajectoryFollower(Trajectory* trajectory);
    
private:
    unsigned int m_CurrentSegmentIndex = 0;
    Segment m_CurrentSegment;
};