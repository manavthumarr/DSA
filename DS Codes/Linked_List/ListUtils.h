#ifndef LISTUTILS_H
#define LISTUTILS_H

#include "Singly_linked_list/Node.h"
#include "Doubly_linked_list/DoublyNode.h"
#include <iostream>
using namespace std;

// if you add template so, recommeded you to define function in header only
template <typename NodeType>
void printList(NodeType *head)
{
    NodeType *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

#endif
