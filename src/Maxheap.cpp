#include "Maxheap.h"
#include "BinaryTree.h"
Heaparr::Heaparr() {
    size = 0;
}

int Heaparr::insert(User da) {
    size++;
    maxHeap.push_back(da);

    // User *ptr = &maxHeap.at(size-1);
    // maxHeap.at(size-1).heapptr=ptr;
    return size-1;
}

void Heaparr::heapSort( int heap_size/*,BinaryTree * bt*/) {
    size = heap_size;
    int n = size;
    Build_Max_Heap(heap_size);
    for (int i = n - 1; i >= 1; i--) {
        string user1=maxHeap.at(0).name;
        string user2=maxHeap.at(i).name;
        /*BinaryTreeNode* btnode1=bt->lookupNode(user1);
        BinaryTreeNode* btnode2=bt->lookupNode(user2);
        btnode1->setUserIndex(i);
        btnode2->setUserIndex(0);*/
            //  maxHeap.at(0).heapptr=&maxHeap.at(i);
            //  maxHeap.at(i).heapptr=&maxHeap.at(0);

        swap(maxHeap.at(0), maxHeap.at(i));

        heap_size = heap_size - 1;
        Max_Heapify( 0, heap_size);
    }
}

// void Heaparr::swapTreeUserIndex(string user1,string user2)
// {

// }

void Heaparr::Build_Max_Heap( int heap_size) {
    int n = size;
    for (int i = floor((n - 1) / 2); i >= 0; i--) {
        Max_Heapify( i, heap_size);
    }
    return;
}

void Heaparr::Max_Heapify( int i, int heap_size) {
    int largest = 0;
    int l = getLeft(i);
    int r = getRight(i);

    if ((l < heap_size) && (maxHeap.at(l).amount < maxHeap.at(i).amount)) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < heap_size) && (maxHeap.at(r).amount < maxHeap.at(largest).amount)) {
        largest = r;
    }

    if (largest != i) {
        swap(maxHeap.at(i), maxHeap.at(largest));
        Max_Heapify(largest, heap_size);
    }
    return;
}

void Heaparr::print(int k){
    int size;
    if(k>maxHeap.size())
    {
        size=maxHeap.size();
    }
    else{
        size = k;
    }
    vector<User> templist;
    for(int i=0;i<size;i++)
    {
        // cout<<"pop \n";
        templist.push_back(pop());
    }
    //maxHeap is empty at this point

    int size2=templist.size();
    for(int i=0;i<size2;i++)
    {
        maxHeap.push_back(templist.at(i));
    }
    //put everything back to heap
}

User Heaparr::popid(int id){
    for(int i = 0; i < maxHeap.size(); i++)
    {
        if(maxHeap.at(i).id == id)
        {
            //std::cout <<maxHeap.at(i).name<<"\t"<<maxHeap.at(i).amount<< "\n ";
            User tmp = maxHeap.at(i);
            maxHeap.erase(maxHeap.begin()+i);
            return tmp;
        }
    }
    return User();
}

User Heaparr::pop(){
    if (maxHeap.size() > 0) {
        std::cout <<maxHeap.at(0).name<<"\t"<<maxHeap.at(0).amount<< "\n ";
        User tmp = maxHeap.at(0);
        maxHeap.erase(maxHeap.begin());
        return tmp;
    }
    return User();
}

User Heaparr::popRandom(){
    if (maxHeap.size() > 0) {
        //std::cout <<maxHeap.at(0).name<<"\t"<<maxHeap.at(0).amount<< "\n ";
        int randNum = rand()%(maxHeap.size() - 0 + 1) + 0;
        User tmp = maxHeap.at(randNum);
        maxHeap.erase(maxHeap.begin()+randNum);
        return tmp;
    }
    return User();
}

int getBid(int id)
{
    for(int i = 0; i < maxHeap.size(); i++)
    {
        if(maxHeap.at(i).id == id)
        {
            //std::cout <<maxHeap.at(i).name<<"\t"<<maxHeap.at(i).amount<< "\n ";
            return maxHeap.at(i).amount;
        }
    }
    return -1;
}

int updateBid(int id)
{
    for(int i = 0; i < maxHeap.size(); i++)
    {
        if(maxHeap.at(i).id == id)
        {
            //std::cout <<maxHeap.at(i).name<<"\t"<<maxHeap.at(i).amount<< "\n ";
            maxHeap.at(i).addBid(bid_value);
            return maxHeap.at(i).amount;
        }
    }
    return -1;
}
