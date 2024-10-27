#ifndef BALANCEBINARYSEARCHTREE_H
#define BALANCEBINARYSEARCHTREE_H

#include <functional>
#include <memory>

namespace MeowComputationalGeometry{
    template<typename ElementType>
    struct BalanceBinarySearchTreeNode
    {
        BalanceBinarySearchTreeNode* _parent = nullptr;
        BalanceBinarySearchTreeNode* _left = nullptr;
        BalanceBinarySearchTreeNode* _right = nullptr;
        ElementType _value;
        int height = 1;
        BalanceBinarySearchTreeNode(
            ElementType value,
            BalanceBinarySearchTreeNode* parent = nullptr, 
            BalanceBinarySearchTreeNode* left = nullptr,
            BalanceBinarySearchTreeNode* right = nullptr
            );

        virtual ~BalanceBinarySearchTreeNode();
    };

    template<
    typename ElementType, 
    typename Compare = std::function<bool(const ElementType&, const ElementType&)>,
    typename Equal = std::function<bool(const ElementType&, const ElementType&)>
    >
    class BalanceBinarySearchTree{

        using NodeType = BalanceBinarySearchTreeNode<ElementType>;

        protected:
        BalanceBinarySearchTreeNode<ElementType>* root = nullptr;

        Compare _compare = defaultCompare;
        Equal _equal = isEqual;
        // 自定义默认比较函数
        static bool defaultCompare(const ElementType& a, const ElementType& b);
        static bool isEqual(const ElementType& a, const ElementType& b);

        int getHeight(BalanceBinarySearchTreeNode<ElementType>* root) const;
        int getBalance(BalanceBinarySearchTreeNode<ElementType>* root) const;

        BalanceBinarySearchTreeNode<ElementType>* insertNode(BalanceBinarySearchTreeNode<ElementType>* root, ElementType elem);

        void inorderTraversal(NodeType* root, std::function<void(ElementType& node)> visit);

        NodeType* leftRotate(NodeType* root);
        NodeType* rightRotate(NodeType* root);

        public:
        BalanceBinarySearchTree(Compare compare = defaultCompare);

        bool isEmpty() const;

        void insert(ElementType elem);
        NodeType* remove(NodeType* root, ElementType elem);

        void print();
    };
};

#include "BalanceBinarySearchTree.cpp"

#endif // BALANCEBINARYSEARCHTREE_H