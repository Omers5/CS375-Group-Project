#ifndef MAXHEAP
#define MAXHEAP
#include<vector>
#include "User.h"
#include "BinaryTree.h"
#include <cmath>

class BinaryTree;
class Heaparr {
public:
    Heaparr();
    void swapTreeUserIndex(string user1,string user2);
    int insert(User da);
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }
    int getParent(int i) { return (i - 1) / 2; }
    User getMax() { return maxHeap.at(0); }
    void print(int k);
    void makeArray();
    void Build_Max_Heap( int heap_size);
    void Max_Heapify(int i, int heap_size);
    void heapSort( int heap_size/*,BinaryTree *bt*/);
    User pop();
    User popRandom();
    
    int getBid(int id);
    int updateBid(int id);
    User popid(int id);

    int size;
    vector<User> maxHeap;
    int index;
    int i;
};

#endif
