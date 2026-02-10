#ifndef NODE_H
#define NODE_H

class Node {
public:
    char ch;
    int freq;
    Node *left;
    Node *right;

    
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }
};

#endif
