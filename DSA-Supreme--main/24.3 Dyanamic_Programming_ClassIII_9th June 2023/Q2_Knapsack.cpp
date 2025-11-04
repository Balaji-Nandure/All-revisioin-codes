/*
    0/1 Knapsack Problem - Multiple Approaches

    Problem Statement:
    Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
    Each item can be included at most once (0/1 property).

    Approaches Used in this Code:
    1. Pure Recursion (solveRec)
    2. Top-Down DP (Memoization) (solveTopDown)
    3. Bottom-Up DP (Tabulation) (solveTab)
    4. Space Optimized DP (2 arrays) (solveSpaceOpt1)
    5. Space Optimized DP (1 array) (solveSpaceOpt2) [Best in this code]

    Alternatives:
    - Bitmask DP (for small n)
    - Meet in the Middle (for large weights, small n)
    - Branch and Bound (for fractional knapsack)
    - Iterative DP with item reconstruction (to get selected items)

    Each function below is commented with logic and reasoning.
    At the end, a dry run is provided for the sample input.

    Sample Input:
    weight[] = {4, 5, 1}
    value[]  = {1, 2, 3}
    n = 3
    capacity = 4
*/

// Include necessary headers
#include <iostream>
#include <vector>
using namespace std;

//------------------- 1. Pure Recursion -------------------
/*
    solveRec:
    - index: current item index (from n-1 to 0)
    - capacity: remaining knapsack capacity
    - Returns: maximum value achievable with items[0..index] and given capacity
    - Time: O(2^n), Space: O(n) (call stack)
*/
int solveRec(int weight[], int value[], int index, int capacity)
{
    // Base case: Only 1 item left (index 0)
    if (index == 0)
    {
        // If item 0 can fit, take its value; else 0
        return (weight[0] <= capacity) ? value[0] : 0;
    }

    // Option 1: Include current item if it fits
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveRec(weight, value, index - 1, capacity - weight[index]);

    // Option 2: Exclude current item
    int exclude = solveRec(weight, value, index - 1, capacity);

    // Return the better of the two options
    return max(include, exclude);
}

//------------------- 2. Top-Down DP (Memoization) -------------------
/*
    solveTopDown:
    - Uses a dp table to store results of subproblems
    - dp[index][capacity]: max value for items[0..index] and given capacity
    - Time: O(n*capacity), Space: O(n*capacity)
*/
int solveTopDown(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    // Base case: Only 1 item left
    if (index == 0)
        return (weight[0] <= capacity) ? value[0] : 0;

    // If already computed, return stored value
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // Option 1: Include current item if it fits
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveTopDown(weight, value, index - 1, capacity - weight[index], dp);

    // Option 2: Exclude current item
    int exclude = solveTopDown(weight, value, index - 1, capacity, dp);

    // Store and return the result
    return dp[index][capacity] = max(include, exclude);
}

//------------------- 3. Bottom-Up DP (Tabulation) -------------------
/*
    solveTab:
    - Iteratively fills dp table from smaller subproblems to larger
    - dp[i][w]: max value for items[0..i] and capacity w
    - Time: O(n*capacity), Space: O(n*capacity)
*/
int solveTab(int weight[], int value[], int n, int capacity)
{
    // Create dp table, initialized to 0
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Base case: Fill for first item (index 0)
    for (int w = 0; w <= capacity; w++)
        dp[0][w] = (weight[0] <= w) ? value[0] : 0;

    // Build the table for all items and capacities
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            // Option 1: Include current item if it fits
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + dp[index - 1][wt - weight[index]];

            // Option 2: Exclude current item
            int exclude = dp[index - 1][wt];

            // Store the best of both
            dp[index][wt] = max(include, exclude);
        }
    }
    // The answer is for all items and full capacity
    return dp[n - 1][capacity];
}

//------------------- 4. Space Optimized DP (2 arrays) -------------------
/*
    solveSpaceOpt1:
    - Only keeps previous and current row of dp table
    - Time: O(n*capacity), Space: O(2*capacity)
*/
int solveSpaceOpt1(int weight[], int value[], int n, int capacity)
{
    // prev: dp for previous item, curr: dp for current item
    vector<int> prev(capacity + 1, 0), curr(capacity + 1, 0);

    // Base case: Fill for first item
    for (int w = 0; w <= capacity; w++)
        prev[w] = (weight[0] <= w) ? value[0] : 0;

    // Build for each item
    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            // Option 1: Include current item if it fits
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + prev[wt - weight[index]];

            // Option 2: Exclude current item
            int exclude = prev[wt];

            // Store the best of both
            curr[wt] = max(include, exclude);
        }
        // Move current row to previous for next iteration
        prev = curr;
    }
    // The answer is in prev[capacity]
    return prev[capacity];
}

//------------------- 5. Space Optimized DP (1 array) -------------------
/*
    solveSpaceOpt2:
    - Uses only one array, updates from right to left to avoid overwriting needed values
    - Time: O(n*capacity), Space: O(capacity)
    - This is the most space-efficient standard DP for 0/1 knapsack
*/
int solveSpaceOpt2(int weight[], int value[], int n, int capacity)
{
    // curr: dp for current state
    vector<int> curr(capacity + 1, 0);

    // Base case: Fill for first item
    for (int w = 0; w <= capacity; w++)
        curr[w] = (weight[0] <= w) ? value[0] : 0;

    // Build for each item
    for (int index = 1; index < n; index++)
    {
        // Traverse backwards to avoid using updated values in the same iteration
        for (int wt = capacity; wt >= 0; wt--)
        {
            // Option 1: Include current item if it fits
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + curr[wt - weight[index]];

            // Option 2: Exclude current item
            int exclude = curr[wt];

            // Store the best of both
            curr[wt] = max(include, exclude);
        }
    }
    // The answer is in curr[capacity]
    return curr[capacity];
}

//------------------- Main Function and Usage -------------------
int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    // Uncomment any approach to test

    // 1. Pure Recursion (Exponential time, not recommended for large n)
    // int ans = solveRec(weight, value, n - 1, capacity);

    // 2. Top-Down DP (Memoization)
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // int ans = solveTopDown(weight, value, n - 1, capacity, dp);

    // 3. Bottom-Up DP (Tabulation)
    // int ans = solveTab(weight, value, n, capacity);

    // 4. Space Optimized DP (2 arrays)
    // int ans = solveSpaceOpt1(weight, value, n, capacity);

    // 5. Space Optimized DP (1 array) [Best for standard 0/1 knapsack]
    int ans = solveSpaceOpt2(weight, value, n, capacity);

    cout << "Maximum profit = " << ans << endl;

    /*
        Dry Run for input:
        weight[] = {4, 5, 1}
        value[]  = {1, 2, 3}
        n = 3, capacity = 4

        Items: (weight, value)
        0: (4, 1)
        1: (5, 2)
        2: (1, 3)

        Let's fill dp for capacity 0..4:

        For item 0 (only item 0 considered):
        capacity: 0 1 2 3 4
        value:    0 0 0 0 1

        For item 1 (items 0,1):
        capacity: 0 1 2 3 4
        value:    0 0 0 0 1
        (item 1 can't fit in any capacity <= 4)

        For item 2 (items 0,1,2):
        capacity: 0 1 2 3 4
        value:    0 3 3 3 3
        (item 2 fits in capacity 1, value=3; for capacity 4, can take item 2 and item 0: value=3+1=4)

        Correction: Let's check for capacity 4:
        - Option 1: Take item 2 (weight 1, value 3), remaining capacity 3, best with items 0,1: value=0
        - Option 2: Don't take item 2, best with items 0,1: value=1
        Actually, for capacity 4, can take item 2 and item 0: total weight=1+4=5>4, so not possible.
        So, only item 2 can be taken: value=3

        But let's check the code's output:
        The correct answer is 3 (take only item 2).

        Output:
        Maximum profit = 3
    */

    return 0;
}

/*
    Alternative Approaches (in comments):

    // Bitmask DP (for n <= 20)
    // Meet in the Middle (for n <= 40, large weights)
    // Fractional Knapsack (if items can be broken, use greedy)
    // Item selection reconstruction (trace back from dp table)
*/
