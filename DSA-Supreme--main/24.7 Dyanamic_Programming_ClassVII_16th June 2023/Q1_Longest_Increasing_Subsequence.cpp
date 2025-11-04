// https://leetcode.com/problems/longest-increasing-subsequence/description/

/*
    APPROACHES USED FOR LONGEST INCREASING SUBSEQUENCE (LIS):

    1. Pure Recursion (Exponential Time)
    2. Top-Down DP (Memoization) - O(N^2) Time, O(N^2) Space
    3. Bottom-Up DP (Tabulation) - O(N^2) Time, O(N^2) Space
    4. Space Optimized DP - O(N^2) Time, O(N) Space
    5. Optimal Solution using Binary Search (Patience Sorting) - O(N log N) Time, O(N) Space

    Each approach is implemented below with detailed comments.
    At the end, a dry run is provided for better understanding.

    ALTERNATIVE: There is also a classic O(N^2) DP (not shown here) where dp[i] = length of LIS ending at i.
    See comments at the end for that code as well.
*/

class Solution {
public:
    // 1. Pure Recursive Solution (Exponential Time)
    // Returns the length of LIS starting from index 'curr', with previous element at index 'prev'
    int solveRec(vector<int>& nums, int curr, int prev) {
        // Base case: If we have processed all elements, LIS is 0
        if (curr >= nums.size())
            return 0;

        int include = 0;
        // If prev == -1 (no element taken yet) or current element is greater than previous, we can include it
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveRec(nums, curr + 1, curr); // include current element and move to next
        }
        // Exclude current element and move to next
        int exclude = solveRec(nums, curr + 1, prev);

        // Return the maximum of including or excluding current element
        return max(include, exclude);
    }

    // 2. Top-Down DP (Memoization)
    // dp[curr][prev+1] stores the result for index 'curr' and previous index 'prev'
    int solveTopDown(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
        // Base case: If we have processed all elements, LIS is 0
        if (curr >= nums.size())
            return 0;

        // If already computed, return the stored value
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int include = 0;
        // If we can include current element
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveTopDown(nums, curr + 1, curr, dp);
        }
        // Exclude current element
        int exclude = solveTopDown(nums, curr + 1, prev, dp);

        // Store and return the result
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    // 3. Bottom-Up DP (Tabulation)
    // Iterative DP to fill the table from the end
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        // dp[curr][prev+1]: LIS starting from curr, with previous index prev
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // +1 for handling prev = -1

        // Fill the table in reverse order (from n-1 to 0)
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                // If we can include current element
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + dp[curr + 1][curr + 1]; // include current, move prev to curr
                }
                // Exclude current element
                int exclude = dp[curr + 1][prev + 1];
                // Store the result
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        // The answer is for curr=0, prev=-1
        return dp[0][0];
    }

    // 4. Space Optimized DP
    // Only keep two rows: current and next, as we only need next row to compute current
    int spaceOpt(vector<int>& nums) {
        int n = nums.size();
        vector<int> currRow(n + 1, 0); // Current row
        vector<int> nextRow(n + 1, 0); // Next row

        // Fill the table in reverse order
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + nextRow[curr + 1];
                }
                int exclude = nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            // Move current row to next row for next iteration
            nextRow = currRow;
        }
        return nextRow[0];
    }

    // 5. Optimal Solution: Patience Sorting (Binary Search)
    // O(N log N) time, O(N) space
    // Maintains a list 'ans' where ans[i] is the smallest possible tail of an increasing subsequence of length i+1
    int solveOptimal(vector<int>& arr) {
        if (arr.empty())
            return 0;

        vector<int> ans; // Stores the smallest tail for all increasing subsequences of different lengths
        ans.push_back(arr[0]); // First element always starts a subsequence

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > ans.back()) {
                // If current element is greater than last element in ans, it extends the LIS
                ans.push_back(arr[i]);
            } else {
                // Otherwise, replace the first element in ans which is >= arr[i]
                // This keeps ans as small as possible, allowing more room for future elements
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        // The size of ans is the length of the LIS
        return ans.size();
    }

    // Main function to call the desired approach
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;

        // Uncomment any one of the following approaches to use:

        // 1. Pure Recursion (Not recommended for large inputs)
        // int ans = solveRec(nums, curr, prev);

        // 2. Top Down DP (Memoization)
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        // int ans = solveTopDown(nums, curr, prev, dp);

        // 3. Bottom Up DP (Tabulation)
        // int ans = solveTab(nums);

        // 4. Space Optimized DP
        // int ans = spaceOpt(nums);

        // 5. Optimal Solution (Patience Sorting, Binary Search)
        int ans = solveOptimal(nums);

        return ans;
    }
};

/*
    ALTERNATIVE O(N^2) DP (Classic):
    ---------------------------------
    // dp[i] = length of LIS ending at index i
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // Each element is at least a subsequence of length 1
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    DRY RUN (Optimal Solution, Input: [10,9,2,5,3,7,101,18]):
    ----------------------------------------------------------
    ans = [10]
    i=1, arr[i]=9: 9 < 10, replace ans[0] with 9 => ans=[9]
    i=2, arr[i]=2: 2 < 9, replace ans[0] with 2 => ans=[2]
    i=3, arr[i]=5: 5 > 2, append => ans=[2,5]
    i=4, arr[i]=3: 3 < 5, replace ans[1] with 3 => ans=[2,3]
    i=5, arr[i]=7: 7 > 3, append => ans=[2,3,7]
    i=6, arr[i]=101: 101 > 7, append => ans=[2,3,7,101]
    i=7, arr[i]=18: 18 < 101, replace ans[3] with 18 => ans=[2,3,7,18]
    Final ans.size() = 4 (LIS is [2,3,7,18])
*/