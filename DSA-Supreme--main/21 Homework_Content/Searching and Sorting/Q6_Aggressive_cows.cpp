// https://practice.geeksforgeeks.org/problems/aggressive-cows/1

/*
Approach Used in This Code (Binary Search on Answer Space):
-----------------------------------------------------------
- The problem is to place k cows in n stalls (given their positions) such that the minimum distance between any two cows is maximized.
- We use Binary Search on the answer space (the minimum possible distance between any two cows).
- For each candidate distance (mid), we check if it is possible to place all cows such that the minimum distance between any two cows is at least mid.
- If possible, we try for a larger distance (move right); otherwise, we try for a smaller distance (move left).

Time Complexity: O(n*log(maxD)), where maxD = stalls[n-1] - stalls[0]
Space Complexity: O(1) extra (excluding input)

-----------------------------------------------------------
Better Alternative Approaches (with code):
-----------------------------------------------------------
1. **Brute Force (Inefficient, O((maxD)*n)):**
   - Try every possible distance from 1 to maxD, and for each, check if placement is possible.
   - Not recommended for large n.

   // Brute Force Code:
   /*
   int maxMinDist(vector<int>& stalls, int n, int k) {
       sort(stalls.begin(), stalls.end());
       int maxD = stalls[n-1] - stalls[0];
       int ans = 0;
       for (int d = 1; d <= maxD; ++d) {
           int cows = 1, last = stalls[0];
           for (int i = 1; i < n; ++i) {
               if (stalls[i] - last >= d) {
                   cows++;
                   last = stalls[i];
               }
           }
           if (cows >= k) ans = d;
           else break;
       }
       return ans;
   }
   */

2. **Binary Search on Answer (Optimal, as in this code):**
   - Most efficient for this problem.

-----------------------------------------------------------
Detailed Code with Comments and Dry Run:
-----------------------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function to check if it is possible to place k cows with at least 'dist' distance apart
    bool isPossible(const vector<int>& stalls, int n, int k, int dist) {
        int cowCount = 1;                // Place first cow at the first stall
        int lastPos = stalls[0];         // Position of last placed cow

        // Try to place remaining cows greedily
        for (int i = 1; i < n; i++) {
            // If the current stall is at least 'dist' away from last placed cow
            if (stalls[i] - lastPos >= dist) {
                cowCount++;              // Place a cow here
                lastPos = stalls[i];     // Update last placed position
                if (cowCount == k)       // If all cows placed, return true
                    return true;
            }
        }
        // Not possible to place all cows with at least 'dist' distance
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        // Sort the stalls to allow greedy placement and binary search
        sort(stalls.begin(), stalls.end());

        // Define the search space for the answer
        int start = 1;                        // Minimum possible distance (cannot be 0)
        int end = stalls[n-1] - stalls[0];    // Maximum possible distance
        int ans = 0;                          // Store the best answer found

        // Binary search on the answer space
        while (start <= end) {
            int mid = start + (end - start) / 2; // Candidate minimum distance

            // Check if it is possible to place all cows with at least 'mid' distance
            if (isPossible(stalls, n, k, mid)) {
                ans = mid;                     // Update answer
                start = mid + 1;               // Try for a bigger distance
            } else {
                end = mid - 1;                 // Try for a smaller distance
            }
        }
        return ans; // Maximum minimum distance possible
    }
};

/*
-------------------------------
Dry Run Example:
-------------------------------
Input: n = 5, k = 3, stalls = [1, 2, 8, 4, 9]

Step 1: Sort stalls: [1, 2, 4, 8, 9]
start = 1, end = 8 (9-1), ans = 0

Binary Search Iterations:
-------------------------
1st Iteration:
    mid = (1+8)/2 = 4
    isPossible(..., 4): Place cows at 1, 4, 8 (distances: 3, 4) => Only 3 cows placed, so possible.
    ans = 4, start = 5

2nd Iteration:
    mid = (5+8)/2 = 6
    isPossible(..., 6): Place at 1, next possible at 8 (distance 7), only 2 cows placed (not enough).
    end = 5

3rd Iteration:
    mid = (5+5)/2 = 5
    isPossible(..., 5): Place at 1, next at 8 (distance 7), only 2 cows placed.
    end = 4

Loop ends (start > end). Final answer: ans = 4

-------------------------------
So, the largest minimum distance possible is 4.
-------------------------------
*/