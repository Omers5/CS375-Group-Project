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
const bool BOOLPRINTCMDS = true;

int main (int argc, char *argv[]) {
  if(argc != 2)
  {
    cout << "Improper program usage. Proper usage:\n\t" << argv[0] << " <input file name>" << endl;
    return -1;
  }
  //open file and read all lines to store into vector
  string inputfilen = argv[1];
  string line;
	ifstream inputfile (inputfilen);
  vector<string> commandsin;
  if (inputfile.is_open())
	{
		while ( getline (inputfile,line) )
		{
      commandsin.push_back(line);
    }
  }
  inputfile.close();
  //run and time commands on linear hashtable
  cout << "Starting linear probing hashtable" << endl;
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();
  PHashTable hashT(TABLESIZE);
  Heaparr maxHeap;
  int idhold = 1;
  int numberOfUsers = 0;
  int pInserts = 0; //counts total number of inserts
  int pMisses = 0; //counts total number of insert misses
  for(int i = 0; i < commandsin.size(); i++)
  {
    istringstream iss(commandsin[i]);
    string cmdin;
    getline(iss, cmdin, ' ');
	  //if(BOOLPRINTCMDS)
		//  cout << cmdin << endl;
    if(cmdin == "add"){
      //get bidder name and value
      string namein;
      string bidin;
      getline(iss, namein, ' ');
      getline(iss, bidin, ' ');
      //give own ID
      int idin = idhold;
      idhold++;
      //input data into maxheap and hashtable
      int addOut = hashT.addBidder(namein, idin);
      pInserts++;
      if(addOut != -1)
      {
        User userin(to_string(idin));
        userin.amount = stoi(bidin);
        int iout = maxHeap.insert(userin);
        numberOfUsers++;
        maxHeap.heapSort(numberOfUsers);
        //output id
        if(BOOLPRINTCMDS)
          cout << "User " << namein << " with bid " << bidin << " created with id " << idin << endl;
      } else {
        pMisses++;
        if(BOOLPRINTCMDS)
          cout << "User " << namein << " with bid " << bidin << " failed to be created" << endl;
      }

    } else if(cmdin == "assassinate"){
      //cout << "Input \"random\" or int id: ";
      string idorrand;
      getline(iss, idorrand, ' ');
      //assassinate here
      User userOut;
      if(idorrand == "random")
      {
        userOut = maxHeap.popRandom();
      } else {
        userOut =  maxHeap.popid(stoi(cmdin));
      }
	    //cout << userOut.name << endl;
      string nout = to_string(hashT.assassinateBidder(stoi(userOut.name)));
	    //cout << nout << endl;
      if(BOOLPRINTCMDS)
      	cout << "Assassinated bidder " << nout << " with id " << userOut.name << " with bid value " << userOut.amount << endl;
      //sort
      numberOfUsers--;
      maxHeap.heapSort(numberOfUsers);
    } else if(cmdin == "bid"){
      string idin;
      string bidin;
      getline(iss, idin, ' ');
      getline(iss, bidin, ' ');
      //update bid here
      int newBid = maxHeap.updateBid(stoi(idin), stoi(bidin));
      if(newBid == -1)
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " new bid is " << newBid << endl;
      }
      //sort
      maxHeap.heapSort(numberOfUsers);
    } else if(cmdin == "getname"){
      string idin;
      getline(iss, idin, ' ');
      string nameout = hashT.getBidderName(stoi(idin));
      if(nameout == "-1")
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " name is " << nameout << endl;
      }
    } else if(cmdin == "getbid"){
      string idin;
      getline(iss, idin, ' ');
      int bidout = maxHeap.getBid(stoi(idin));
      if(bidout == -1)
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " bid is " << bidout << endl;
      }
    } else if(cmdin == "winner"){
      User won = maxHeap.pop();
      string name = hashT.getBidderName(stoi(won.getName()));
      if(BOOLPRINTCMDS)
      	cout << "Winner of auction is " << name << " with id " << won.getName();
      i = commandsin.size();
    } else if(cmdin == "exit"){
      if(BOOLPRINTCMDS)
      	cout << "Exiting..." << endl;
      i = commandsin.size();
    } else if(cmdin == "scoreboard"){
      string k;
      getline(iss, k, ' ');
      if(BOOLPRINTCMDS)
			{
      	cout << "\nSCOREBOARD";
      cout << "\n-----------------\n";
      maxHeap.print(stoi(k));
      maxHeap.heapSort(numberOfUsers);
      cout << "\n-----------------\n";
			}
    }
  }
  end = chrono::system_clock::now();
  //print time here
  cout << "Linear probing total time: " << ((float)chrono::duration_cast<chrono::microseconds>(end-start).count())/1000 << " milliseconds" << endl;
  cout << "Linear probing misses/total: " << pMisses << "/" << pInserts << endl;
  //run and time commands on linked list hashtable
  cout << "Starting hash table with linked list" << endl;
  start = chrono::system_clock::now();
  HashTable<LinkedList> *hashLinked = new HashTable<LinkedList>(TABLESIZE);
  Heaparr maxHeap2;
  idhold = 1;
  numberOfUsers = 0;
  for(int i = 0; i < commandsin.size(); i++)
  {
    istringstream iss(commandsin[i]);
    string cmdin;
    getline(iss, cmdin, ' ');
    if(cmdin == "add"){
      //get bidder name and value
      string namein;
      string bidin;
      getline(iss, namein, ' ');
      getline(iss, bidin, ' ');
      //give own ID
      int idin = idhold;
      idhold++;
      //input data into maxheap and hashtable
      hashLinked->addBidder(namein, idin);
      User userin(to_string(idin));
      userin.amount = stoi(bidin);
      int iout = maxHeap2.insert(userin);
      numberOfUsers++;
      maxHeap2.heapSort(numberOfUsers);
      //output id
      if(BOOLPRINTCMDS)
      	cout << "User " << namein << " with bid " << bidin << " created with id " << idin << endl;

    } else if(cmdin == "assassinate"){
      //cout << "Input \"random\" or int id: ";
      string idorrand;
      getline(iss, idorrand, ' ');
      //assassinate here
      User userOut;
      if(cmdin == "random")
      {
        userOut = maxHeap2.popRandom();
      } else {
        userOut =  maxHeap2.popid(stoi(cmdin));
      }
      string nout = hashLinked->assassinateBidder(stoi(userOut.name));
      if(BOOLPRINTCMDS)
      	cout << "Assassinated bidder " << nout << " with id " << userOut.name << " with bid value " << userOut.amount << endl;
      //sort
      numberOfUsers--;
      maxHeap2.heapSort(numberOfUsers);
    } else if(cmdin == "bid"){
      string idin;
      string bidin;
      getline(iss, idin, ' ');
      getline(iss, bidin, ' ');
      //update bid here
      int newBid = maxHeap2.updateBid(stoi(idin), stoi(bidin));
      if(newBid == -1)
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " new bid is " << newBid << endl;
      }
      //sort
      maxHeap2.heapSort(numberOfUsers);
    } else if(cmdin == "getname"){
      string idin;
      getline(iss, idin, ' ');
      string nameout = hashLinked->getBidderName(stoi(idin));
      if(nameout == "-1")
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " name is " << nameout << endl;
      }
    } else if(cmdin == "getbid"){
      string idin;
      getline(iss, idin, ' ');
      int bidout = maxHeap2.getBid(stoi(idin));
      if(bidout == -1)
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " bid is " << bidout << endl;
      }
    } else if(cmdin == "winner"){
      User won = maxHeap2.pop();
      string name = hashLinked->getBidderName(stoi(won.getName()));
      if(BOOLPRINTCMDS)
      	cout << "Winner of auction is " << name << " with id " << won.getName();
      //delete hashLinked;
      i = commandsin.size();
    } else if(cmdin == "exit"){
      if(BOOLPRINTCMDS)
      	cout << "Exiting..." << endl;
      //delete hashLinked;
      i = commandsin.size();
    } else if(cmdin == "scoreboard"){
      string k;
      getline(iss, k, ' ');
			if(BOOLPRINTCMDS)
			{
				cout << "\nSCOREBOARD";
				cout << "\n-----------------\n";
				maxHeap2.print(stoi(k));
				maxHeap2.heapSort(numberOfUsers);
				cout << "\n-----------------\n";
			}
    }
  }
  end = chrono::system_clock::now();
    cout << "Hash table with linked list buckets total time: " << ((float)chrono::duration_cast<chrono::microseconds>(end-start).count())/1000 << " milliseconds" << endl;
  //run and time commands on bst hashtable
  cout << "Starting hashtable with BST" << endl;
  start = chrono::system_clock::now();
  HashTable<BinaryTree> *hashTree = new HashTable<BinaryTree>(TABLESIZE);
  Heaparr maxHeap3;
  idhold = 1;
  numberOfUsers = 0;
  for(int i = 0; i < commandsin.size(); i++)
  {
    istringstream iss(commandsin[i]);
    string cmdin;
    getline(iss, cmdin, ' ');
    if(cmdin == "add"){
      //get bidder name and value
      string namein;
      string bidin;
      getline(iss, namein, ' ');
      getline(iss, bidin, ' ');
      //give own ID
      int idin = idhold;
      idhold++;
      //input data into maxheap and hashtable
      hashTree->addBidder(namein, idin);
      User userin(to_string(idin));
      userin.amount = stoi(bidin);
      int iout = maxHeap3.insert(userin);
      numberOfUsers++;
      maxHeap3.heapSort(numberOfUsers);
      //output id
      if(BOOLPRINTCMDS)
      	cout << "User " << namein << " with bid " << bidin << " created with id " << idin << endl;

    } else if(cmdin == "assassinate"){
      //cout << "Input \"random\" or int id: ";
      string idorrand;
      getline(iss, idorrand, ' ');
      //assassinate here
      User userOut;
      if(cmdin == "random")
      {
        userOut = maxHeap3.popRandom();
      } else {
        userOut =  maxHeap3.popid(stoi(cmdin));
      }
      string nout = hashTree->assassinateBidder(stoi(userOut.name));
      if(BOOLPRINTCMDS)
      	cout << "Assassinated bidder " << nout << " with id " << userOut.name << " with bid value " << userOut.amount << endl;
      //sort
      numberOfUsers--;
      maxHeap3.heapSort(numberOfUsers);
    } else if(cmdin == "bid"){
      string idin;
      string bidin;
      getline(iss, idin, ' ');
      getline(iss, bidin, ' ');
      //update bid here
      int newBid = maxHeap3.updateBid(stoi(idin), stoi(bidin));
      if(newBid == -1)
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " new bid is " << newBid << endl;
      }
      //sort
      maxHeap3.heapSort(numberOfUsers);
    } else if(cmdin == "getname"){
      string idin;
      getline(iss, idin, ' ');
      string nameout = hashTree->getBidderName(stoi(idin));
      if(nameout == "-1")
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " name is " << nameout << endl;
      }
    } else if(cmdin == "getbid"){
      string idin;
      getline(iss, idin, ' ');
      int bidout = maxHeap3.getBid(stoi(idin));
      if(bidout == -1)
      {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " not found" << endl;
      } else {
        if(BOOLPRINTCMDS)
      		cout << "id " << idin << " bid is " << bidout << endl;
      }
    } else if(cmdin == "winner"){
      User won = maxHeap3.pop();
      string name = hashTree->getBidderName(stoi(won.getName()));
      if(BOOLPRINTCMDS)
      	cout << "Winner of auction is " << name << " with id " << won.getName();
      //delete hashTree;
      i = commandsin.size();
    } else if(cmdin == "exit"){
      if(BOOLPRINTCMDS)
      	cout << "Exiting..." << endl;
      //delete hashTree;
      i = commandsin.size();
    } else if(cmdin == "scoreboard"){
      string k;
      getline(iss, k, ' ');
      if(BOOLPRINTCMDS)
			{
      	cout << "\nSCOREBOARD";
				cout << "\n-----------------\n";
				maxHeap3.print(stoi(k));
				maxHeap3.heapSort(numberOfUsers);
				cout << "\n-----------------\n";
			}
    }
  }
  end = chrono::system_clock::now();
    cout << "Hash table with BST buckets total time: " << ((float)chrono::duration_cast<chrono::microseconds>(end-start).count())/1000 << " milliseconds" << endl;
  //delete necessary tables
  delete hashLinked;
  delete hashTree;
}
