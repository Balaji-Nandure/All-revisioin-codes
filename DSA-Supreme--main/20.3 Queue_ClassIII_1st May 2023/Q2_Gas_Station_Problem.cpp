/*
Approach (Balance + Deficit Method):
------------------------------------
1. Maintain:
   - balance = current fuel in the tank while moving.
   - deficit = fuel shortage accumulated when we couldn’t move forward.
2. Traverse the stations:
   - balance += gas[i] - cost[i]
   - If balance < 0:
        → we can't reach next station
        → add this deficit to total deficit
        → reset balance = 0
        → move start to i+1
3. After full loop:
   - If (balance + deficit) >= 0 → return start (possible)
   - Else → return -1 (impossible)

Time: O(n)
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int balance = 0;  // current fuel balance
    int deficit = 0;  // total shortage accumulated
    int start = 0;    // candidate starting station

    for (int i = 0; i < n; i++) {
        balance += gas[i] - cost[i];
        if (balance < 0) {
            // can't reach next station
            deficit += balance;
            balance = 0;
            start = i + 1;
        }
    }

    // total gas - total cost = balance + deficit
    if (balance + deficit >= 0)
        return start;
    return -1;
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
    -----------------------------------
    i=0 → bal=-2 (def=-2, start=1)
    i=1 → bal=-2 (def=-4, start=2)
    i=2 → bal=-2 (def=-6, start=3)
    i=3 → bal=+3
    i=4 → bal=+6
    balance=6, deficit=-6 → total=0 ✅
    Output → start=3
    */
}
