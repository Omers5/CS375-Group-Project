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

enum InputCodes
{
    REGISTER = 1,
    BID = 2,
    SCOREBOARD = 3,
    EXIT = 4,
    HELP = 5,
    PROFIT = 6, //added
    DELETE = 7,
    DELETERANDOM = 8,
};

int determineCurrentCommand(string command)
{
    if (command == "register")
    {
        return REGISTER;
    }
    else if (command == "bid")
    {
        return BID;
    }
    else if (command == "scoreboard")
    {
        return SCOREBOARD;
    }
    else if (command == "exit" || command == "q")
    {
        return EXIT;
    }
    else if (command == "help")
    {
        return HELP;
    }
    //added
    else if (command == "profit")
    {
        return PROFIT;
    }
    else if (command == "delete")
    {
        return DELETE;
    }
    else if (command == "delete random")
    {
        return DELETERANDOM;
    }
    //added
    else
        return -1;
}

int main(int argc, char** argv)
{
    float bank=0; //added
    const string SCOREBOARD_ERROR_MESSAGE = "Invalid input. Correct syntax: 'scoreboard <Number of Bidders to Display>'";
    const string VOTING_ERROR_MESSAGE = "Invalid Input. Correct syntax: 'bid <Bid value> <Candidate Name>'";
    const string REGISTER_ERROR_MESSAGE = "Invalid Input. Correct syntax: 'register <Candidate Name>'";
    const string INPUT_ERROR_MESSAGE =
        "Invalid Command. Possible commands are:\n\
        register <Bidder Name>\n\
        bid <Bid value> <Bidder Name>\n\
        scoreboard <Number of Bidders to Display>\n\
        delete \n\
        delete random \n\
        exit\n";
    const string ENTER_COMMAND_MESSAGE = "Please enter command. Type 'help' for full list.";

    bool errorEncountered = false;

    int numberOfUsers = 0;
    BinaryTree *userTree = new BinaryTree;
    HashTable<LinkedList> *hashLinked = new HashTable<LinkedList>(TABLESIZE);
    HashTable<BinaryTree> *hashTree = new HashTable<BinaryTree>(TABLESIZE);
    PHashTable hashT(TABLESIZE);
    Heaparr scoreboard;
    int flightCost;
    // int totalVotes = 0;
    string temp;
    bool costValid = false;
    // cout << "Please enter flight cost:\n";
    // flightCost=stoi(argv[1]);
    // cout<<"tester:"<<flightCost;
    // while (!costValid)
    // {
    //     // getline(cin, temp);
    //     try
    //     {
    //         flightCost = stoi(temp);
    //         costValid = true;
    //     }
    //     catch (exception e)
    //     {
    //         cout << "Please enter a valid flight cost (Hint: Use an integer):" << endl;
    //         costValid = false;
    //     }
    // }
    string command;
    vector<string> tokens;
    while (true)
    {

        cout << ENTER_COMMAND_MESSAGE << endl;
        getline(cin, command);
        stringstream check1(command);
        string intermediate;
        while (getline(check1, intermediate, ' '))
        {
            if (intermediate != " ")
            {
                tokens.push_back(intermediate);
            }
            // cout<<"\n"<<intermediate;
        }

        // cout<<tokens[0];
        // Get numerical version of command
        int currentCommand = determineCurrentCommand(tokens[0]);

        switch (currentCommand)
        {
        

        
        case REGISTER:
        {
            // Make sure he amount args is correct
            if (tokens.size() == 1)
            {
                cout << "Invalid Input. Correct syntax: 'register<Bidder Name>'" << endl;
                break;
            }

            string username;
            for (int i = 1; i < tokens.size(); ++i)
            {
                username += tokens[i];
                // Check if done, if not add a space
                if (i + 1 != tokens.size())
                {
                    username += " ";
                }
            }
            if (userTree->lookupUser(username) != nullptr)
            {
                cout << "Bidder is already registered." << endl;
                break;
            }
            cout << username << " registered.\n";
            User userToAdd(username);
            userTree->addNode(userToAdd);
            BinaryTreeNode *tmpnode = userTree->lookupNode(username);
            int num = scoreboard.insert(User(username));
            tmpnode->setUserIndex(num);
            numberOfUsers++;
            break;
        }
        case BID:
        {
            if (tokens.size() < 3)
            {
                cout << VOTING_ERROR_MESSAGE << endl;
                break;
            }
            int bid_value = 0;
            try
            {
                bid_value = stoi(tokens[1]);
            }
            catch (exception e)
            {
                cout << VOTING_ERROR_MESSAGE << endl;
                break;
            }
            string username;
            // Generate full name
            for (int i = 2; i < tokens.size(); ++i)
            {
                username += tokens[i];
                // Check if done, if not add a space
                if (i + 1 != tokens.size())
                {
                    username += " ";
                }
            }

            User *localUser = userTree->lookupUser(username);

            // Make sure the candidate is in running
            if (localUser)
            {
                // totalVotes += bid_value / 2; //money for the vote
                // bank+=bid_value/2.0; //added
                localUser->addBid(bid_value);
                BinaryTreeNode *tmpnode = userTree->lookupNode(username);
                int localUserIndex = tmpnode->getUserIndex();
                // cout<<"\nlocal user index="<<localUserIndex;
                scoreboard.maxHeap.at(localUserIndex).addBid(bid_value);
                scoreboard.heapSort(numberOfUsers, userTree);

                cout << "Total Bid amount by " << username << " = " << localUser->amount << endl;
                break;
            }
            else
            {
                cout << "\nBidder " << username << " does not exist." << endl;
                break;
            }
        }
        case SCOREBOARD:
        {
            int k = numberOfUsers;
            if (tokens.size() > 2)
            {
                cout << SCOREBOARD_ERROR_MESSAGE << endl;
                break;
            }
            if (tokens.size() == 2)
            {
                k = stoi(tokens[1]);
            }
            cout << "\nSCOREBOARD";
            cout << "\n-----------------\n";
            scoreboard.print(k);
            scoreboard.heapSort(numberOfUsers, userTree);
            cout << "\n-----------------\n";
            break;
        }
        case PROFIT: //added
        {
            
            cout << "\nProfit";
            cout << "\n-----------------\n";
            cout<<bank; //added
            cout << "\n-----------------\n";
            break;
        }
        case EXIT:
        {
            // Exits program
            User won = scoreboard.pop();
            cout << "\n"<<won.getName()<<" WON THE AUCTION!!!\n" << endl;
            cout << "Closing Program..." << endl;
            cout << "Goodbye." << endl;
            delete userTree;
            return 0;
        }
        case HELP:
            cout << "\nFull list of Commands:\n\
                register<Candidate Name>\n\
                bid <Bid value><Bidder Name>\n\
                scoreboard<Number of Bidder to Display>\n\
                profit\n\
                delete\n\
                delete random\n\
                exit\n"
                 << endl;
            break;
        case DELETE:
        {
            if(numberOfUsers>0)
            {
            User shot_dead = scoreboard.pop();
            cout << "\n Looks like "<<shot_dead.getName()<<" is about to win the auction.\n.\n.\n.BANG!\n" << endl;
            numberOfUsers--;
            scoreboard.heapSort(numberOfUsers, userTree);
            userTree->removeNode(shot_dead.getName());
            shot_dead.print();
            cout << shot_dead.getName() << " was SHOT DEAD!!" << endl;
            }
            else{
            cout << "\n Assasin: \" Umm.... who should I shoot at? chairs and tables??\""<< endl;

            }
            break;
          
        };
        case DELETERANDOM:
        {
            if(numberOfUsers>0)
            {
            User shot_dead = scoreboard.popRandom();
            numberOfUsers--;
            scoreboard.heapSort(numberOfUsers, userTree);
            userTree->removeNode(shot_dead.getName());
            shot_dead.print();
            cout << shot_dead.getName() << " was SHOT DEAD!!" << endl;
            cout << "\n Looks like "<<shot_dead.getName()<<" is about to win the auction.\n.\n.\n.BANG!\n" << endl;
          }
            else{
            cout << "\n Assasin: \" Umm.... who should I shoot at? chairs and tables??\""<< endl;

            }
            break;
        };
        default:

            cout
                << INPUT_ERROR_MESSAGE
                << endl;
            break;
        }

        tokens.clear();
    }
    return 0;
}
