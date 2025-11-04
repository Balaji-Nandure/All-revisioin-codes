/*
    Gas Station Problem (Leetcode 134): 
    Given two integer arrays gas and cost, where gas[i] is the amount of gas at station i, and cost[i] is the cost of gas to travel from station i to i+1.
    The task is to find the starting gas station's index from which you can travel around the circuit once in the clockwise direction, otherwise return -1.

    Approach Used in This Code (Greedy, O(N)):
    - Traverse all stations, keep track of current balance (gas left after each station).
    - If at any point balance goes negative, it means we cannot reach the next station from the current start.
    - So, we set the next station as the new start and accumulate the deficit (shortage).
    - At the end, if total gas (balance + deficit) >= 0, then the answer is the start index, else -1.

    Why this works:
    - If the total gas is less than total cost, it's impossible to complete the circuit.
    - If we fail at station i, then any station between previous start and i cannot be the answer, so we skip them.

    Alternative Approaches:
    1. Brute Force (O(N^2)): Try starting from every station and simulate the journey. (Inefficient for large N)
    2. Prefix Sum: Not needed, as the greedy approach above is optimal.

    // Brute Force Alternative (for reference):
    /*
    int bruteForce(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int start = 0; start < n; ++start) {
            int tank = 0, cnt = 0, i = start;
            while(cnt < n) {
                tank += gas[i] - cost[i];
                if(tank < 0) break;
                i = (i + 1) % n;
                cnt++;
            }
            if(cnt == n && tank >= 0) return start;
        }
        return -1;
    }
    */

    // Dry Run Example:
    // gas  = [1,2,3,4,5]
    // cost = [3,4,5,1,2]
    // i=0: balance = 1-3 = -2 < 0, start=1, deficit=2, balance=0
    // i=1: balance = 0+2-4 = -2 < 0, start=2, deficit=4, balance=0
    // i=2: balance = 0+3-5 = -2 < 0, start=3, deficit=6, balance=0
    // i=3: balance = 0+4-1 = 3 >= 0
    // i=4: balance = 3+5-2 = 6 >= 0
    // At end: balance=6, deficit=6, so answer is start=3

*/

#include<iostream>
#include<vector>
using namespace std;

// Function to find the starting gas station index
int solve(vector<int>& gas, vector<int>& cost){
    int deficit = 0; // Total shortage encountered when balance goes negative
    int balance = 0; // Current petrol left in tank
    int start = 0;   // Candidate starting index

    // Traverse all stations
    for(int i = 0; i < gas.size(); i++){
        balance += gas[i] - cost[i]; // Update balance after visiting station i

        // If balance is negative, cannot reach next station from current start
        if(balance < 0){
            deficit += -balance; // Accumulate the shortage (deficit)
            start = i + 1;       // Set next station as new start
            balance = 0;         // Reset balance for new start
        }
    }

    // If total gas (balance) is enough to cover total deficit, return start index
    if(balance >= deficit){
        return start;
    }
    // Otherwise, not possible to complete the circuit
    return -1;
}

int main(){
    // Example input
    vector<int> gas {1,2,3,4,5};
    vector<int> cost {3,4,5,1,2};

    int ans = solve(gas, cost); // Find starting index
    cout << "Starting index = " << ans << endl;

    /*
        Dry Run:
        gas  = [1,2,3,4,5]
        cost = [3,4,5,1,2]
        i=0: balance = 1-3 = -2 < 0, start=1, deficit=2, balance=0
        i=1: balance = 0+2-4 = -2 < 0, start=2, deficit=4, balance=0
        i=2: balance = 0+3-5 = -2 < 0, start=3, deficit=6, balance=0
        i=3: balance = 0+4-1 = 3 >= 0
        i=4: balance = 3+5-2 = 6 >= 0
        At end: balance=6, deficit=6, so answer is start=3
    */

    return 0;
}