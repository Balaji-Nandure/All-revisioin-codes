class Solution {
public:
    // Helper function to perform backtracking for combination sum
    void backtrack(
        vector<int>& candidates,    // List of candidate numbers
        int target,                 // Remaining target sum to reach
        int index,                  // Index of the current candidate
        vector<int>& current,       // Current combination being built
        vector<vector<int>>& result // Stores all valid combinations
    ) {
        if (target == 0) { // If remaining target is zero, valid combination is found
            result.push_back(current); // Add the current combination to results
            return; // Stop further recursion for this path
        }
        
        // Base case: if target is less than zero, or out of bounds in candidates
        if (target < 0 || index == candidates.size())
            return; // Invalid combination, backtrack now
        
        current.push_back(candidates[index]); // Include current index number in combination
        backtrack(candidates, target - candidates[index], index, current, result); // Try same index, allow repeated use
        
        current.pop_back(); // Remove last pushed number (backtrack step)
        
        backtrack(candidates, target, index + 1, current, result); // Try next index, skip current candidate
    }
    
    // Main function to find all unique combinations that sum up to target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result; // To store final result combinations
        vector<int> current;        // To keep current combination
        backtrack(candidates, target, 0, current, result); // Start backtracking from index 0
        return result; // Return the list of all possible combinations
    }
};