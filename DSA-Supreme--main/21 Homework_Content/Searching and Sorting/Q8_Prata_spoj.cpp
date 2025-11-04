/*
    SPOJ PRATA Problem: https://www.spoj.com/problems/PRATA/

    Approach Used in This Code (Binary Search on Answer Space):
    -----------------------------------------------------------
    - We are given P parathas to cook and L cooks, each with a rank Ri.
    - The ith paratha by a cook with rank R takes i*R minutes (1st: R, 2nd: 2R, 3rd: 3R, ...).
    - We need to find the minimum time required to cook all P parathas using all cooks optimally.

    - We use Binary Search on the answer space (the minimum possible time required).
    - For each candidate time (mid), we check if it is possible to cook all P parathas within 'mid' minutes using all cooks.
    - If possible, we try to minimize further (move left); otherwise, we increase the allowed time (move right).

    Time Complexity: O(P * L * log(maxTime)), where maxTime is the upper bound for time.
    Space Complexity: O(L) for storing cook ranks.

    -----------------------------------------------------------
    Better Alternative Approaches (with code):
    -----------------------------------------------------------
    1. **Brute Force (Inefficient, O(P^2 * L)):**
       - Try every possible time from 1 to maxTime, and for each, check if all parathas can be cooked.
       - Not recommended for large P or L.

       // Brute Force Code:
       /*
       int bruteForce(vector<int>& cookRanks, int nP) {
           int maxTime = 1e8;
           for (int t = 1; t <= maxTime; ++t) {
               if (isPossible(cookRanks, nP, t)) return t;
           }
           return -1;
       }
       */

    2. **Binary Search on Answer (Optimal, as in this code):**
       - Most efficient for this problem.

    -----------------------------------------------------------
    Dry Run Example:
    -----------------------------------------------------------
    Suppose:
    - nP = 3 (parathas)
    - nC = 2 (cooks)
    - cookRanks = [1, 2]

    Let's see how the binary search and isPossible work for this input at the end of the code.

*/

// Include necessary headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Helper function to check if it is possible to cook all parathas within 'solution' minutes
bool isPossible(const vector<int>& cookRanks, int nP, int solution) {
    int currP = 0; // Current total parathas cooked

    // For each cook, calculate how many parathas they can make in 'solution' time
    for (int i = 0; i < cookRanks.size(); i++) {
        int R = cookRanks[i]; // Rank of current cook
        int timeTaken = 0;    // Time spent by this cook
        int j = 1;            // Paratha number (1-based)

        // Each next paratha takes j*R time
        while (timeTaken + j * R <= solution) {
            timeTaken += j * R; // Add time for j-th paratha
            currP++;            // Increment total parathas cooked
            j++;                // Next paratha
            if (currP >= nP)    // If required parathas cooked, return true
                return true;
        }
    }
    // If not enough parathas cooked, return false
    return false;
}

// Function to find the minimum time required to cook all parathas
int minTime(const vector<int>& cookRanks, int nP) {
    int start = 0; // Minimum possible time
    int highestRank = *min_element(cookRanks.begin(), cookRanks.end()); // Use min rank for tighter upper bound
    // Maximum time: slowest cook making all parathas alone (sum of AP: R * (nP*(nP+1))/2)
    int end = highestRank * (nP * (nP + 1)) / 2;
    int ans = -1; // Store the minimum time found

    // Binary search on time
    while (start <= end) {
        int mid = start + (end - start) / 2; // Candidate time
        if (isPossible(cookRanks, nP, mid)) {
            ans = mid;        // Store possible answer
            end = mid - 1;    // Try to find a smaller time
        } else {
            start = mid + 1;  // Need more time
        }
    }
    return ans;
}

int main() {
    int T; // Number of test cases
    cin >> T;
    while (T--) {
        int nP, nC;
        cin >> nP >> nC; // nP: number of parathas, nC: number of cooks
        vector<int> cookRanks(nC);
        for (int i = 0; i < nC; ++i) {
            cin >> cookRanks[i]; // Input ranks of cooks
        }
        cout << minTime(cookRanks, nP) << endl; // Output minimum time for this test case
    }
    return 0;
}

/*
-----------------------------------------------------------
Dry Run Example:
-----------------------------------------------------------
Input:
1
3 2
1 2

Explanation:
- 1 test case, 3 parathas, 2 cooks with ranks 1 and 2.

Step 1: Calculate upper bound for binary search:
- minRank = 1
- end = 1 * (3*4)/2 = 6

Binary search on [0, 6]:
- mid = 3
  isPossible([1,2], 3, 3):
    Cook 1 (R=1): 1st paratha: 1 (ok), 2nd: 1+2=3 (ok), 3rd: 3+3=6 (>3, stop). Cook 1 made 2 parathas.
    Cook 2 (R=2): 1st: 2 (ok), 2nd: 2+4=6 (>3, stop). Cook 2 made 1 paratha.
    Total: 2+1=3 parathas. So possible.
  So, ans=3, end=2

- mid = 1
  isPossible([1,2], 3, 1):
    Cook 1: 1st: 1 (ok), 2nd: 1+2=3 (>1, stop). 1 paratha.
    Cook 2: 1st: 2 (>1, stop). 0 paratha.
    Total: 1 paratha. Not enough.
  So, start=2

- mid = 2
  isPossible([1,2], 3, 2):
    Cook 1: 1st: 1 (ok), 2nd: 1+2=3 (>2, stop). 1 paratha.
    Cook 2: 1st: 2 (ok), 2nd: 2+4=6 (>2, stop). 1 paratha.
    Total: 2 parathas. Not enough.
  So, start=3

Now start=3, end=2, so loop ends. Minimum time = 3.

Output: 3

-----------------------------------------------------------
*/