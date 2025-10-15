#include "CircularList.h"
#include <iostream>

using namespace std;

// insert from start
void CircularList::fromStart(int val)
{
    Node *newNode = new Node(val);
    newNode->link = head->link;
    head->link = newNode;
    head->data++; // Increment count
}

// insert from end
void CircularList::fromEnd(int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;

    while (temp->link != head)
    {
        temp = temp->link;
    }

    temp->link = newNode;
    newNode->link = head;
    head->data++;
}

// delete Node of specific value
void CircularList::deleteNodeAtValue(int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;

    int n;
    cout << "--->Sentinel Node is not counted<---" << endl;
    cout << "enter no. of Node after that you insert a value:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;
    head->data++;
}

void CircularList::printll()
{
    Node *temp = head;
    cout << "[SENTINEL(count): " << temp->data << "] -> ";
    temp = temp->link;

    while (temp != head)
    {
        cout << temp->data << " -> ";
        temp = temp->link;
    }

    cout << "[back to SENTINEL]" << endl;
}
