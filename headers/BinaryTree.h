#ifndef BINARYTREE
#define BINARYTREE
//#include "BinaryTreeNode.h"
#include "Maxheap.h"
#include <string>

// Binary Search Tree

struct BTNode
{
    int id;
    string name;
    BTNode *right;
    BTNode *left;
}

class BinaryTree
{
private:
    BinaryTreeNode *head;

public:
    BinaryTree();
    ~BinaryTree() { 
        delNodes(head);
    }
    void delNodes(BTNode* nin)
    {
        if(nin != nullptr)
        {
            delNodes(nin->left);
            delNodes(nin->right);
            delete nin;
        }
    }
    BinaryTreeNode *getHeadNode() { return headNode; }
    void add(int id, string name); // Add user to tree and then update heap
    string remove(int id);    // remove that user from the tree
    string getName(int id);
};

#endif
