#ifndef MEOW_COMPUTATIONAL_GEOMETRY_SEGMENT_H
#define MEOW_COMPUTATIONAL_GEOMETRY_SEGMENT_H

#include <vector>

namespace MeowComputationalGeometry
{
    struct Segment
    {
        std::vector<std::vector<int>> _endpoints;
        Segment(std::vector<int> &upperPt, std::vector<int> &lowerPt);
    };
}

#endif
