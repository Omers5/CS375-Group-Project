#ifndef BINARYTREE
#define BINARYTREE
#include "BinaryTreeNode.h"
#include "Maxheap.h"
#include <string>

// Binary Search Tree

class BinaryTree
{
private:
    int nElemenets;
    BinaryTreeNode *headNode;
    // Heaparr *heapPointer; //Points to the max heap

    User *findMinUser(BinaryTreeNode *root);

public:
    BinaryTree();
    ~BinaryTree() { 
        // cout<<"delete binary tree worked\n";
        delete headNode;
         };

    BinaryTreeNode *getHeadNode() { return headNode; }
    int deleteBst();
    void addNode(User const &userToAdd); // Add user to tree and then update heap
    bool removeNode(string userName);    // remove that user from the tree
    User *lookupUser(string userName);   // Lookup if user exists in the tree, if so return the User
    BinaryTreeNode *lookupNode(string userName);   // Lookup if user exists in the tree, if so return the BTNode

    void printInfo();

    void inOrderPrint(BinaryTreeNode *root);
};

#endif