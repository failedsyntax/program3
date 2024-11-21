#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

template <typename T>
class BinaryTree {
    private:
        struct TreeNode {
            T Value; // Node Value
            TreeNode *Left; // Left Node
            TreeNode *Right; // Right Node
        };

        TreeNode *Root; // Root Node

        // Private Functions
        void insert(TreeNode *&, TreeNode *&);
        void destroySubTree(TreeNode *);
        void displayInOrder(TreeNode *) const;

    public:
        BinaryTree() {
            Root = NULL;
        };

        ~BinaryTree() {
            destroySubTree(Root);
        };

        // Public Functions
        bool searchNode(T);
        void insertNode(T);
        void displayInOrder() const {
            displayInOrder(Root);
        };
};

#endif