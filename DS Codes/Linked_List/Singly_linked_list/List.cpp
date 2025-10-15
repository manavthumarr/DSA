#include "List.h"
#include <iostream>

using namespace std;

// Return value of head
Node *List::gethead()
{
   return head;
}

// insert from start
void List::fromStart(int val)
{
   Node *newNode = new Node(val);
   if (!head)
   {
      head = tail = newNode;
      return;
   }
   else
   {
      newNode->link = head;
      head = newNode;
   }
}

// insert from end
void List::fromEnd(int val)
{
   Node *newNode = new Node(val);
   if (!head)
   {
      head = tail = newNode;
      return;
   }
   else
   {
      tail->link = newNode;
      tail = newNode;
   }
}

// insert after nth Node
void List::InsertAt_NthNode(int val)
{

   int n;
   Node *newNode = new Node(val);

   cout << "newNode will be add after nth Node" << endl;
   cout << "enter n:";

   cin >> n;
   if (!head)
   {
      head = tail = newNode;
      return;
   }
   else
   {
      Node *temp = head;
      for (int i = 1; i < n; i++)
      {
         temp = temp->link;
      }
      newNode->link = temp->link;
      temp->link = newNode;
   }
}

// print linked list By recursion
void List::recursivePrintll(Node *p)
{
   if (p != NULL)
   {
      cout << p->data << "->";
      recursivePrintll(p->link);
   }
   else
      cout << "NULL" << endl;
}

// delete Node from start
void List::deleteFromStart()
{
   if (!head)
      return;
   Node *temp = head;
   head = head->link;

   if (!head)
      tail = nullptr;

   delete temp;
}

// delete Node from end
void List::deleteFromEnd()
{

   if (!head)
      return;

   if (!head->link)
   {
      delete head;
      head = tail = nullptr;
      return;
   }

   Node *temp = head;
   while (temp->link->link)
   {
      temp = temp->link;
   }
   delete temp->link;
   tail = temp;
   tail->link = nullptr;
}

// delete Node of specific value
void List::deleteNodeAtValue(int val)
{
   if (!head)
      return;

   if (!(head->link) && head->data == val)
   {
      delete head;
      head = tail = nullptr;
      return;
   }

   if (head->data == val)
   {
      Node *temp = head;
      head = head->link;
      delete temp;
      return;
   }

   Node *temp = head;
   while (temp->link && temp->link->data != val)
   {
      temp = temp->link;
   }
   if (!temp->link)
   {
      cout << "value is not found" << endl;
      return;
   }

   Node *temp1 = temp->link;
   temp->link = temp1->link;

   if (temp1 == tail)
   {
      tail = temp;
   }
   delete temp1;
}

// reverse a linked list
Node *List::rev_ll(Node *curr)
{
   Node *prev = NULL;
   Node *next = NULL;

   while (curr)
   {
      next = curr->link;
      curr->link = prev;
      prev = curr;
      curr = next;
   }
   return prev;
}
