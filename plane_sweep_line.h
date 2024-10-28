#ifndef MEOW_COMPUTATIONAL_GEOMETRY_PLACE_SWEEP_LINE_H
#define MEOW_COMPUTATIONAL_GEOMETRY_PLACE_SWEEP_LINE_H

#include "BalanceBinarySearchTree.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include "EventPoint.h"
#include "Segment.h"

namespace MeowComputationalGeometry
{

    auto comp = [](EventPoint &a, EventPoint &b)
    {
        if (a._endpoint[1] == b._endpoint[1])
        {
            return a._endpoint[0] <= b._endpoint[0];
        }
        return a._endpoint[1] > b._endpoint[1];
    };

    class PlaneSweepLine
    {
    protected:
        std::priority_queue<EventPoint, std::vector<EventPoint>, decltype(comp)> events;
        /* data */
        BalanceBinarySearchTree<std::pair<int, int>> status;

        std::vector<Segment> _segments;

    public:
        PlaneSweepLine(std::vector<Segment> &segs);
        virtual ~PlaneSweepLine();

        void initializeEventsQueue();
    };
}

#endif