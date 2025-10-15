#include "quick_sort_knapsack.h"
#include <iostream>

using namespace std;

//Partition for quick sort
int partitions(Item arr[],double avg[],int first_index,int last_index)
{
double x=avg[last_index];
int i=first_index-1;

for(int j=first_index;j<=last_index-1;j++){
    if(avg[j]>x){
        i=i+1;
        swap(arr[i],arr[j]);
        swap(avg[i],avg[j]);
    }
}

i=i+1;
swap(arr[i],arr[last_index]);
swap(avg[i],avg[last_index]);

return i;
}

// Quick sort 
void quick_sort(Item arr[],double avg[],int first_index,int last_index) 
{
if(first_index<last_index){
int q;                                            // q is index of partion
    q=partitions(arr,avg,first_index,last_index);

    quick_sort(arr,avg,first_index,q-1);
    quick_sort(arr,avg,q+1,last_index);
}
}
