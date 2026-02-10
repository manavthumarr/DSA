#include <iostream>
#include "huffman.h"

using namespace std;

int main() {
    int n;
    cout<<"enter no. of char you have to enter:-";
    cin>>n;
    char chars[n];
    int freq[n];

    for(int i=0; i<n; i++){
        cout<<"enter char "<<i+1<<":-";
        cin>>chars[i];
        cout<<"enter freq for "<<chars[i]<<":-";
        cin>>freq[i];
    }

    Huffman h;
    Node* root = h.buildTree(chars, freq, n);

    cout << "Huffman Codes:\n";
    h.printCodes(root);

    return 0;
}
