#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;

const string namesarr[20] = {"Liam", "Olivia", "Noah", "Emma", "Oliver", 
                             "Ava", "Elijah", "Charlotte", "William", "Sophia",
                             "James", "Amelia", "Benjamin", "Isabella", "Lucas",
                             "Mia", "Henry", "Evelyn", "Alexander", "Harper"};

int main (int argc, char *argv[]) {
  if(argc != 3)
  {
    cout << "Expecting two arguments: ./" << argv[0] << " <filename> <int k>\n\tk is number of instructions" << endl;
    return -1;
  }
  string outputfilen = argv[1];
  int k = stoi(argv[2]);
  ofstream outfile (outputfilen);
  int totnum = 0;
	if (outfile.is_open())
	{
		for(int i = 0; i < k; i++)
		{
      int randNum = rand()%6;
      if(randNum == 0) {
        //add
        
        outfile << "add " << namesarr[rand()%20] << " " << rand()%10000 << endl;
        totnum++;
      } else if(randNum == 1) {
        //assassinate
        
        outfile << "assassinate " << rand()%totnum << endl;
        totnum--;
      } else if(randNum == 2) {
        //bid
        outfile << "bid " << rand()%totnum << rand()%10000 << endl;
      } else if(randNum == 3) {
        //getname
        outfile << "getname " << rand()%totnum << endl;
      } else if(randNum == 4) {
        //getbid
        outfile << "getbid " << rand()%totnum << endl;
      } else {
        //scoreboard
        outfile << "scoreboard " << rand()%totnum << endl;
      }
		}
    outfile << "winner" << endl;
		outfile.close();
	} else {
		cout << "Failed to open output file: " << outputfilen << endl;
		return -1;
	}
	return 0;
}
