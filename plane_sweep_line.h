#include "BalanceBinarySearchTree.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include "EventPoint.h"

namespace MeowComputationalGeometry{

    auto comp = []( EventPoint& a, EventPoint& b) { 
        if(a.position[1] == b.position[1]){
            return a.position[0] <= b.position[0];
        }
        return a.position[1] > b.position[1]; 
    };

    class PlaneSweepLine
    {
    protected:
        std::priority_queue<EventPoint, std::vector<EventPoint>, decltype(comp)> events;
        /* data */
        BalanceBinarySearchTree<std::pair<int, int>> status;
    public:
        PlaneSweepLine(/* args */);
        virtual ~PlaneSweepLine();
    };
}