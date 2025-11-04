#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Problem Statement:

// You are given:

// A set of coins of different denominations coins[].

// A total amount sum.

// Task: Count all possible ways to make the amount using the coins. You can use a coin any number of times.
// Function 1: Count number of ways to make sum
// Count the total ways to make the sum using coins (coin change ways)
int coinChangeWays(int coins[], int n, int sum, int index = 0) {
    if (sum == 0) return 1;           // sum achieved exactly, one way found
    if (sum < 0) return 0;            // sum negative, not possible
    if (index == n) return 0;         // no coins left, not possible

    // Case 1: include current coin (can reuse, so keep same index)
    int include = coinChangeWays(coins, n, sum - coins[index], index);  
    // Case 2: exclude current coin (move to next coin)
    int exclude = coinChangeWays(coins, n, sum, index + 1);            

    return include + exclude;         // total ways = include + exclude
}

// Find the minimum number of coins needed to make the sum
int minCoins(int coins[], int n, int sum, int index = 0) {
    if (sum == 0) return 0;                 // sum achieved, no more coins needed
    if (sum < 0) return INT_MAX;            // sum negative, not possible
    if (index == n) return INT_MAX;         // no coins left, not possible

    // Try including the current coin
    int include = minCoins(coins, n, sum - coins[index], index);
    if (include != INT_MAX) include += 1;   // only add if valid

    // Try excluding the current coin
    int exclude = minCoins(coins, n, sum, index + 1);

    return min(include, exclude);           // return the minimum of both choices
}

// Find the maximum number of coins that can be used to make the sum
int maxCoins(int coins[], int n, int sum, int index = 0) {
    if (sum == 0) return 0;                // sum achieved, stop recursion
    if (sum < 0) return INT_MIN;           // sum negative, invalid
    if (index == n) return INT_MIN;        // no coins left, invalid

    // Try including the current coin
    int include = maxCoins(coins, n, sum - coins[index], index);
    if (include != INT_MIN) include += 1;  // add one if valid path

    // Try excluding the current coin
    int exclude = maxCoins(coins, n, sum, index + 1);

    return max(include, exclude);          // return the maximum of both choices
}

// Function to print all possible ways to make the sum using coins
// result holds the current combination, allWays stores every valid combination
void coinChangePrintWays(int coins[], int n, int sum, vector<int>& result, vector<vector<int>>& allWays, int index = 0) {
    if (sum == 0) {
        allWays.push_back(result);
        return;
    }
    if (sum < 0 || index == n)
        return;

    // Include the current coin (can reuse, so same index)
    result.push_back(coins[index]);
    coinChangePrintWays(coins, n, sum - coins[index], result, allWays, index);
    result.pop_back();

    // Exclude the current coin (move to next coin)
    coinChangePrintWays(coins, n, sum, result, allWays, index + 1);
}


int main() {
    int coins[] = {1, 2, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;

    cout << "Number of ways to make sum " << sum << " = " << coinChangeWays(coins, n, sum) << endl;

    int minCoinsNeeded = minCoins(coins, n, sum);
    if (minCoinsNeeded == INT_MAX)
        cout << "It is not possible to make the sum with given coins." << endl;
    else
        cout << "Minimum number of coins required = " << minCoinsNeeded << endl;

    int maxCoinsNeeded = maxCoins(coins, n, sum);
    if (maxCoinsNeeded == INT_MIN)
        cout << "It is not possible to make the sum with given coins." << endl;
    else
        cout << "Maximum number of coins required = " << maxCoinsNeeded << endl;

    vector<vector<int>> allWays;
    vector<int> result;
    coinChangePrintWays(coins, n, sum, result, allWays);
    cout << "All possible ways to make the sum " << sum << " = " << allWays.size() << endl;
    for (int i = 0; i < allWays.size(); i++) {
        cout << "[";
        for (int j = 0; j < allWays[i].size(); j++) {
            cout << allWays[i][j] << " ";
        }
        cout << "]";
    }
    cout << endl;

    return 0;
}
