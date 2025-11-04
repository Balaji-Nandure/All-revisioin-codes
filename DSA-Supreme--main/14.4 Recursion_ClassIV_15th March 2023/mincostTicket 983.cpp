class Solution {
public:
    int minCostTicketsHelper(const vector<int>& days, const vector<int>& costs, int index) {
        // Base case: if all travel days covered
        if (index >= days.size()) return 0;

        int minCost = INT_MAX;

        // Try 1-day, 7-day, and 30-day passes
        for (int i = 0; i < 3; ++i) {
            int duration = (i == 0) ? 1 : (i == 1) ? 7 : 30;
            int cost = costs[i];

            int j = index;
            // Skip all days covered by this pass starting at days[index]
            while (j < days.size() && days[j] < days[index] + duration) {
                j++;
            }

            int totalCost = cost + minCostTicketsHelper(days, costs, j);
            if (totalCost < minCost) {
                minCost = totalCost;
            }
        }

        return minCost;
    }

    int minCostTickets(vector<int>& days, vector<int>& costs) {
        return minCostTicketsHelper(days, costs, 0);
    }
};


// Example: Draw recursion tree for days = [1, 4, 6, 7, 8, 20], costs = [2, 7, 15]
//
// Call: minCostTicketsHelper([1,4,6,7,8,20], [2,7,15], 0)
//
// (index=0, day=1)
// ├── Choose 1-day pass (covers day 1) → cost=2
// │   └── minCostTicketsHelper(..., 1)
// │       (index=1, day=4)
// │       ├── 1-day: minCostTicketsHelper(..., 2)
// │       ├── 7-day: minCostTicketsHelper(..., 4)
// │       └── 30-day: minCostTicketsHelper(..., 6) [covers all days]
// ├── Choose 7-day pass (covers days 1,4,6,7,8) → cost=7
// │   └── minCostTicketsHelper(..., 5)
// │       (index=5, day=20)
// │       ├── 1-day: minCostTicketsHelper(..., 6)
// │       ├── 7-day: minCostTicketsHelper(..., 6)
// │       └── 30-day: minCostTicketsHelper(..., 6)
// └── Choose 30-day pass (covers all days) → cost=15
//     └── minCostTicketsHelper(..., 6) [base case: returns 0]
//
// The tree shows recursive choices at each index:
// - Each branch is a pass type (1-day, 7-day, 30-day)
// - Each node leads to calls on the next uncovered index, building up the total cost
//
// You can use this sort of recursion tree to visualize the overlapping subproblems and number of recursive calls.