#include "BalanceBinarySearchTree.h"
#include <iostream>

namespace MeowComputationalGeometry{

template <typename ElementType>
BalanceBinarySearchTreeNode<ElementType>::BalanceBinarySearchTreeNode(
    ElementType value,
    BalanceBinarySearchTreeNode *parent, 
    BalanceBinarySearchTreeNode *left, 
    BalanceBinarySearchTreeNode *right): _parent(parent), _left(left), _right(right), _value(value), height(1)
{
}

template<typename ElementType>
BalanceBinarySearchTreeNode<ElementType>::~BalanceBinarySearchTreeNode()
{
}

// 自定义默认比较函数
template<typename ElementType, typename Compare, typename Equal>
bool BalanceBinarySearchTree<ElementType, Compare, Equal>::defaultCompare(const ElementType& a, const ElementType& b) {
    return a < b;
}

template <typename ElementType, typename Compare, typename Equal>
bool BalanceBinarySearchTree<ElementType, Compare, Equal>::isEqual(const ElementType &a, const ElementType &b)
{
    return a == b;
}

template<typename ElementType, typename Compare, typename Equal>
int BalanceBinarySearchTree<ElementType, Compare, Equal>::getHeight(BalanceBinarySearchTreeNode<ElementType>* root) const
{
    return root == nullptr ? 0 : root->height;
}

template<typename ElementType, typename Compare, typename Equal>
int BalanceBinarySearchTree<ElementType, Compare, Equal>::getBalance(BalanceBinarySearchTreeNode<ElementType>* root) const
{
    if(root == nullptr){
        return 0;
    }
    return getHeight(root->_right) - getHeight(root->_left);
}

template<typename ElementType, typename Compare, typename Equal>
BalanceBinarySearchTreeNode<ElementType>* 
BalanceBinarySearchTree<ElementType, Compare, Equal>::insertNode(
    BalanceBinarySearchTreeNode<ElementType> * root, ElementType elem)
{
    if(root == nullptr){
        return new BalanceBinarySearchTreeNode(elem, root);
    }
    auto parent = root;
    if(_compare(root->_value, elem)){
        root->_right = insertNode(root->_right, elem);
    }
    else{
        root->_left = insertNode(root->_left, elem);
    }

    root->height = 1 + std::max(getHeight(root->_left), getHeight(root->_right));

    const int balance = getBalance(root);
    if(balance > 1 && _compare(root->_right->_value, elem)){
        return leftRotate(root);
    }
    else if(balance < -1 && _compare(elem, root->_left->_value)){
        return rightRotate(root);
    }
    else if(balance > 1 && _compare(elem, root->_right->_value)){
        auto node = rightRotate(root->_right);
        return leftRotate(root);
    }
    else if(balance < -1 && _compare(root->_left->_value, elem)){
        auto node = leftRotate(root->_left);
        return rightRotate(root);
    }

    return root;
}

template <typename ElementType, typename Compare, typename Equal>
BalanceBinarySearchTree<ElementType, Compare, Equal>::BalanceBinarySearchTree(Compare compare):root(nullptr), _compare(compare)
{
}

template<typename ElementType, typename Compare, typename Equal>
bool BalanceBinarySearchTree<ElementType, Compare, Equal>::isEmpty() const
{
    return root == nullptr;
}
template<typename ElementType, typename Compare, typename Equal>
void BalanceBinarySearchTree<ElementType, Compare, Equal>::insert(ElementType elem)
{
    if(isEmpty()){
        auto node = new BalanceBinarySearchTreeNode(elem);
        root = node;
    }
    else{
        insertNode(root, elem);
    }
}

template <typename ElementType, typename Compare, typename Equal>
BalanceBinarySearchTreeNode<ElementType>* 
BalanceBinarySearchTree<ElementType, Compare, Equal>::remove(NodeType* root, ElementType elem)
{
    if(root == nullptr){
        return root;
    }

    if(_equal(root->_value, elem)){
        NodeType* ret = nullptr;
        if(root->_left == nullptr || root->_right == nullptr){
            auto tmp = root->_left ? root->_left : root->_right;
            if(!tmp){
                tmp = root;
                root = nullptr;
            }
            else{
                *root = *tmp;
            }
            delete tmp;
        }
        else{
            NodeType* minNode = findMinNode(root->_right);
            root->_value = minNode->_value;
            root->_right = remove(root->_right, minNode->_value);
        }
    }
    else if(_compare(root->_value, elem)){
        root->_right = remove(root->_right, elem);
    }
    else{
        root->_left = remove(root->_left, elem);
    }
    if(!root){
        return root;
    }

    root->height = 1 + std::max(height(root->_left), height(root->_right));

    const int balance = getBalance(root);
    if(balance > 1 && _compare(root->_right->_value, elem)){
        return leftRotate(root);
    }
    else if(balance < -1 && _compare(elem, root->_left->_value)){
        return rightRotate(root);
    }
    else if(balance > 1 && _compare(elem, root->_right->_value)){
        auto node = rightRotate(root->_right);
        return leftRotate(root);
    }
    else if(balance < -1 && _compare(root->_left->_value, elem)){
        auto node = leftRotate(root->_left);
        return rightRotate(root);
    }

    return root;
}

template<typename ElementType, typename Compare, typename Equal>
void BalanceBinarySearchTree<ElementType, Compare, Equal>::inorder(NodeType * root, std::function<void(ElementType&)> visit)
{
    if(root == nullptr){
        return;
    }

    inorder(root->_left, visit);
    visit(root->_value);
    inorder(root->_right, visit);
}

template <typename ElementType, typename Compare, typename Equal>
BalanceBinarySearchTreeNode<ElementType>* 
BalanceBinarySearchTree<ElementType, Compare, Equal>::leftRotate(NodeType* root)
{
    if(root == nullptr){
        return root;
    }

    auto right = root->_right;
    auto rl = right->_left;
    auto parent = root->_parent;
    root->_right = rl;
    right->_left = root;
    root->_parent = right;
    right->_parent = parent;
    if(rl){
        rl->_parent = root;
    }
    if(parent == nullptr){
        this->root = right;
    }
    root->height = 1 + std::max(getHeight(root->_left), getHeight(root->_right));
    right->height = 1 + std::max(getHeight(right->_left), getHeight(right->_right));
    return right;
}

template <typename ElementType, typename Compare, typename Equal>
BalanceBinarySearchTreeNode<ElementType>* 
BalanceBinarySearchTree<ElementType, Compare, Equal>::rightRotate(NodeType* root)
{
    if(root == nullptr){
        return nullptr;
    }

    auto left = root->_left;
    auto lr = left->_right;
    auto parent = root->_parent;
    root->_left = lr;
    left->_right = root;
    root->_parent = left;
    left->_parent = parent;
    if(lr){
        lr->_parent = root;
    }
    if(parent == nullptr){
        this->root = left;
    }
    root->height = 1 + std::max(getHeight(root->_left), getHeight(root->_right));
    left->height = 1 + std::max(getHeight(left->_left), getHeight(left->_right));
    return left;
}

template <typename ElementType, typename Compare, typename Equal>
BalanceBinarySearchTreeNode<ElementType>* BalanceBinarySearchTree<ElementType, Compare, Equal>::findMinNode(NodeType *root) const
{
    while(root){
        if(!root->_left){
            return root;
        }
        root = root->_left;
    }
    return nullptr;
}

template<typename ElementType, typename Compare, typename Equal>
void BalanceBinarySearchTree<ElementType, Compare, Equal>::print()
{
    inorder(root, [](ElementType key){
        std::cout << key << ' ';
    });
    std::cout << std::endl;
}
}
