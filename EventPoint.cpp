#include "EventPoint.h"

MeowComputationalGeometry::EventPoint::EventPoint(std::vector<int> &endpoint)
    : _endpoint({endpoint[0], endpoint[1]})
{
}