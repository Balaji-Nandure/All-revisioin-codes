#include <vector>
using namespace std;

/*
Approach:
We use backtracking to find all possible arrangements of numbers 1 to n
such that for every position i (1-based), either the number at that
position is divisible by i or i is divisible by the number.
We keep track of which numbers are already used (visited).
Whenever a valid arrangement is found (all positions filled), we increment the count.
*/

class Solution {
public:
    int countArrangement(int n) {
        // Initialize a boolean vector to mark which numbers have been used in the arrangement
        vector<bool> visited(n+1, false); // 1-indexed, so size n+1
        int count = 0; // To store number of beautiful arrangements
        // Start backtracking from position 1
        backtrack(n, 1, visited, count);
        // Return the total count of valid arrangements
        return count;
    }

    // Helper function for backtracking
    // n: total number, pos: current position, visited: marks used numbers, count: reference to result counter
    void backtrack(int n, int pos, vector<bool>& visited, int& count) {
        // If all positions are filled, found a valid arrangement
        if (pos > n) {
            count++; // Increment the result count
            return;
        }  
        // Try each number from 1 to n at current position
        for (int i = 1; i <= n; ++i) {
            // If number i has not been used yet and satisfies divisibility condition
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true; // Mark number i as used
                backtrack(n, pos+1, visited, count); // Recurse to next position
                visited[i] = false; // Backtrack: mark number i as unused for next iteration
            }
        }
    }
};
