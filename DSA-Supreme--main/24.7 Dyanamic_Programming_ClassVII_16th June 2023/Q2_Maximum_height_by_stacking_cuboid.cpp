// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

/*
Approach Used:
---------------
- The problem is a variation of the Longest Increasing Subsequence (LIS) in 3D.
- Each cuboid can be rotated so that its dimensions are sorted (width <= length <= height).
- We sort all cuboids so that we can try to stack them in order.
- For each cuboid, we decide whether to include it in the stack (if it fits on the previous one) or not.
- We use space-optimized dynamic programming (bottom-up) to compute the maximum stack height.

Better Alternatives:
--------------------
1. **Memoization (Top-Down DP):**
   - Use recursion with memoization to avoid recomputation.
   - More intuitive but uses more stack space.

2. **Tabulation (Bottom-Up DP):**
   - Use a 2D DP table to store results for all subproblems.
   - More space but easier to debug.

3. **Space Optimized DP (Used here):**
   - Only keep two rows (current and next) to save space.

Alternative Code (Memoization):
-------------------------------
/*
int solve(int curr, int prev, vector<vector<int>>& nums, vector<vector<int>>& dp) {
    if (curr == nums.size()) return 0;
    if (dp[curr][prev+1] != -1) return dp[curr][prev+1];
    int include = 0;
    if (prev == -1 || (nums[curr][0] >= nums[prev][0] && nums[curr][1] >= nums[prev][1] && nums[curr][2] >= nums[prev][2])) {
        include = nums[curr][2] + solve(curr+1, curr, nums, dp);
    }
    int exclude = solve(curr+1, prev, nums, dp);
    return dp[curr][prev+1] = max(include, exclude);
}
*/

class Solution {
public:
    // Helper function to check if cuboid 'b' can be placed on cuboid 'a'
    bool check(const vector<int>& a, const vector<int>& b){
        // All dimensions of b must be <= corresponding dimensions of a
        return (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2]);
    }

    // Space optimized DP to find max stack height
    int spaceOpt(vector<vector<int>>& nums){
        int n = nums.size();
        vector<int> currRow(n+1, 0); // DP for current row (curr index)
        vector<int> nextRow(n+1, 0); // DP for next row (curr+1 index)

        // Iterate from last cuboid to first
        for(int curr = n - 1; curr >= 0; curr--){
            // For each possible previous cuboid (prev), including -1 (no previous)
            for(int prev = curr-1; prev >= -1; prev--){
                int include = 0;
                // If prev == -1 (no previous cuboid) or current cuboid can be placed on prev
                if(prev == -1 || check(nums[curr], nums[prev])){
                    // Include current cuboid: add its height and move to next
                    include = nums[curr][2] + nextRow[curr+1];
                }
                // Exclude current cuboid: move to next without adding height
                int exclude = nextRow[prev+1];
                // Store the best of including or excluding current cuboid
                currRow[prev+1] = max(include, exclude);
            }
            // Move to next row for next iteration
            nextRow = currRow;
        }
        // The answer is the max height with no previous cuboid
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: Sort dimensions of each cuboid so we can rotate them freely
        for(auto &a : cuboids){
            sort(a.begin(), a.end());
        }
        // Step 2: Sort all cuboids to ensure a valid stacking order
        sort(cuboids.begin(), cuboids.end());
        // Step 3: Apply space optimized DP to get the answer
        int ans = spaceOpt(cuboids);
        return ans;
    }
};

/*
Dry Run Example:
----------------
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]

Step 1: Sort each cuboid:
    [20,45,50], [37,53,95], [12,23,45]

Step 2: Sort all cuboids:
    [[12,23,45], [20,45,50], [37,53,95]]

Step 3: DP (from last to first):
    - Try to stack each cuboid on top of previous ones.
    - For each, decide to include or exclude, and take max.

Result: Maximum height = 190

Alternative Approach (Tabulation):
----------------------------------
int maxHeight(vector<vector<int>>& cuboids) {
    for(auto &a : cuboids) sort(a.begin(), a.end());
    sort(cuboids.begin(), cuboids.end());
    int n = cuboids.size();
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i) {
        dp[i] = cuboids[i][2];
        for(int j = 0; j < i; ++j) {
            if(cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                dp[i] = max(dp[i], cuboids[i][2] + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
*/