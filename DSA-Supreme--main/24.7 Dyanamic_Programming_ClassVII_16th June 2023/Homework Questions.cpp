/*
================================================================================
1) Russian Doll Envelopes (Same pattern as Longest Increasing Subsequence)
================================================================================

Approach Used:
--------------
- This problem is a variation of the Longest Increasing Subsequence (LIS).
- Each envelope is represented as a pair (width, height).
- You can put envelope A into envelope B if both width and height of A are less than B.
- The task is to find the maximum number of envelopes you can Russian doll (i.e., put one inside another).

Steps:
------
1. **Sort the envelopes**:
   - Sort by width in ascending order.
   - If widths are equal, sort by height in *descending* order (to avoid counting envelopes with same width).
2. **Apply LIS on heights**:
   - After sorting, the problem reduces to finding LIS on the heights.

Code with Comments:
-------------------
int maxEnvelopes(vector<vector<int>>& envelopes) {
    // Sort envelopes: width ascending, height descending for equal widths
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    // Extract heights for LIS
    vector<int> heights;
    for(const auto& env : envelopes) {
        heights.push_back(env[1]);
    }

    // Find LIS on heights
    vector<int> dp;
    for(int h : heights) {
        // Find the insertion point for h in dp
        auto it = lower_bound(dp.begin(), dp.end(), h);
        if(it == dp.end()) {
            dp.push_back(h); // New largest element, extend LIS
        } else {
            *it = h; // Replace to maintain smallest possible tail
        }
    }
    return dp.size(); // Length of LIS is the answer
}

Better Alternatives:
--------------------
- The above approach is O(n log n) due to sorting and LIS with binary search.
- A naive DP approach (O(n^2)) is possible but slower:
    /*
    // O(n^2) DP
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
    */
- The O(n log n) approach is preferred for large input.

Dry Run:
--------
Input: [[5,4],[6,4],[6,7],[2,3]]
After sorting: [[2,3],[5,4],[6,7],[6,4]]
Heights: [3,4,7,4]
LIS on heights: 3,4,7 => length = 3 (so answer is 3)

================================================================================
2) Longest Increasing Subsequence with Absolute Difference = 1
================================================================================

Approach Used:
--------------
- Find the length of the longest subsequence such that the absolute difference between adjacent elements is exactly 1.
- Use Dynamic Programming (DP) to store the length of the longest such subsequence ending at each index.

Code with Comments:
-------------------
int longestSubseqWithDiffOne(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // dp[i]: length of longest valid subsequence ending at i

    for(int i=1; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            // If absolute difference is 1, try to extend the subsequence
            if(abs(arr[i] - arr[j]) == 1) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    // The answer is the maximum value in dp
    return *max_element(dp.begin(), dp.end());
}

Better Alternatives:
--------------------
- For small constraints, the above O(n^2) DP is sufficient.
- For large constraints, use a hash map to store the length of subsequence ending with a particular value:
    /*
    unordered_map<int, int> dp;
    int ans = 1;
    for(int x : arr) {
        dp[x] = max(dp[x], max(dp[x-1], dp[x+1]) + 1);
        ans = max(ans, dp[x]);
    }
    return ans;
    */
- This reduces time complexity to O(n).

Dry Run:
--------
Input: [10, 9, 4, 5, 4, 8, 6]
dp: [1,2,1,2,2,1,2]
Answer: 2 (e.g., [10,9] or [4,5] or [5,4])

================================================================================
3) Burst Balloons (3D DP Question)
================================================================================

Approach Used:
--------------
- Given an array of balloons with numbers, you can burst any balloon. When you burst balloon i, you get coins equal to nums[left] * nums[i] * nums[right], where left and right are adjacent balloons (not yet burst).
- The task is to maximize the coins by bursting all balloons in an optimal order.
- Use DP with memoization (Top-Down) or tabulation (Bottom-Up).

Code with Comments:
-------------------
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    // Add 1 at both ends to simplify edge cases
    vector<int> arr(n+2, 1);
    for(int i=0; i<n; ++i) arr[i+1] = nums[i];

    // dp[i][j]: max coins from bursting balloons in (i, j) (exclusive)
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    // Bottom-up DP
    for(int len=1; len<=n; ++len) { // length of subarray
        for(int left=1; left<=n-len+1; ++left) {
            int right = left+len-1;
            for(int k=left; k<=right; ++k) {
                // Burst k last in (left, right)
                dp[left][right] = max(dp[left][right],
                    arr[left-1]*arr[k]*arr[right+1] + dp[left][k-1] + dp[k+1][right]);
            }
        }
    }
    return dp[1][n];
}

Better Alternatives:
--------------------
- Top-Down DP with memoization (recursive):
    /*
    int burst(vector<int>& arr, int left, int right, vector<vector<int>>& memo) {
        if(left > right) return 0;
        if(memo[left][right] != -1) return memo[left][right];
        int ans = 0;
        for(int k=left; k<=right; ++k) {
            int coins = arr[left-1]*arr[k]*arr[right+1]
                        + burst(arr, left, k-1, memo)
                        + burst(arr, k+1, right, memo);
            ans = max(ans, coins);
        }
        return memo[left][right] = ans;
    }
    // Usage:
    vector<int> arr(nums.size()+2, 1);
    for(int i=0; i<nums.size(); ++i) arr[i+1] = nums[i];
    vector<vector<int>> memo(arr.size(), vector<int>(arr.size(), -1));
    return burst(arr, 1, nums.size(), memo);
    */
- Both approaches are O(n^3).

Dry Run:
--------
Input: [3,1,5,8]
After adding 1s: [1,3,1,5,8,1]
dp[1][4] is filled by considering all possible last balloons to burst in each subarray.
Final answer: 167

================================================================================
Summary:
- All three problems use DP, with space/time optimizations where possible.
- Comments explain the logic behind each line.
- Better alternatives and dry runs are provided for deeper understanding.
*/
