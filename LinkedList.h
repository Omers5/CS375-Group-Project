#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

using namespace std;


struct Node
{
  int id;
  string name;
  Node *next;
}

class LinkedList
{
  Node * head;
  public:
  LinkedList()
  {
    head = nullptr;
  }
  void add(int id, string name)
  {
    Node* hold = head;
    Node* holdp = head;
    while(hold != nullptr)
    {
      if(id == hold.id)
      {
        //?? what to do about this?
      }
      holdp = hold;
      hold = hold.next;
    }
    Node holdin = new Node();
    holdin.id = id;
    holdin.name = name;
    holdin.next = nullptr;
    holdp.next = holdin;
  }
  //return name
  string remove(int id)
  {
    Node* hold = head;
    Node* holdp = head;
    while(hold != nullptr)
    {
      if(id == hold.id)
      {
        holdp.next = hold.next;
        string nout = hold.name;
        delete out;
        return nout;
      }
      holdp = hold;
      hold = hold.next;
    }
    return "-1";
  }
  string getName(int id)
  {
    Node* hold = head;
    Node* holdp = head;
    while(hold != nullptr)
    {
      if(id == hold.id)
      {
        return hold.name;
      }
      holdp = hold;
      hold = hold.next;
    }
    return "-1";
  }
}
  
#endif
