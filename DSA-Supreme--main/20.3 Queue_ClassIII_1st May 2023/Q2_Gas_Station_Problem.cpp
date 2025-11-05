/*
Problem:
---------
You are given two arrays:
- gas[i]   : amount of gas at station i
- cost[i]  : amount of gas required to travel from station i to (i+1)

Find the starting gas station index from which you can complete the circuit once.
If it's not possible, return -1.

Constraints:
- You can start at any station.
- You travel in a circular route.

Approach:
----------
1. If total gas < total cost → impossible → return -1.
2. Otherwise, one pass:
   - Maintain `tank` (current fuel in tank).
   - Traverse stations:
        tank += gas[i] - cost[i]
        if tank < 0:
            → can't reach next station → reset start to i+1
            → tank = 0
3. The valid start index (if any) will be the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int totalGas = 0, totalCost = 0;
    int tank = 0, start = 0;

    for (int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        // If can't reach next station, reset start
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    // If total gas is less than total cost → not possible
    return (totalGas < totalCost) ? -1 : start;
}

int main() {
    vector<int> gas  = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int start = canCompleteCircuit(gas, cost);

    if (start != -1)
        cout << "Start at station index: " << start << "\n";
    else
        cout << "No valid starting point.\n";

    /*
    Dry Run:
    gas  = [1,2,3,4,5]
    cost = [3,4,5,1,2]

    totalGas = 15, totalCost = 15 (✅ possible)
    Traverse:
     i=0: tank = -2 → can't continue → start=1, tank=0
     i=1: tank = -2 → start=2
     i=2: tank = -2 → start=3
     i=3: tank = +3
     i=4: tank = +6
    ✅ start = 3
    */
}
