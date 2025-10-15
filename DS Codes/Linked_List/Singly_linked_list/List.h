#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "ListUtils.h"

class List
{
    Node *head, *tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    Node *gethead(); // Return value of head

    void fromStart(int val); // insert from start

    void fromEnd(int val); // insert from end

    void InsertAt_NthNode(int val); // insert after nth Node

    void printll(); // print linked list

    void deleteFromStart(); // delete Node from start

    void deleteFromEnd(); // delete Node from end

    void deleteNodeAtValue(int val); // delete Node of specific value

    void recursivePrintll(Node *p); // print linked list By recursion

    Node *rev_ll(Node *curr); // Reverse a linked list
};

#endif