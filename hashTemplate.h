#include <vector>

using namespace std;
//to be used with either linked list or BST as bucket
template <typename bucket>
class HashTable
{
	public:
		HashTable(int sizeIn)
		{
			tableSize = sizeIn;
		}
		void addBidder(string name, int id)
		{
			Table[id%tableSize].add(name, id);
		}
		//this should be also used for assassinateRandomBidder
		//	id for this should be sent from id that was removed from heap
		void assassinateBidder(int id)
		{
			Table[id%tableSize].remove(id);
		}
		void getBidderName(int id)
		{
			Table[id%tableSize].getName(id);
		}
			
		
	private:
		int tableSize;
		vector<bucket> Table;
};
