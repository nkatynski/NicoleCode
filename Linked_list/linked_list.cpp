// This program is an exercise in linked list use. Normally, we would use the STL to implement a list, but to make sure we understand pointer variables, we're making our own from scratch.

#include <iostream>

using namespace std;

struct node{
    double val;
    node *next = NULL;  // pointer to the next node
};

class LinkedList {
private:
  node *head;
  node *last;
public:
  void add(double x)
  {
      node *newNode = new node; // declare new node, assign value and address of next node
      newNode->val = x;
      newNode->next = NULL;
      if(!head){                // if the linked list has no head node
        head = newNode;         // the address for the head node is that of the new node
        last = newNode;         // the address for the last node is that of the new node
      }
      else                      // if a head node already exists
      {
        last->next = newNode;   // set the current last node's next pointer to the address of the new node
        last = newNode;         // make the new node the new last node
      }
  }

  bool isMember(double x)
  {
    bool membership = false;
    bool runSearch = true;
    node *currentNode = new node;
    currentNode = head;

    // check if head node contains the searched value
    if(currentNode->val == x) membership = true;
    while(runSearch && !membership)
    {
      // finding the searched value ends the search
      if(currentNode->val == x) membership = true;
      else
      {
        // if search value not found, advance to the next node if one exists
        if(currentNode->next) currentNode = currentNode->next;
        // if no next node exists, terminate the search
        else runSearch = false;
      }
    }

    return membership;
  }

  // default constructor
  LinkedList()
  {
    head = NULL;
    last = NULL;
  }
};

int main()
{
  LinkedList linkList;
  double searchVal = 7.28;

  linkList.add(5);
  linkList.add(12385);
  linkList.add(7.28);
  if(linkList.isMember(searchVal)) cout << searchVal << " is a member." << endl;
  else cout << searchVal << " is not a member." << endl;

  return 0;
}
