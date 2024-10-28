#include "BalanceBinarySearchTree.h"
#include "plane_sweep_line.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <queue>

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
        std::unordered_map<std::vector<int>, EventPoint> eventsHash;
        auto handleEp = [&](std::vector<int> &endpoint, Segment &seg)
        {
            if (eventsHash.find(endpoint) == eventsHash.end())
            {
                eventsHash.insert({endpoint, EventPoint(endpoint)});
            }
            if (seg._endpoints[0] == endpoint)
            {
                auto &ep = eventsHash[endpoint];
                ep._segments.emplace_back(seg);
            }
        };

        for (auto &seg : _segments)
        {
            handleEp(seg._endpoints[0], seg);
            handleEp(seg._endpoints[1], seg);
        }

        for (const auto &[endpoint, event] : eventsHash)
        {
            events.push(event);
        }
    }
}