#include "Segment.h"

namespace MeowComputationalGeometry
{
    Segment::Segment(std::vector<int> &upperPt, std::vector<int> &lowerPt)
        : _endpoints(std::vector<std::vector<int>>{upperPt, lowerPt})
    {
    }
}