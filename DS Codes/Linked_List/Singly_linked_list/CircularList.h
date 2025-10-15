#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "Node.h"
#include "ListUtils.h"

class CircularList
{
public:
    Node *head; // Sentinel Node

    CircularList() : head(new Node(0)) // Sentinel ni value
    {
        head->link = head; // for circular
    }

    void fromStart(int val); // insert from start

    void fromEnd(int val); // insert from end

    void deleteNodeAtValue(int val); // delete Node of specific value

    void printll(); // print Linked list
};

#endif