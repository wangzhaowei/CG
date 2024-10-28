#include <vector>

class Segment;
struct EventPoint
{
    /* data */
    std::vector<int> position;
    std::vector<std::vector<int>> segments;
};
