#include "huffman.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Huffman::heapify(Node* heap[], int size, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l]->freq < heap[smallest]->freq)
        smallest = l;
    if (r < size && heap[r]->freq < heap[smallest]->freq)
        smallest = r;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void Huffman::buildMinHeap(Node* heap[], int size) {
    for (int i = size/2 - 1; i >= 0; i--) {
        heapify(heap, size, i);
        if (i == 0) break;
    }
}

Node* Huffman::extractMin(Node* heap[], int &size) {
    Node* minNode = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(heap, size, 0);
    return minNode;
}

void Huffman::insertHeap(Node* heap[], int &size, Node* node) {
    int i = size;
    heap[size++] = node;

    while (i > 0 && heap[(i - 1) / 2]->freq > heap[i]->freq) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node* Huffman::buildTree(char chars[], int freq[], int n) {
    Node* heap[100];
    int size = n;

    for (int i = 0; i < n; i++)
        heap[i] = new Node(chars[i], freq[i]);

    buildMinHeap(heap, size);

    while (size > 1) {
        Node* left = extractMin(heap, size);
        Node* right = extractMin(heap, size);

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        insertHeap(heap, size, parent);
    }

    return heap[0];
}

void Huffman::printHelper(Node* root, int code[], int top) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->ch << " : ";
        for (int i = 0; i < top; i++)
            cout << code[i];
        cout << endl;
        return;
    }

    code[top] = 0;
    printHelper(root->left, code, top + 1);

    code[top] = 1;
    printHelper(root->right, code, top + 1);
}

void Huffman::printCodes(Node* root) {
    if (!root) return;
    int code[100];
    printHelper(root, code, 0);
}
