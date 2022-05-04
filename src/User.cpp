#include "User.h"


User::User(){
    this->name = "";
    this->amount = 0;
}

User::User(string userName){
    this->name = userName;
    this->amount = 0;
}
User::User(string userName,User * ptr){
    this->name = userName;
    // this->heapptr = ptr;
}
void User::addBid(int x)
{
    this->amount = this->amount + x;
}

//Compares the Usernames alphabetically 
bool User::operator<(const User &other)
{
    
    // Find shorter word

    string thisName = this->name;
    string otherName = other.name;

    int lengthOfShortestWord = -1;
    if (thisName.size() > otherName.size())
    {
        lengthOfShortestWord = otherName.size();
    }
    else
    {
        lengthOfShortestWord = thisName.size();
    }

    for (int i = 0; i < lengthOfShortestWord; i++)
    {
        char *nameA = &thisName[i];
        char *nameB = &otherName[i];
        //cout << "Comparing '"<< *nameA <<"' to '" << *nameB<< "'" << endl;
        if (*nameA < *nameB)
        {
            return true;
        }
        else if(*nameA > *nameB){
            return false;
        }
    }
    return false;
}

void User::print(){
    cout << "Name: " << this->name << endl;
    cout << "Votes: " << this->amount << endl;
}