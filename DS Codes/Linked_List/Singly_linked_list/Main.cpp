#include "List.h"

#include <iostream>

using namespace std;

int main()
{
    List ll;
    int choice, value, n = 1;
    while (n)
    {
        cout << "enter choice for following operation" << endl;
        cout << "1.insert from start" << endl;
        cout << "2.insert from end" << endl;
        cout << "3.insert after nth node" << endl;
        cout << "4.delete node from start" << endl;
        cout << "5.delete node from end" << endl;
        cout << "6.delete node at any value" << endl;
        cout << "7.Reverse a linked list" << endl;
        cout << "8.exit" << endl;
        cout << "enter choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter your data:";
            cin >> value;
            ll.fromStart(value);
            break;
        case 2:
            cout << "enter your data:";
            cin >> value;
            ll.fromEnd(value);
            break;
        case 3:
            cout << "enter your data:";
            cin >> value;
            ll.InsertAt_NthNode(value);
            break;
        case 4:
            ll.deleteFromStart();
            break;
        case 5:
            ll.deleteFromEnd();
            break;
        case 6:
            cout << "enter node data:";
            cin >> value;
            ll.deleteNodeAtValue(value);
            break;
        case 7:
            ll.rev_ll(ll.gethead());
            break;
        case 8:
            cout << "exit" << endl;
            n = 0;
            break;
        default:
            cout << "enter a valid choice";
            break;
        }
        cout << "updated linked list:" << endl;
        printList(ll.gethead());
    }
    cout << "your final list:" << endl;
    printList(ll.gethead());
    return 0;
}