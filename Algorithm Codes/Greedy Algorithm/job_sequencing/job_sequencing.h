#ifndef JOB_SEQUENCING_H
#define JOB_SEQUENCING_H

#include "job.h"

// function signature unchanged
void jobSequencing(Job jobs[], int n, int dmax);

// global results (accessible in main)
extern int gSlot[];
extern int gSlotsCount;
extern int gTotalProfit;

#endif
