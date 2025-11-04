// LeetCode 121: Best Time to Buy and Sell Stock
// Approach: Greedy - Track the minimum price so far, and the maximum profit at each step.
// This gives O(N) time and O(1) space (best possible).

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;   // Smallest price encountered so far
    int maxProfit = 0;        // Max profit achievable so far

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price;   // Update min price if a new lower price is found
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice; // Update max profit if larger profit found
        }
    }
    return maxProfit;
}

int main() {
    // Example test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl; // Output: 5 (buy at 1, sell at 6)
    return 0;
}
