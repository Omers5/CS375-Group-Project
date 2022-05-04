//this executable will take no arguments
//  initialize all 3 options of hash table
//  Run pre-set tests on all 3 hash tables
//  output the time taken for each method on hash table


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "User.h"
#include "BinaryTree.h"
#include "Maxheap.h"
#include "LinkedList.h"
#include "HashTemplate.h"
#include "ProbeHash.h"

using namespace std;

const int TABLESIZE = 10;

enum InputCodes
{
    REGISTER = 1,
    BID = 2,
    SCOREBOARD = 3,
    EXIT = 4,
    HELP = 5,
    PROFIT = 6, //added
    DELETE = 7,
    DELETERANDOM = 8,
};

int determineCurrentCommand(string command)
{
    if (command == "register")
    {
        return REGISTER;
    }
    else if (command == "bid")
    {
        return BID;
    }
    else if (command == "scoreboard")
    {
        return SCOREBOARD;
    }
    else if (command == "exit" || command == "q")
    {
        return EXIT;
    }
    else if (command == "help")
    {
        return HELP;
    }
    //added
    else if (command == "profit")
    {
        return PROFIT;
    }
    else if (command == "delete")
    {
        return DELETE;
    }
    else if (command == "delete random")
    {
        return DELETERANDOM;
    }
    //added
    else
        return -1;
}

int main (int argc, char *argv[]) {
  //create all hash tables and maxheap
  HashTable<LinkedList> *hashLinked = new HashTable<LinkedList>(TABLESIZE);
  HashTable<BinaryTree> *hashTree = new HashTable<BinaryTree>(TABLESIZE);
  PHashTable hashT(TABLESIZE);
  Heaparr maxHeap;
  
  //delete necessary tables
  delete hashLinked;
  delete hashTree;
}
