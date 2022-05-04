#ifndef USER
#define USER

#include <string>
#include <iostream> 

using namespace std;


class User{
    
    public:
        string name;
        int amount;
        //Access to memory adress in heap
        // User *heapptr;
    public:
        User();
        User(string userName);
        User(string userName,User * ptr);

        void addBid(int x);
        bool operator<(const User& other);

        string getName() { return name; }

        void print();
};

#endif