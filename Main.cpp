//this executable will take 1 argument (1,2,or 3)
//  initialize the hash table with the option chosen (1 = linear, 2 = linked list, 3 = BST)
//  Allow user control over table


#include "LinkedList.h"
#include "hashTemplate.h"


int main (int argc, char *argv[]) {
  if(argc != 2)
  {
    cout << "Requires only 1 argument after executable name.\nReceived " << to_string(argc-1) << " arguments after executable." << endl;
    return;
  }
  if(argv[1] == "1")
  {
    //linear
  } else if(argv[1] == "2") {
    //linked list
  } else if(argv[1] == "3"){
    //BST
  } else {
    cout << "argv[1] must be between 1-3, inclusive.\nReceived \"" << argv[1] << "\" as argv[1]\n\t(usage: 1 = linear, 2 = linked list, 3 = BST)" << endl;
  }
}
