#include <string>
#include <vector>

using namespace std;

struct Node
{
	int id;
	string name;
	double value;
	string STATE;
	
	Node()
	{
		id = (int)NULL;
		name = "NULL";
		value = (double)NULL;
		STATE = "NULL";
	}
	Node(string n, int i, double v)
	{
		id = i;
		name = n;
		value = v;
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
		int addBidder(string name, int id, double value);
		int findBidder(int id);
		int assassinateBidder(int id);
		int assassinateRandomBidder();
		int bidHigherValue(int id, double value);
		int getBidders(int limit);
		string getBidderName(int id);
		double getBidderBid(int id);
		Node winner();
};
