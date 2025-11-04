/*
Approach Used:
--------------
This file lists classic Dynamic Programming (DP) homework problems, grouped by 1D and 2D DP. 
Below, for each problem, we provide:
- A brief description and the main approach.
- Key lines with comments explaining the logic.
- Better alternatives (if any) with code snippets in comments.
- A dry run for at least one problem at the end.

----------------------------------------------------------
1D DP
----------------------------------------------------------
1) Count Derangements (No element appears in its original position)
----------------------------------------------------------
Problem: Given n items, count the number of ways to derange them (no item is in its original place).

// Recursive + Memoization Approach
int countDerangements(int n, vector<int>& dp) {
    // Base cases
    if (n == 1) return 0; // Only one item, can't derange
    if (n == 2) return 1; // Only one way to swap two items
    if (dp[n] != -1) return dp[n]; // If already computed, return stored value

    // Recurrence: D(n) = (n-1) * (D(n-1) + D(n-2))
    dp[n] = (n - 1) * (countDerangements(n - 1, dp) + countDerangements(n - 2, dp));
    return dp[n];
}

/*
Better Alternative: Bottom-Up DP (Tabulation)
---------------------------------------------
int countDerangementsBU(int n) {
    vector<long long> dp(n+1, 0);
    dp[1] = 0; // Base case
    if (n >= 2) dp[2] = 1; // Base case
    for (int i = 3; i <= n; ++i) {
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    }
    return dp[n];
}
*/

----------------------------------------------------------
2D DP
----------------------------------------------------------
2) Equal Subset Sum Partition
----------------------------------------------------------
Problem: Given an array, can it be partitioned into two subsets with equal sum?

// Top-Down DP (Memoization)
bool canPartition(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
    // Base cases
    if (sum == 0) return true; // Found a subset
    if (n == 0) return false;  // No elements left

    if (dp[n][sum] != -1) return dp[n][sum];

    // If current element is less than or equal to sum, we can include or exclude it
    if (nums[n-1] <= sum) {
        dp[n][sum] = canPartition(nums, n-1, sum-nums[n-1], dp) || canPartition(nums, n-1, sum, dp);
    } else {
        dp[n][sum] = canPartition(nums, n-1, sum, dp);
    }
    return dp[n][sum];
}

/*
Better Alternative: Bottom-Up DP (Tabulation)
---------------------------------------------
bool canPartitionBU(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;
    int sum = total / 2;
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (nums[i-1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
*/

----------------------------------------------------------
3) Subset Sum
----------------------------------------------------------
Problem: Given an array and a sum, is there a subset with sum equal to given sum?

// Top-Down DP (Memoization)
bool isSubsetSum(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
    // Base cases
    if (sum == 0) return true;
    if (n == 0) return false;
    if (dp[n][sum] != -1) return dp[n][sum];

    if (nums[n-1] <= sum) {
        dp[n][sum] = isSubsetSum(nums, n-1, sum-nums[n-1], dp) || isSubsetSum(nums, n-1, sum, dp);
    } else {
        dp[n][sum] = isSubsetSum(nums, n-1, sum, dp);
    }
    return dp[n][sum];
}

/*
Better Alternative: Bottom-Up DP (Tabulation)
---------------------------------------------
bool isSubsetSumBU(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (nums[i-1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
*/

----------------------------------------------------------
4) Minimum Subset Sum Difference
----------------------------------------------------------
Problem: Partition array into two subsets such that the difference of their sums is minimized.

// Bottom-Up DP (Tabulation)
int minSubsetSumDifference(vector<int>& nums) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<bool>> dp(n+1, vector<bool>(total/2+1, false));
    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= total/2; ++j) {
            if (nums[i-1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int ans = INT_MAX;
    for (int s1 = 0; s1 <= total/2; ++s1) {
        if (dp[n][s1]) {
            int s2 = total - s1;
            ans = min(ans, abs(s2 - s1));
        }
    }
    return ans;
}

/*
Better Alternative: Space Optimized DP
--------------------------------------
- Use a 1D array instead of 2D for subset sum.
*/

----------------------------------------------------------
Dry Run Example: Count Derangements for n = 4
----------------------------------------------------------
countDerangements(4)
- D(4) = (4-1) * (D(3) + D(2))
- D(3) = (3-1) * (D(2) + D(1))
- D(2) = 1, D(1) = 0
- D(3) = 2 * (1 + 0) = 2
- D(4) = 3 * (2 + 1) = 9

So, for n=4, number of derangements = 9
