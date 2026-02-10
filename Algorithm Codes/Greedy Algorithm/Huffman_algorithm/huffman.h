#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "node.h"

class Huffman {
private:
    void heapify(Node* heap[], int size, int i);
    void buildMinHeap(Node* heap[], int size);
    Node* extractMin(Node* heap[], int &size);
    void insertHeap(Node* heap[], int &size, Node* node);

    void printHelper(Node* root, int code[], int top);

public:
    Node* buildTree(char chars[], int freq[], int n);
    void printCodes(Node* root);
};

#endif
