#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

using namespace std;


struct LLNode
{
  int id;
  string name;
  LLNode *next;
};

class LinkedList
{
  private:
    LLNode * head;
  public:
    LinkedList()
    {
      head = nullptr;
    }
    ~LinkedList()
    {
      while(head != nullptr)
      {
        LLNode * hold = head;
        head = head->next;
        delete hold;
      }
    }
    void add(string name, int id)
    {
      LLNode* hold = head;
      LLNode* holdp = head;
      while(hold != nullptr)
      {
        if(id == hold->id)
        {
          //?? what to do about this?
        }
        holdp = hold;
        hold = hold->next;
      }
      LLNode* holdin = new LLNode();
      holdin->id = id;
      holdin->name = name;
      holdin->next = nullptr;
      holdp->next = holdin;
    }
    //return name
    string remove(int id)
    {
      LLNode* hold = head;
      LLNode* holdp = head;
      while(hold != nullptr)
      {
        if(id == hold->id)
        {
          holdp->next = hold->next;
          string nout = hold->name;
          delete hold;
          return nout;
        }
        holdp = hold;
        hold = hold->next;
      }
      return "-1";
    }
    string getName(int id)
    {
      LLNode* hold = head;
      //Node* holdp = head;
      while(hold != nullptr)
      {
        if(id == hold->id)
        {
          return hold->name;
        }
        //holdp = hold;
        hold = hold->next;
      }
      return "-1";
    }
};
  
#endif
