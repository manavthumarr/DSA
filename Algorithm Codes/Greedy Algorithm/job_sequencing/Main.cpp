#include <iostream>
#include "job_sequencing.h"

using namespace std;

int main() {

    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    cout << "Enter deadline and profit for each job:\n";
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        cin >> jobs[i].deadline >> jobs[i].profit;
    }

    // compute maximum deadline
    int dmax = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > dmax)
            dmax = jobs[i].deadline;

    // call algorithm
    jobSequencing(jobs, n, dmax);

    // ---------- OUTPUT ----------
    cout << "\nScheduled Jobs (slot-wise): ";
    for (int i = 0; i < gSlotsCount; i++) {
        if (gSlot[i] != -1)
            cout << "J" << gSlot[i] << " ";
    }

    cout << "\nTotal Profit: " << gTotalProfit << endl;

    return 0;
}
