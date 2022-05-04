#include <vector>
#include <string>

using namespace std;
//to be used with either linked list or BST as bucket
template <typename bucket>
class HashTable
{
	public:
		HashTable(int sizeIn)
		{
			tableSize = sizeIn;
			for(int i = 0; i < tableSize; i++)
			{
				bucket hold;
				Table.push_back(hold);
			}
		}
	
		~HashTable()
		{
			for(int i = 0; i < tableSize; i++)
			{
				//pop_back() also deletes
				Table.pop_back();
			}
		}
		void addBidder(string name, int id)
		{
			Table[id%tableSize].add(name, id);
		}
		//this should be also used for assassinateRandomBidder
		//	id for this should be sent from id that was removed from heap
		string assassinateBidder(int id)
		{
			return Table[id%tableSize].remove(id);
		}
		string getBidderName(int id)
		{
			return Table[id%tableSize].getName(id);
		}
	
			
		
	private:
		int tableSize;
		vector<bucket> Table;
};
