#ifndef BINARYTREENODE
#define BINARYTREENODE

#include "User.h"

class BinaryTreeNode
{
private:
    BinaryTreeNode *leftChild;
    BinaryTreeNode *rightChild;

    // index of the user in the heap
    int userIndex; //heapptr
    User nodeUser;

    // User stored in the heap

public:
    BinaryTreeNode();
    BinaryTreeNode(const User &userNode);

    ~BinaryTreeNode();

    BinaryTreeNode *getLeftChild() { return leftChild; }
    BinaryTreeNode *getRightChild() { return rightChild; }
    void setRightChild(BinaryTreeNode *newRightChild) { this->rightChild = newRightChild; }
    void setLeftChild(BinaryTreeNode *newLeftChild) { this->leftChild = newLeftChild; }

    int getUserIndex() { return userIndex; }

    void setUserIndex(int newIndex) { this->userIndex = newIndex; }
    User *getUser() { return &nodeUser; }
    void setUser(User nodeUser) { this->nodeUser = nodeUser; }
    void print();
};

#endif