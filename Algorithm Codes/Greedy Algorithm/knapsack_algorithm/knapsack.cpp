#include "knapsack.h"

double knapsack(Item arr[],int n,int capacity) // n is no. of items
{
    double avg[n],p=0;
    int i;
      for(int j=0 ; j<n ; j++){
       avg[j]=double(arr[j].profit)/arr[j].weight;
      }

     quick_sort(arr,avg,0,n-1);

     for(i=0 ; i<n ; i++){
    if(capacity>0 && capacity>=arr[i].weight){
        capacity=capacity-arr[i].weight;
        p=p+arr[i].profit;
    }
    else if(capacity>0){
        p=p+arr[i].profit * (double(capacity)/arr[i].weight);
        capacity=0;
        break;
    }
}
    return p;
}
