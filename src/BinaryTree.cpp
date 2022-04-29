#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    this->headNode = nullptr;
    this->nElemenets = 0;
}

// Add node to the binary search tree
void BinaryTree::addNode(const User &userToAdd)
{
    BinaryTreeNode *newNode = new BinaryTreeNode(userToAdd);
    BinaryTreeNode *currentNode = this->headNode;
    bool lookingForSpot = true;
    // Check for empty tree
    while (lookingForSpot)
    {
        if (currentNode == nullptr)
        {
            headNode = newNode;
            lookingForSpot = false;
            ++this->nElemenets;
        }

        else
        {
            // Check if newNode has a lower alphabetical order than the currentNode
            if (*(newNode->getUser()) < *(currentNode->getUser()))
            {
                // newNode is smaller
                if (currentNode->getLeftChild() == nullptr)
                {
                    currentNode->setLeftChild(newNode);
                    /*cout << currentNode->getUser()->getName() << " left child = "
                         << newNode->getUser()->getName() << endl;*/
                    lookingForSpot = false;
                    ++this->nElemenets;
                }
                else
                {
                    currentNode = currentNode->getLeftChild();
                }
            }
            else
            {
                // newNode is larger
                if (currentNode->getRightChild() == nullptr)
                {
                    currentNode->setRightChild(newNode);
                    /*cout << currentNode->getUser()->getName() << " right child = "
                         << newNode->getUser()->getName() << endl;*/
                    lookingForSpot = false;
                    ++this->nElemenets;
                }
                else
                {
                    currentNode = currentNode->getRightChild();
                }
            }
        }
    }

    //free(newNode);
    //free(currentNode);
}

//Lookup username and return a pointer to the user, returns nullpointer if not present
User *BinaryTree::lookupUser(string userName)
{

    // Make sure tree is not empty
    if (headNode == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode *currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getUser()->getName() == userName)
        {
            return currentNode->getUser();
        }
        // Check if the userName is more or less than currentNode, alphabetically
        if (userName < currentNode->getUser()->getName())
        {
            // userName is smaller
            currentNode = currentNode->getLeftChild();
        }
        else
        {
            currentNode = currentNode->getRightChild();
        }
    }
    return nullptr;
}



//Lookup username and return a pointer to the BinaryTreeNode, returns nullpointer if not present
BinaryTreeNode *BinaryTree::lookupNode(string userName)
{

    // Make sure tree is not empty
    if (headNode == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode *currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getUser()->getName() == userName)
        {
            return currentNode;
        }
        // Check if the userName is more or less than currentNode, alphabetically
        if (userName < currentNode->getUser()->getName())
        {
            // userName is smaller
            currentNode = currentNode->getLeftChild();
        }
        else
        {
            currentNode = currentNode->getRightChild();
        }
    }
    return nullptr;
}

// remove a node from a tree, returns false if user is not present or tree is empty
bool BinaryTree::removeNode(string userName)
{
    BinaryTreeNode *currNode = this->headNode;
    BinaryTreeNode *prevNode = this->headNode;
    int comingFromDirection = 0; //-1 for left, 1 for right; shows the direction the the currentNode came from

    // Check if tree is empty
    if (headNode == nullptr)
    {
        return false;
    }

    // Check if the Head is the only node
    if (currNode == headNode && headNode->getUser()->getName() == userName)
    {
        if (currNode->getLeftChild() == nullptr && currNode->getRightChild() == nullptr)
        {
            this->headNode = nullptr;
            // delete headNode;
            --this->nElemenets;
            // cout<<"ONLY HEADNODE\n";
            // headNode->deleteData(1);
            return true;
        }
    }

    // Move current node to the next value
    /*
    if (currNode->getUser() < tempUser)
    {
        currNode = currNode->getRightChild();
        comingFromDirection = 1;
    }
    else
    {
        currNode->getLeftChild();
        comingFromDirection = -1;
    }
    */

    while (currNode != nullptr)
    {
        
        if (currNode->getUser()->getName() == userName)
        {
        
            // Check if leaf node
            if (currNode->getRightChild() == nullptr && currNode->getLeftChild() == nullptr)
            { 
                // if(prevNode==nullptr)
                // {
                //     cout<<"\nPREV NODE IS NULL=======================\n";
                // }
                if (comingFromDirection > 0)
                {
                    prevNode->setRightChild(nullptr);
                }
                else
                {
                    prevNode->setLeftChild(nullptr);
                }
            }

            // Case if left is null, right is not
            else if (currNode->getLeftChild() == nullptr && currNode->getRightChild() != nullptr)
            {
                if (comingFromDirection > 0)
                {
                    prevNode->setRightChild(currNode->getRightChild());
                }
                else
                {
                    prevNode->setLeftChild(currNode->getRightChild());
                }
            }
            // Case if right is null, left is valid
            else if (currNode->getLeftChild() != nullptr && currNode->getRightChild() == nullptr)
            {
                if (comingFromDirection > 0)
                {
                    prevNode->setRightChild(currNode->getLeftChild());
                }
                else
                {
                    prevNode->setLeftChild(currNode->getLeftChild());
                }
            }

            // If both the right and left are valid
            else if (currNode->getLeftChild() != nullptr && currNode->getRightChild() != nullptr)
            {
                User *minUser = findMinUser(currNode);
                // cout << minUser->getName() << endl;
                currNode->setUser(*minUser);
            }
            --this->nElemenets;

            return true;
        }

        // Move up prev and current Value
        prevNode = currNode; // Move prev node to the current node
        if (currNode->getUser()->getName() < userName)
        {
            currNode = currNode->getRightChild();
            comingFromDirection = 1;
        }
        else
        {
            currNode = currNode->getLeftChild();
            comingFromDirection = -1;
        }
    }
    
    return false;
}

//Print Tree with additional info
void BinaryTree::printInfo()
{
    cout << "Number of Elements in tree: " << this->nElemenets << endl;
    inOrderPrint(this->headNode);
}

// Get the minimum node from a node position and removes it from the prev Node
// ONLY USE AS A HELPER TO THE REMOVE FUNCTION; gets the inorder smallest node
User *BinaryTree::findMinUser(BinaryTreeNode *root)
{
    BinaryTreeNode *currNode = root;
    BinaryTreeNode *prevNode = root;
    if (currNode->getRightChild() != nullptr)
    {
        currNode = currNode->getRightChild();
    }
    else
        return nullptr;

    while (currNode->getLeftChild() != nullptr)
    {
        prevNode = currNode;
        currNode = currNode->getLeftChild();
    }
    User *tempUser = currNode->getUser();
    ++nElemenets; // Compensates for the remove node being called
    removeNode(currNode->getUser()->getName());
    // prevNode->setLeftChild(nullptr);
    return tempUser;
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
}