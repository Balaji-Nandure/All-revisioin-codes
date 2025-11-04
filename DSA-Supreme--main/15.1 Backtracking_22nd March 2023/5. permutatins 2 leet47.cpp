class Solution {
    public:
        // Backtracking function to generate unique permutations
        void backtrack(vector<int>& nums, vector<bool>& used,
                       vector<int>& current, vector<vector<int>>& result) {
            if (current.size() == nums.size()) { // If we have a full permutation
                result.push_back(current);       // Add current permutation to result
                return;                          // Backtrack
            }

            for (int i = 0; i < nums.size(); i++) {    // Try each element in nums
                if (used[i]) continue;                 // Skip if this element is already used in the current permutation

                // Skip duplicates: if same as previous and previous was not used, skip to avoid duplicate permutations
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;

                used[i] = true;            // Mark this element as used
                current.push_back(nums[i]); // Add element to current permutation

                backtrack(nums, used, current, result); // Recurse to next step

                current.pop_back();       // Remove last element to backtrack
                used[i] = false;          // Mark this element as unused for next iterations
            }
        }

        // Main function to return all unique permutations for nums
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> result;           // Stores all unique permutations
            vector<int> current;                  // Current permutation being built
            vector<bool> used(nums.size(), false); // Track which elements are used

            sort(nums.begin(), nums.end());       // Sort nums to easily identify duplicates
            backtrack(nums, used, current, result); // Start backtracking
            return result;                        // Return all unique permutations
        }
    };
