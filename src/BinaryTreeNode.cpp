#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(){
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->userIndex = -1;
}

BinaryTreeNode::BinaryTreeNode(const User& user){
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->userIndex = -1;
    this->nodeUser = user;
}
// void BinaryTreeNode:: deletesingleuser()
// {
//     cout<<"\ndeleteing single user\n";
//     delete &nodeUser;
// }
BinaryTreeNode::~BinaryTreeNode(){
    // cout<<"delete binarytreenode worked\n";
 
    // if(leftChild==nullptr && rightChild==nullptr)
    // {
    //     cout<<"\nDELETING LEFT AND RIGHT\n";
    //     // delete leftChild;
    //     // delete rightChild;
    // }
    if(leftChild!=nullptr)
    {
        // cout<<"\nDELETING LEFT "<<leftChild->getUser()->name<<" \n";
        delete leftChild;
    }
    if(rightChild!=nullptr)
    {
        // cout<<"\nDELETING RIGHT "<<rightChild->getUser()->name<<" \n";
        // cout<<rightChild->getUser()->name;
        // cout<<"\nDELETING RIGHT\n";

        delete rightChild;
    }
    // else{
    //     //    delete leftChild;
    //     // delete rightChild;
    //     // delete leftChild;
    // }
    //  delete leftChild;
    //  delete rightChild;
    
}

void BinaryTreeNode::print(){
    cout << "User: ";
    nodeUser.print();
}
