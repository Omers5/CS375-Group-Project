#include <string>
#include <vector>

using namespace std;

struct Node
{
	int id;
	string name;
	string STATE;
	
	Node()
	{
		id = (int)NULL;
		name = "NULL";
		STATE = "NULL";
	}
	Node(string n, int i)
	{
		id = i;
		name = n;
		STATE = "NORMAL";
	}
};

class HashTable{
	private:
		int tableSize;
		vector<Node> hash_vect;
	public:
		HashTable(int size);
		int hashFunct(int id);
		int addBidder(string name, int id);
		int findBidder(int id);
		int assassinateBidder(int id);
		string getBidderName(int id);
};
