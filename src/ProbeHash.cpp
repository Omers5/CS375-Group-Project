#include "ProbeHash.h"

HashTable::HashTable(int size)
{
	tableSize = size;
	cout << "Size allocated: " << tableSize << endl;
	hash_vect.resize(tableSize);
}
		
int HashTable::hashFunct(int id)
{
	return id % tableSize;
}

int HashTable::addBidder(string name, int id, double value)
{
	int i = hashFunct(id);
	
	for(int j = 0; j < tableSize; j++){
		if(hash_vect.at(i).STATE == "NULL" || hash_vect.at(i).STATE == "DELETED")
		{
			hash_vect.at(i) = Node(name, id, value);
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

int HashTable::findBidder(int id)
{
	int i = hashFunct(id);
	
	for(int j = 0; j < tableSize; j++)
	{
		if(hash_vect.at(i).STATE == "DELETED")
		{
			i = (i+1) % tableSize;
			continue;
		}
		else if(hash_vect.at(i).STATE == "NULL")
		{
			//Bidder cannot exist
			return -1;
		}
		else
		{
			if(hash_vect.at(i).id = id)
				return i;
		}
		i = (i+1) % tableSize;
	}
	
	//Bidder not found
	return -1;
}

int HashTable::assassinateBidder(int id)
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

int HashTable::assassinateRandomBidder()
{
	int i = rand() % tableSize;
	for(int j = 0; j < tableSize; j++)
	{
		if(hash_vect.at(i).STATE == "NORMAL")
		{
			hash_vect.at(i).STATE == "DELETED";
			return i;
		}
		i = (i+1) % tableSize;
	}
	
	//No bidders exist
	return -1;
}

int HashTable::bidHigherValue(int id, double value)
{
	int i = findBidder(id);
	if(i < 0)
		return -1;
	if(value > hash_vect.at(i).value)
		hash_vect.at(i).value = value;
	else
		return -1;
}

int HashTable::getBidders(int limit)
{
	if(limit < 1)
	{
		return -1;
	}
	for(int i = 0; i < limit; i++)
	{
		cout << "Name: " << hash_vect.at(i).name << endl;
		cout << "ID: " << hash_vect.at(i).id << endl;
		cout << "Value: " << hash_vect.at(i).value << endl << endl;
	}
	return 0;
}

string HashTable::getBidderName(int id)
{
	int i = findBidder(id);
	if(i < 0)
		return "error";
	else
		return hash_vect.at(i).name;
}

double HashTable::getBidderBid(int id)
{
	int i = findBidder(id);
	if(i < 0)
		return -1;
	else
		return hash_vect.at(i).value;
}

Node HashTable::winner()
{
	int best = 0;
	for(int i = 1; i < tableSize; i++)
	{
		if(hash_vect.at(i).value > hash_vect.at(best).value)
			best = i;
	}
	return hash_vect.at(best);
} 
