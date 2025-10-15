#ifndef QUICK_SORT_KNAPSACK
#define QUICK_SORT_KNAPSACK

#include "Item.h"


int partitions(Item arr[],double avg[],int first_index,int last_index); //Partition for quick sort


void quick_sort(Item arr[],double avg[],int first_index,int last_index); // Quick sort

#endif