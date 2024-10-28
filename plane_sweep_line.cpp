#include "BalanceBinarySearchTree.h"
#include "plane_sweep_line.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

namespace MeowComputationalGeometry
{
    PlaneSweepLine::PlaneSweepLine(std::vector<Segment> &segs)
        : events(comp), status(), _segments(segs)
    {
    }

    PlaneSweepLine::~PlaneSweepLine()
    {
    }

    void PlaneSweepLine::initializeEventsQueue()
    {
    }

    Segment::Segment(std::vector<int> &upperPt, std::vector<int> &lowerPt)
        : _endpoints(std::vector<std::vector<int>>{upperPt, lowerPt})
    {
    }
}