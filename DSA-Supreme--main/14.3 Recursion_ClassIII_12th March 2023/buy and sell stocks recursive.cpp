/*
Approach Explanation (Recursive):
The problem: Given an array of stock prices, you can buy and sell as many times as you like (but only one stock at a time—can't have overlapping transactions), find the maximum profit you can make.

Recursive breakdown:
- At each day, you have two states: canBuy (True/False)
    - If canBuy is true: You can either buy at today's price or skip.
    - If canBuy is false: You can either sell at today's price or skip.
- Recursively, for each day, consider both options, take the maximum, and solve for the next day.
- Base case: If you reach end of array, no more profit possible (return 0).

Implementation:
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// -------------------------------------------------------------
// // BETTER APPROACH: Single Transaction (shorter names)
// -------------------------------------------------------------

// Recursive function with medium-short variable names
int maxProfitHelper(const vector<int>& prices, int index, int minPrice) {
    if (index == prices.size()) return 0;
    int profitIfSell = prices[index] - minPrice;
    int profitIfSkip = maxProfitHelper(prices, index + 1, min(minPrice, prices[index]));
    return max(profitIfSell, profitIfSkip);
}

int maxProfit(const vector<int>& prices) {
    if (prices.empty()) return 0;
    return maxProfitHelper(prices, 1, prices[0]);
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example prices
    int result = maxProfit(prices);
    cout << "Maximum Profit (Recursive): " << result << endl;
    // Output should be 7 (buy at 1, sell at 5; buy at 3, sell at 6)
    return 0;
}

/*
Key Points:
- This is the classic recursive solution (exponential time).
- With memoization (top-down DP), we can optimize to O(N*2).
- In real interviews, usually they expect DP solution, but recursion is a good base to understand state exploration.
- The 'canBuy' flag simulates the constraint that you must sell before you buy again.
*/