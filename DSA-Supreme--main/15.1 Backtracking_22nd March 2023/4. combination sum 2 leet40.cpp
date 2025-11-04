#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function to perform backtracking for combination sum 2
    void backtrack(
        vector<int>& candidates,    // List of candidate numbers (may have duplicates)
        int target,                 // Remaining target sum to reach
        int index,                  // Index of the current candidate
        vector<int>& current,       // Current combination being built
        vector<vector<int>>& result // Stores all valid combinations
    ) {
        if (target == 0) { // If remaining target is zero, valid combination is found
            result.push_back(current); // Add the current combination to results
            return; // Stop further recursion for this path
        }
        
        // Loop from current index to end
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates at the same recursive level
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break; // Early pruning since candidates sorted
            
            current.push_back(candidates[i]);
            // We pass i+1 since each number can be used at most once
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
    
    // Main function to find all unique combinations that sum up to target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result; // To store final result combinations
        vector<int> current;        // To keep current combination
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        backtrack(candidates, target, 0, current, result); // Start backtracking from index 0
        return result; // Return the list of all possible combinations
    }
};