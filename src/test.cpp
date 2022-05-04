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
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();
  PHashTable hashT(TABLESIZE);
  Heaparr maxHeap;
  int idhold = 0;
  for(int i = 0; i < commandsin.size; i++)
  {
    istringstream iss(line);
		string hold;
    getline(iss, hold, ' ');
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
      hashT.addBidder(namein, idin);
      User userin(to_string(idin));
      userin.amount = stoi(bidin);
      int iout = maxHeap.insert(userin);
      //output id
      cout << "User " << namein << " with bid " << bidin << " created with id " << idin << endl;

    } else if(cmdin == "assassinate"){
      //cout << "Input \"random\" or int id: ";
      string idorrand;
      getline(iss, idorrand, ' ');
      //assassinate here
    } else if(cmdin == "bid"){
      string idin;
      string bidin;
      getline(iss, idin, ' ');
      getline(iss, bidin, ' ');
      //update bid here
    } else if(cmdin == "getname"){
      string idin;
      getline(iss, idin, ' ');
      string nameout = hashT.getBidderName(idin);
      if(nameout == "-1")
      {
        cout << "id " << idin << " not found" << endl;
      } else {
        cout << "id " << idin << " name is " << nameout << endl;
      }
    } else if(cmdin == "getbid"){
      string idin;
      getline(iss, idin, ' ');
    } else if(cmdin == "winner"){
      string winout = "";
      cout << "Winner of auction is: " << winout;
      lhold = false;
    } else if(cmdin == "exit"){
      cout << "Exiting..." << endl;
      lhold = false;
    } else if(cmdin == "scoreboard"){
      string amount;
      getline(iss, amount, ' ');
    }
  }
  end = chrono::system_clock::now();
  //run and time commands on linked list hashtable
  start = chrono::system_clock::now();
  end = chrono::system_clock::now();
  //run and time commands on bst hashtable
  start = chrono::system_clock::now();
  end = chrono::system_clock::now();
  //delete necessary tables
  delete hashLinked;
  delete hashTree;
}
