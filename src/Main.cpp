//this executable will take 1 argument (1,2,or 3)
//  initialize the hash table with the option chosen (1 = linear, 2 = linked list, 3 = BST)
//  Allow user control over table


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

const int TABLESIZE = 10;
int main (int argc, char *argv[]) {
  int idhold = 1;
  if(argc != 2)
  {
    cout << "Requires only 1 argument after executable name.\nReceived " << to_string(argc-1) << " arguments after executable." << endl;
    return -1;
  }
  if(argv[1][0] == '1')
  {
    //linear
    cout << "Hash table with linked list buckets selected (using " << TABLESIZE << " buckets, changeable in main.cpp)" << endl;
    PHashTable hashT(TABLESIZE);
    Heaparr maxHeap;
    bool lhold = true;
    cout << "Please input a command from the following list:\n\tadd bidder\n\tassassinate\n\tbid\n\tget name\n\tget bid\n\twinner\n\texit" << endl;
    while (lhold) {
      string cmdin;
      cout << "cmd: ";
      cin >> cmdin;
      if(cmdin == "add bidder"){
        //get bidder name and value
        string namein;
        int bidin;
        cout << "Input bidder name: ";
        cin >> namein;
        cout << "Input bid value (int): ";
        cin >> bidin;
        //give own ID
        int idin = idhold;
        idhold++;
        //input data into maxheap and hashtable
        hashT.addBidder(namein, idin);
        User userin(to_string(idin));
        userin.amount = bidin;
        int iout = maxHeap.insert(userin);
        //output id
        cout << "User " << namein << " with bid " << bidin << " created with id " << idin << endl;
        
      } else if(cmdin == "assassinate"){
        cout << "Input \"random\" or int id: ";
        cin >> cmdin;
        //assassinate here
      } else if(cmdin == "bid"){
        int idin;
        int bidin;
        cout << "Input int id: ";
        cin >> idin;
        cout << "Input int bid to increase original bid by: ";
        cin >> bidin;
        //update bid here
      } else if(cmdin == "get name"){
        int idin;
        cout << "Input int id: ";
        cin >> idin;
        string nameout = hashT.getBidderName(idin);
        if(nameout == "-1")
        {
          cout << "id " << idin << " not found" << endl;
        } else {
          cout << "id " << idin << " name is " << nameout << endl;
        }
      } else if(cmdin == "get bid"){
        
      } else if(cmdin == "winner"){
        
      } else if(cmdin == "exit"){
        cout << "Exiting..." << endl;
        lhold = false;
      } else {
        cout << "Unknown command. Command received: \"" << cmdin << "\".\nPlease input a command from the following list:\n\tadd bidder\n\tassassinate\n\tbid\n\tget name\n\tget bid\n\twinner\n\texit" << endl;
      }
      
    }
  } else if(argv[1][0] == '2') {
    //linked list
    cout << "Hash table with linked list buckets selected (using " << TABLESIZE << " buckets, changeable in main.cpp)" << endl;
    HashTable<LinkedList> *hashLinked = new HashTable<LinkedList>(TABLESIZE);
    Heaparr maxHeap;
    bool lhold = true;
    cout << "Please input a command from the following list:\n\tadd bidder\n\tassassinate\n\tbid\n\tget name\n\tget bid\n\twinner\n\texit" << endl;
    while (lhold) {
      string cmdin;
      cout << "cmd: ";
      cin >> cmdin;
      if(cmdin == "add bidder"){
        //get bidder name and value
        string namein;
        int bidin;
        cout << "Input bidder name: ";
        cin >> namein;
        cout << "Input bid value (int): ";
        cin >> bidin;
        //give own ID
        int idin = idhold;
        idhold++;
        //input data into maxheap and hashtable
        hashLinked->addBidder(namein, idin);
        User userin(to_string(idin));
        userin.amount = bidin;
        int iout = maxHeap.insert(userin);
        //output id
        cout << "User " << namein << " with bid " << bidin << " created with id " << idin << endl;
        
      } else if(cmdin == "assassinate"){
        cout << "Input \"random\" or int id: ";
        cin >> cmdin;
        //assassinate here
      } else if(cmdin == "bid"){
        int idin;
        int bidin;
        cout << "Input int id: ";
        cin >> idin;
        cout << "Input int bid to increase original bid by: ";
        cin >> bidin;
        //update bid here
      } else if(cmdin == "get name"){
        int idin;
        cout << "Input int id: ";
        cin >> idin;
        string nameout = hashLinked->getBidderName(idin);
        if(nameout == "-1")
        {
          cout << "id " << idin << " not found" << endl;
        } else {
          cout << "id " << idin << " name is " << nameout << endl;
        }
      } else if(cmdin == "get bid"){
        
      } else if(cmdin == "winner"){
        
      } else if(cmdin == "exit"){
        cout << "Exiting..." << endl;
        delete hashLinked;
        lhold = false;
      } else {
        cout << "Unknown command. Command received: \"" << cmdin << "\".\nPlease input a command from the following list:\n\tadd bidder\n\tassassinate\n\tbid\n\tget name\n\tget bid\n\twinner\n\texit" << endl;
      }
      
    }
  } else if(argv[1][0] == '3'){
    //BST
    cout << "Hash table with linked list buckets selected (using " << TABLESIZE << " buckets, changeable in main.cpp)" << endl;
    HashTable<BinaryTree> *hashTree = new HashTable<BinaryTree>(TABLESIZE);
    Heaparr maxHeap;
    bool lhold = true;
    cout << "Please input a command from the following list:\n\tadd bidder\n\tassassinate\n\tbid\n\tget name\n\tget bid\n\twinner\n\texit" << endl;
    while (lhold) {
      string cmdin;
      cout << "cmd: ";
      cin >> cmdin;
      if(cmdin == "add bidder"){
        //get bidder name and value
        string namein;
        int bidin;
        cout << "Input bidder name: ";
        cin >> namein;
        cout << "Input bid value (int): ";
        cin >> bidin;
        //give own ID
        int idin = idhold;
        idhold++;
        //input data into maxheap and hashtable
        hashTree->addBidder(namein, idin);
        User userin(to_string(idin));
        userin.amount = bidin;
        int iout = maxHeap.insert(userin);
        //output id
        cout << "User " << namein << " with bid " << bidin << " created with id " << idin << endl;
        
      } else if(cmdin == "assassinate"){
        cout << "Input \"random\" or int id: ";
        cin >> cmdin;
        //assassinate here
      } else if(cmdin == "bid"){
        int idin;
        int bidin;
        cout << "Input int id: ";
        cin >> idin;
        cout << "Input int bid to increase original bid by: ";
        cin >> bidin;
        //update bid here
      } else if(cmdin == "get name"){
        int idin;
        cout << "Input int id: ";
        cin >> idin;
        string nameout = hashTree->getBidderName(idin);
        if(nameout == "-1")
        {
          cout << "id " << idin << " not found" << endl;
        } else {
          cout << "id " << idin << " name is " << nameout << endl;
        }
      } else if(cmdin == "get bid"){
        
      } else if(cmdin == "winner"){
        
      } else if(cmdin == "exit"){
        cout << "Exiting..." << endl;
        delete hashTree;
        lhold = false;
      } else {
        cout << "Unknown command. Command received: \"" << cmdin << "\".\nPlease input a command from the following list:\n\tadd bidder\n\tassassinate\n\tbid\n\tget name\n\tget bid\n\twinner\n\texit" << endl;
      }
      
    }
  } else {
    cout << "argv[1] must be between 1-3, inclusive.\nReceived \"" << argv[1] << "\" as argv[1]\n\t(usage: 1 = linear, 2 = linked list, 3 = BST)" << endl;
    return -1;
  }
  return 0;
}
