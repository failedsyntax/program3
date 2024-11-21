#include "BinaryTree.h"

// Insert a node into the binary tree recursively
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePointer, TreeNode *&newNode) {
    if (nodePointer == nullptr) {
        nodePointer = newNode;
    } else if (newNode->Value < nodePointer->Value) {
        insert(nodePointer->Left, newNode);
    } else {
        insert(nodePointer->Right, newNode);
    }
}

template <typename T>
void BinaryTree<T>::insertNode(T Item) {
    TreeNode *newNode = nullptr; // Pointer

    // Create Node
    newNode = new TreeNode;
    newNode->Value = Item;
    newNode->Left = newNode->Right = nullptr;

    // Insert
    insert(Root, newNode);
}

template <class T>
bool BinaryTree<T>::searchNode(T Item) {
    TreeNode *nodePtr = Root;

    while (nodePtr) {
        if (nodePtr->Value == Item) {
            return true;
        } else if (Item < nodePtr->Value) {
            nodePtr = nodePtr->Left;
        } else {
            nodePtr = nodePtr->Right;
        }
    };

    return false;
}

template <typename T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr) {
    if (nodePtr) {
        if (nodePtr->Left) {
            destroySubTree(nodePtr->Left);
        };

        if (nodePtr->Right) {
            destroySubTree(nodePtr->Right);
        }

        delete nodePtr;
    }
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *ptr) const {
    if (ptr) {
        displayInOrder(ptr->Left);
        cout << ptr->Value << endl;
        displayInOrder(ptr->Right);
    }
}