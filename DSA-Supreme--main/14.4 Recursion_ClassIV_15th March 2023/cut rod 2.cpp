#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 1. Count number of ways to cut rod to get sum (like coin change ways)
int rodCutWays(int lengths[], int n, int rodLength, int index = 0) {
    if (rodLength == 0)
        return 1; // exact length achieved
    if (rodLength < 0 || index == n)
        return 0;

    // Include current length if possible
    int include = 0;
    if (rodLength - lengths[index] >= 0)
        include = rodCutWays(lengths, n, rodLength - lengths[index], index);

    // Exclude current length
    int exclude = rodCutWays(lengths, n, rodLength, index + 1);

    return include + exclude;
}

// 2. Maximum profit (like unbounded knapsack/rod cutting)
int rodMaxProfit(int lengths[], int prices[], int n, int rodLength, int index = 0) {
    if (rodLength == 0)
        return 0;
    if (index == n || rodLength < 0)
        return 0;

    // Include current length if possible
    int include = 0;
    if (rodLength - lengths[index] >= 0)
        include = prices[index] + rodMaxProfit(lengths, prices, n, rodLength - lengths[index], index);

    // Exclude current length
    int exclude = rodMaxProfit(lengths, prices, n, rodLength, index + 1);

    return max(include, exclude);
}

// 3. Minimum cuts needed for maximum profit (returns cuts for *some* max profit)
int minCutsForMaxProfit(int lengths[], int prices[], int n, int rodLength, int index = 0) {
    if (rodLength == 0)
        return 0;
    if (index == n || rodLength < 0)
        return INT_MAX;

    // Include current length if possible
    int include = INT_MAX;
    if (rodLength - lengths[index] >= 0) {
        int inc = minCutsForMaxProfit(lengths, prices, n, rodLength - lengths[index], index);
        if (inc != INT_MAX)
            include = 1 + inc;
    }

    // Exclude current length
    int exclude = minCutsForMaxProfit(lengths, prices, n, rodLength, index + 1);

    return min(include, exclude);
}

// 4. Print all ways to cut rod to get exact length
void rodCutPrintWays(int lengths[], int n, int rodLength, vector<int>& result, vector<vector<int>>& allWays, int index = 0) {
    if (rodLength == 0) {
        allWays.push_back(result);
        return;
    }
    if (rodLength < 0 || index == n)
        return;

    // Include current length if possible
    if (rodLength - lengths[index] >= 0) {
        result.push_back(lengths[index]);
        rodCutPrintWays(lengths, n, rodLength - lengths[index], result, allWays, index);
        result.pop_back();
    }
    // Exclude current length
    rodCutPrintWays(lengths, n, rodLength, result, allWays, index + 1);
}

int main() {
    int lengths[] = {1, 2, 3};
    int prices[] = {2, 5, 7};  // price for lengths 1,2,3
    int n = sizeof(lengths) / sizeof(lengths[0]);
    int rodLength = 4;

    cout << "Number of ways to cut rod of length " << rodLength << " = " << rodCutWays(lengths, n, rodLength) << endl;

    int maxProfit = rodMaxProfit(lengths, prices, n, rodLength);
    cout << "Maximum profit = " << maxProfit << endl;

    int minCuts = minCutsForMaxProfit(lengths, prices, n, rodLength);
    if (minCuts == INT_MAX)
        cout << "Not possible to cut rod for max profit." << endl;
    else
        cout << "Minimum cuts for max profit = " << minCuts << endl;

    vector<vector<int>> allWays;
    vector<int> result;
    rodCutPrintWays(lengths, n, rodLength, result, allWays);
    cout << "All possible ways to cut the rod:\n";
    for (auto &way : allWays) {
        cout << "[ ";
        for (int len : way) cout << len << " ";
        cout << "]\n";
    }

    return 0;
}
