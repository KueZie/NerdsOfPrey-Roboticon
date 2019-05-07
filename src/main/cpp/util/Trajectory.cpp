#include "util/Trajectory.h"

Trajectory::Trajectory(TrajectoryCandidate& preparedTrajectoryCandidate)
{
    length = preparedTrajectoryCandidate.length;
    segments = (Segment*)malloc(sizeof(Segment) * length);
    pathfinder_generate(&preparedTrajectoryCandidate, segments);
}

Trajectory::~Trajectory()
{
    delete segments;
}