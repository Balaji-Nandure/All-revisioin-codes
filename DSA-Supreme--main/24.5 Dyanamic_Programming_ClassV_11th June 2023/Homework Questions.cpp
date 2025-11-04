/*
1) Unique Binary Search Trees

Approach Used:
----------------
We are to find the number of structurally unique BSTs (binary search trees) that store values 1...n.
This is a classic DP problem, and the answer is the nth Catalan number.

Logic:
-------
- For each number i from 1 to n, consider it as the root.
- The left subtree will have (i-1) nodes, and the right subtree will have (n-i) nodes.
- The total number of unique BSTs with n nodes is the sum over all i of:
    (number of unique BSTs in left subtree) * (number of unique BSTs in right subtree)

DP Formula:
-----------
Let dp[n] = number of unique BSTs with n nodes.
dp[0] = 1 (empty tree)
dp[1] = 1 (single node tree)
For n >= 2:
    dp[n] = sum_{i=1 to n} (dp[i-1] * dp[n-i])

Below is the C++ implementation with comments explaining each step.
Also, alternative approaches and optimizations are discussed in comments.

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate number of unique BSTs for given n
int numTrees(int n) {
    // dp[i] will store the number of unique BSTs with i nodes
    vector<int> dp(n+1, 0);

    // Base cases
    dp[0] = 1; // Empty tree
    dp[1] = 1; // Single node tree

    // Fill dp[] using the recursive formula
    for(int nodes = 2; nodes <= n; ++nodes) {
        // For each possible root node
        for(int root = 1; root <= nodes; ++root) {
            // Number of unique BSTs with 'root' as root is:
            // (number of left subtrees) * (number of right subtrees)
            dp[nodes] += dp[root-1] * dp[nodes-root];
        }
    }
    return dp[n];
}

int main() {
    int n = 3;
    cout << "Number of unique BSTs with " << n << " nodes: " << numTrees(n) << endl;
    return 0;
}

/*
Alternative Approaches:
-----------------------
1. Catalan Number Formula (Mathematical Approach):
   The number of unique BSTs with n nodes is the nth Catalan number:
   C(n) = (2n)! / ((n+1)! * n!)
   This can be computed directly using combinatorics for O(n) time and O(1) space.

   // C++ code for Catalan number approach:
   int numTreesCatalan(int n) {
       long long res = 1;
       for(int i = 0; i < n; ++i) {
           res = res * 2 * (2*i + 1) / (i + 2);
       }
       return (int)res;
   }

2. Recursive Approach (Not recommended for large n due to exponential time):
   int numTreesRec(int n) {
       if(n <= 1) return 1;
       int total = 0;
       for(int i = 1; i <= n; ++i) {
           total += numTreesRec(i-1) * numTreesRec(n-i);
       }
       return total;
   }

Dry Run (for n = 3):
---------------------
dp[0] = 1
dp[1] = 1

For nodes = 2:
    root = 1: dp[1-1] * dp[2-1] = dp[0]*dp[1] = 1*1 = 1
    root = 2: dp[2-1] * dp[2-2] = dp[1]*dp[0] = 1*1 = 1
    dp[2] = 1 + 1 = 2

For nodes = 3:
    root = 1: dp[0]*dp[2] = 1*2 = 2
    root = 2: dp[1]*dp[1] = 1*1 = 1
    root = 3: dp[2]*dp[0] = 2*1 = 2
    dp[3] = 2 + 1 + 2 = 5

So, number of unique BSTs with 3 nodes = 5

*/
