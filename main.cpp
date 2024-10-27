#include "BalanceBinarySearchTree.h"
#include <functional>
#include <iostream>
class AB{
    bool compare(AB& a, AB& b){
        return true;
    }
};
template<typename Compare = std::function<bool(const int&, const int&)>>
class Sample{
    Compare comp;
};
int main(int argc, char const *argv[])
{
    MeowComputationalGeometry::BalanceBinarySearchTree<int> tree;
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(-30);
    tree.insert(10);

    tree.print();
    // MeowComputationalGeometry::BalanceBinarySearchTree<AB> bstt;
    /* code */
    return 0;
}