#include "util/TrajectoryFollower.h"

TrajectoryFollower::TrajectoryFollower(Trajectory* trajectory)
    : m_CurrentSegment(trajectory->segments[0])
{
    
}