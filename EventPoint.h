#ifndef MEOW_CG_EVENT_POINT_H
#define MEOW_CG_EVENT_POINT_H

#include <vector>
#include "Segment.h"
namespace MeowComputationalGeometry
{

    // 自定义哈希函数
    struct EventPointHash
    {
        std::size_t operator()(const EventPoint &ep) const
        {
            // 简单的哈希函数，可以根据需要进行优化
            return std::hash<int>()(ep.x) ^ (std::hash<int>()(ep.y) << 1);
        }
    };

    struct EventPoint
    {
        union
        {
            const int x, y;
            const int _endpoint[2];
        };
        //  store the segments that upper endpoint on this pos
        std::vector<Segment> _segments;

        EventPoint(const std::vector<int> &endpoint);

        bool operator==(const EventPoint &other) const
        {
            return this == &other || this->_endpoint == other._endpoint;
        }
    };
}

#endif