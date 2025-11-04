/*
Approach Used: Two Pointer after Sorting (O(n log n) time, O(n) space)
----------------------------------------------------------------------
This code solves the "Two Sum" problem by first storing each number along with its original index, sorting the array, and then using the two-pointer technique to find two numbers that sum up to the target.

Logic:
------
1. Store each number with its original index in a vector of pairs.
2. Sort the vector based on the number values (not indices).
3. Use two pointers (start and end) to scan from both ends:
   - If the sum of the two pointed numbers equals the target, return their original indices.
   - If the sum is greater than the target, move the end pointer left.
   - If the sum is less than the target, move the start pointer right.

Why this works:
---------------
- Sorting allows us to efficiently search for the pair using two pointers.
- Storing original indices ensures we return the correct answer as per the problem's requirement.

Better Alternatives & Detailed Approaches:
------------------------------------------
1. **Hash Map (Optimal O(n) time, O(n) space):**
   - Store each number and its index in a hash map as you iterate.
   - For each number, check if (target - current number) exists in the map.
   - If found, return the indices.
   - No need to sort, so preserves original order.

   // Code:
   /*
   vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> mp; // value -> index
       for(int i = 0; i < nums.size(); i++) {
           int complement = target - nums[i];
           if(mp.count(complement)) {
               return {mp[complement], i};
           }
           mp[nums[i]] = i;
       }
       return {};
   }
   */

2. **Brute Force (O(n^2) time, O(1) space):**
   - For each pair of indices, check if their sum is target.
   - Not efficient for large inputs.

   // Code:
   /*
   vector<int> twoSum(vector<int>& nums, int target) {
       for(int i = 0; i < nums.size(); i++) {
           for(int j = i+1; j < nums.size(); j++) {
               if(nums[i] + nums[j] == target) {
                   return {i, j};
               }
           }
       }
       return {};
   }
   */

Dry Run:
--------
Input: nums = [2, 7, 11, 15], target = 9

Step 1: Store with indices: data = [(2,0), (7,1), (11,2), (15,3)]
Step 2: Sort (already sorted): data = [(2,0), (7,1), (11,2), (15,3)]
Step 3: start=0, end=3
    - data[0].first + data[3].first = 2+15=17 > 9 => end--
    - data[0].first + data[2].first = 2+11=13 > 9 => end--
    - data[0].first + data[1].first = 2+7=9 == 9 => return [0,1]

Output: [0,1]

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Comparator to sort pairs by their first value (the number itself)
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> data; // To store (number, original index)
        vector<int> ans; // To store the answer indices

        // Store each number with its original index
        for(int i = 0; i < nums.size(); i++){
            data.push_back({nums[i], i});
        }

        // Sort the data based on the number value
        sort(data.begin(), data.end(), cmp);

        int start = 0; // Left pointer
        int end = data.size() - 1; // Right pointer

        // Two pointer approach to find the pair
        while(start < end){
            int sum = data[start].first + data[end].first; // Sum of two numbers

            if(sum == target){
                // If sum matches target, store their original indices
                ans.push_back(data[start].second);
                ans.push_back(data[end].second);
                break; // Since only one solution exists
            }
            else if(sum > target){
                // If sum is too large, move end pointer left
                end--;
            }
            else{
                // If sum is too small, move start pointer right
                start++;
            }
        }
        return ans; // Return the indices of the two numbers
    }
};