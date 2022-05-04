#include "ProbeHash.h"

PHashTable::PHashTable(int size)
{
	tableSize = size;
	//cout << "Size allocated: " << tableSize << endl;
	hash_vect.resize(tableSize);
}
		
int PHashTable::hashFunct(int id)
{
	return id % tableSize;
}

int PHashTable::addBidder(string name, int id)
{
	int i = hashFunct(id);
	
	for(int j = 0; j < tableSize; j++){
		if(hash_vect.at(i).STATE == "NULL" || hash_vect.at(i).STATE == "DELETED")
		{
			hash_vect.at(i) = Node(name, id);
			return id;
		}
		else
		{
			i = (i+1) % tableSize;
		}
	}
	
	//HashTable Full
	return -1;
}

int PHashTable::findBidder(int id)
{
	int i = hashFunct(id);
	
	for(int j = 0; j < tableSize; j++)
	{
		if(hash_vect.at(i).STATE == "NULL")
		{
			//Bidder cannot exist
			return -1;
		}
		else if(hash_vect.at(i).id = id)
		{
			return i;
		}
		i = (i+1) % tableSize;
	}
	
	//Bidder not found
	return -1;
}

int PHashTable::assassinateBidder(int id)
{
	int i = findBidder(id);
	
	if(i < 0)
		return i;
	else
	{
		hash_vect.at(i).STATE == "DELETED";
		return i;
	}
}

string PHashTable::getBidderName(int id)
{
	int i = findBidder(id);
	if(i < 0)
		return "-1";
	else
		return hash_vect.at(i).name;
}
