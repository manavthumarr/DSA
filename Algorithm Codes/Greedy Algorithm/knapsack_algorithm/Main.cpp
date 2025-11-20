#include "knapsack.h"
#include<iostream>
using namespace std;


int main(){
    int n,capacity;
    cout<<"enter space of bag:";
    cin>>capacity;

    cout<<"no. items you have to store:";
    cin>>n;

    Item arr[n]; 
    
    for(int i=0 ; i<n ; i++){
        cout<<"enter the value for item-"<<i+1<<endl;
        arr[i].input();
    }
  
    cout<<"max profit:-"<<knapsack(arr,n,capacity);

    
    
    return 0;
}