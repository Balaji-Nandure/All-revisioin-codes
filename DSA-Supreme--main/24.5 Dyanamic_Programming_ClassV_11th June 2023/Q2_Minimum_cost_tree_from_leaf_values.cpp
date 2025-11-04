// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

/*
Approach Used:
---------------
This code solves the "Minimum Cost Tree From Leaf Values" problem using Dynamic Programming (DP).
The problem is to build a binary tree from an array of leaf values such that the sum of the values of each non-leaf node (which is the product of the largest leaf in its left and right subtree) is minimized.

The code provides three approaches:
1. Pure Recursion (solveRec)
2. Top-Down DP (Memoization) (solveTopDown)
3. Bottom-Up DP (Tabulation) (solveTab) -- This is used in the final solution.

Key Idea:
----------
- For every possible partition of the array into two subarrays, recursively compute the minimum cost for left and right subarrays, and add the product of their maximum values.
- Use DP to avoid recomputation.

Better Alternative:
-------------------
There is a more optimal O(n) Greedy Stack-based approach (see below in comments) which is much faster than DP (O(n^2)), but here we focus on DP as per the code.

*/

// Main Solution class
class Solution {
public:
    // Pure Recursive Approach (Exponential Time)
    int solveRec(vector<int>& arr, map<pair<int,int>,int>& maxi, int left, int right){
        // Base case: If only one element, no cost to combine
        if(left == right){
            return 0; // No non-leaf node can be formed
        }
        int ans = INT_MAX; // Initialize answer to maximum
        // Try every possible partition between left and right
        for(int i = left; i < right; i++){
            // Calculate cost for this partition:
            // 1. Product of max in left and right subarrays
            // 2. Recursively solve for left and right subarrays
            int cost = maxi[{left,i}] * maxi[{i+1,right}] + solveRec(arr, maxi, left, i) + solveRec(arr, maxi, i+1, right);
            ans = min(ans, cost); // Take minimum over all partitions
        }
        return ans;
    }

    // Top-Down DP (Memoization)
    int solveTopDown(vector<int>& arr, map<pair<int,int>,int>& maxi, int left, int right, vector<vector<int>>& dp){
        // Base case: single element, no cost
        if(left == right){
            return 0;
        }
        // If already computed, return stored value
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = INT_MAX;
        // Try all partitions
        for(int i = left; i < right; i++){
            int cost = maxi[{left,i}] * maxi[{i+1,right}] + solveTopDown(arr, maxi, left, i, dp) + solveTopDown(arr, maxi, i+1, right, dp);
            ans = min(ans, cost);
        }
        dp[left][right] = ans; // Store result for future
        return dp[left][right];
    }

    // Bottom-Up DP (Tabulation)
    int solveTab(vector<int>& arr, map<pair<int,int>,int>& maxi){
        int n = arr.size();
        // dp[left][right] = minimum cost to build tree from arr[left...right]
        vector<vector<int>> dp(n, vector<int>(n, 0)); // Initialize dp array to 0

        // Fill dp for all subarray lengths > 1
        for(int len = 2; len <= n; len++){ // subarray length
            for(int left = 0; left <= n - len; left++){
                int right = left + len - 1;
                dp[left][right] = INT_MAX;
                // Try all partitions
                for(int i = left; i < right; i++){
                    int cost = maxi[{left,i}] * maxi[{i+1,right}] + dp[left][i] + dp[i+1][right];
                    dp[left][right] = min(dp[left][right], cost);
                }
            }
        }
        // The answer for the whole array is dp[0][n-1]
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi; // Stores max value in arr[i...j] for all i,j

        // Pre-computation: Fill maxi for all subarrays
        for(int i = 0; i < arr.size(); i++){
            maxi[{i,i}] = arr[i]; // Single element
            for(int j = i+1; j < arr.size(); j++){
                // Maximum in arr[i...j] is max of arr[j] and max in arr[i...j-1]
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        int n = arr.size();

        // Uncomment below to use recursive or top-down DP approach:
        // int ans = solveRec(arr, maxi, 0, n-1);

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // int ans = solveTopDown(arr, maxi, 0, n-1, dp);

        // Use Bottom-Up DP (Tabulation) for best performance among DP approaches
        int ans = solveTab(arr, maxi);
        return ans;
    }
};

/*
-------------------------------
Better Alternative: Greedy Stack Approach (O(n))
-------------------------------
The optimal solution uses a monotonic decreasing stack. At each step, combine the two smallest leaves (locally) to minimize the cost.

Code:
-------
int mctFromLeafValues(vector<int>& arr) {
    int res = 0;
    stack<int> st;
    st.push(INT_MAX); // Sentinel
    for(int a : arr){
        while(st.top() <= a){
            int mid = st.top(); st.pop();
            res += mid * min(st.top(), a);
        }
        st.push(a);
    }
    while(st.size() > 2){
        int mid = st.top(); st.pop();
        res += mid * st.top();
    }
    return res;
}

-------------------------------
Dry Run Example:
-------------------------------
Input: arr = [6,2,4]

Step 1: Precompute maxi:
    maxi[{0,0}] = 6
    maxi[{0,1}] = max(6,2) = 6
    maxi[{0,2}] = max(6,2,4) = 6
    maxi[{1,1}] = 2
    maxi[{1,2}] = max(2,4) = 4
    maxi[{2,2}] = 4

Step 2: DP Table (Bottom-Up):
    For subarray [0,1]: cost = 6*2 = 12
    For subarray [1,2]: cost = 2*4 = 8
    For subarray [0,2]:
        Partition at i=0: cost = maxi[{0,0}]*maxi[{1,2}] + dp[0][0] + dp[1][2] = 6*4 + 0 + 8 = 32
        Partition at i=1: cost = maxi[{0,1}]*maxi[{2,2}] + dp[0][1] + dp[2][2] = 6*4 + 12 + 0 = 36
        Take min(32,36) = 32

Final Answer: 32

-------------------------------
Summary of Approaches:
-------------------------------
- Recursion: Simple but exponential time.
- Top-Down DP: Memoizes overlapping subproblems, O(n^3) time, O(n^2) space.
- Bottom-Up DP: Iterative, O(n^3) time, O(n^2) space.
- Greedy Stack: O(n) time, O(n) space, optimal for this problem.
*/