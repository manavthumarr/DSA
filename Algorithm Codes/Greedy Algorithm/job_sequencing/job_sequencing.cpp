#include <algorithm>
#include "job_sequencing.h"

using namespace std;

// ---------- GLOBAL VARIABLES ----------
int gSlot[100];        // slot array (0-based)
int gSlotsCount = 0;   // number of valid slots
int gTotalProfit = 0; // total profit

// ---------- COMPARATOR ----------
bool compare(Job a, Job b) {
    return a.profit > b.profit; // descending profit
}

// ---------- JOB SEQUENCING ----------
void jobSequencing(Job jobs[], int n, int dmax) {

    // Step 1: sort jobs by profit
    sort(jobs, jobs + n, compare);

    // Step 2: compute usable slots
    gSlotsCount = min(dmax, n);

    // Step 3: initialize slots
    for (int i = 0; i < gSlotsCount; i++)
        gSlot[i] = -1;

    gTotalProfit = 0;

    // Step 4: schedule jobs
    for (int i = 0; i < n; i++) {

        // deadline is end time → index = deadline - 1
        int lastSlot = min(gSlotsCount, jobs[i].deadline) - 1;

        for (int j = lastSlot; j >= 0; j--) {
            if (gSlot[j] == -1) {
                gSlot[j] = jobs[i].id;
                gTotalProfit += jobs[i].profit;
                break;
            }
        }
    }
}
