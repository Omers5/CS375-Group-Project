#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    this->headNode = nullptr;
}

// Add node to the binary search tree
void BinaryTree::add(int id, string name)
{
    BTNode *newNode = new BTNode();
    newNode->name = name;
    newNode->id = id;
    newNode->left = nullptr;
    newNode->right = nullptr;
    BTNode *currentNode = this->head;
    bool lookingForSpot = true;
    if(currentNode == nullptr)
    {
        headNode = newNode;
        return;
    }
    // Check for empty tree
    while(currentNode != nullptr)
    {
        if(newNode->id < currentNode->id)
        {
            if(currentNode->left == nullptr)
            {
                currentNode->left = newNode;
                return;
            } else {
                currentNode = currentNode->left;
            }
        } else {
            if(currentNode->right == nullptr)
            {
                currentNode->right = newNode;
                return;
            } else {
                currentNode = currentNode->right;
            }
        }
    }
}

// remove a node from a tree and return name, returns -1 if user is not present or tree is empty
bool BinaryTree::remove(int id)
{
    BTNode *currNode = this->head;
    BTNode *prevNode = this->head;
    int comingFromDirection = 0; //-1 for left, 1 for right; shows the direction the the currentNode came from

    while (currNode != nullptr)
    {
        
        if (currNode->id == id)
        {
            string nout = currNode->name;
        
            // Check if leaf node
            if (currNode->right == nullptr && currNode->left == nullptr)
            { 
                if (comingFromDirection > 0)
                {
                    prevNode->right = nullptr;
                }
                else if(comingFromDirection < 0)
                {
                    prevNode->left = nullptr;
                } else if(currNode == head) {
                    head = nullptr;
                }
            }

            // Case if left is null, right is not
            else if (currNode->left == nullptr && currNode->right != nullptr)
            {
                if (comingFromDirection > 0)
                {
                    prevNode->right = currNode->right;
                }
                else if(comingFromDirection < 0)
                {
                    prevNode->left = currNode->right;
                } else if(currNode == head) {
                    head = currNode->right;
                }
            }
            // Case if right is null, left is valid
            else if (currNode->left != nullptr && currNode->right == nullptr)
            {
                if (comingFromDirection > 0)
                {
                    prevNode->right = currNode->left;
                }
                else if(comingFromDirection < 0)
                {
                    prevNode->left = currNode->left;
                } else if(currNode == head) {
                    head = currNode->left;
                }
            }

            // If both the right and left are valid
            else if (currNode->getLeftChild() != nullptr && currNode->getRightChild() != nullptr)
            {
                BTNode * nhold = currNode->left;
                BTNode * nholdp = currNode;
                while(nhold->left != nullptr)
                {
                    nholdp = nhold;
                    nhold = nhold->left;
                }
                nholdp->left = nhold->right;
                currNode->name = nhold->name;
                currNode->id = nhold->id;
                // cout << minUser->getName() << endl;
                currNode = nhold;
            }
            delete currNode
            return nout;
        }

        // Move up prev and current Value
        prevNode = currNode; // Move prev node to the current node
        if (currNode->id < id)
        {
            currNode = currNode->right;
            comingFromDirection = 1;
        }
        else
        {
            currNode = currNode->left;
            comingFromDirection = -1;
        }
    }
    
    return "-1";
}

string BinaryTree::getName(int id)
{
    BTNode* hold = head;
    while(hold != nullptr)
    {
        if(hold->id < id)
        {
            hold = hold->right;
        } else if(hold->id > id) {
            hold = hold->left;
        } else {
            return hold->name;
        }
    }
    return "-1";
}

//Print Tree with additional info
/*void BinaryTree::printInfo()
{
    cout << "Number of Elements in tree: " << this->nElemenets << endl;
    inOrderPrint(this->headNode);
}


//Print Tree using in-order print
void BinaryTree::inOrderPrint(BinaryTreeNode *root)
{

    if (root == nullptr)
    {
        return;
    }

    inOrderPrint(root->getLeftChild());
    cout << root->getUser()->getName() << endl;
    inOrderPrint(root->getRightChild());
}*/
