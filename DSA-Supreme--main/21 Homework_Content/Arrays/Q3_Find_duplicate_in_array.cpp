// https://leetcode.com/problems/find-the-duplicate-number/description/

/*
Approach Used in Code (Cycle Detection / Array as Linked List):
---------------------------------------------------------------
- The given code uses the "Cyclic Sort" approach (a variant of Floyd's Tortoise and Hare cycle detection) to find the duplicate number in the array.
- The array contains n+1 integers where each integer is between 1 and n (inclusive), so at least one duplicate must exist.
- The idea is to place each number at its correct index (i.e., nums[i] should be i), and the duplicate will cause a cycle or a repeated swap.
- The code swaps elements until nums[0] is at its correct position, and the duplicate is found when nums[0] == nums[nums[0]].

Better Alternatives (with code and explanation):
------------------------------------------------
1. **Floyd's Tortoise and Hare (Cycle Detection) [O(n), O(1)]:**
   - Treat the array as a linked list where the value at each index points to the next index.
   - The duplicate number forms a cycle.
   - Find the intersection point, then find the entrance to the cycle (duplicate).

   // Floyd's Tortoise and Hare
   int findDuplicate(vector<int>& nums) {
       int slow = nums[0];
       int fast = nums[0];
       // Phase 1: Find intersection point
       do {
           slow = nums[slow];
           fast = nums[nums[fast]];
       } while (slow != fast);
       // Phase 2: Find entrance to the cycle
       slow = nums[0];
       while (slow != fast) {
           slow = nums[slow];
           fast = nums[fast];
       }
       return slow;
   }

2. **Sorting [O(n log n), O(1)]:**
   - Sort the array and check for consecutive duplicates.

   // Sorting approach
   int findDuplicate(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       for (int i = 1; i < nums.size(); i++) {
           if (nums[i] == nums[i-1]) return nums[i];
       }
       return -1;
   }

3. **Negative Marking [O(n), O(1)]:**
   - For each number, mark the index as visited by negating the value.
   - If you visit an already negative value, that's the duplicate.

   // Negative marking approach
   int findDuplicate(vector<int>& nums) {
       for (int i = 0; i < nums.size(); i++) {
           int idx = abs(nums[i]);
           if (nums[idx] < 0) return idx;
           nums[idx] = -nums[idx];
       }
       return -1;
   }

4. **Binary Search on Value [O(n log n), O(1)]:**
   - Count how many numbers are less than or equal to mid, and adjust search range accordingly.

   // Binary search approach
   int findDuplicate(vector<int>& nums) {
       int low = 1, high = nums.size() - 1, ans = -1;
       while (low <= high) {
           int mid = low + (high - low) / 2;
           int cnt = 0;
           for (int n : nums) if (n <= mid) cnt++;
           if (cnt > mid) {
               ans = mid;
               high = mid - 1;
           } else {
               low = mid + 1;
           }
       }
       return ans;
   }

---------------------------------------------------------------
Below is the improved code with detailed comments and a dry run at the end.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Approach: Floyd's Tortoise and Hare (Cycle Detection)
        // Step 1: Initialize two pointers, slow and fast, both at the start of the array.
        int slow = nums[0];
        int fast = nums[0];

        // Step 2: Move slow by one step and fast by two steps to find the intersection point inside the cycle.
        do {
            slow = nums[slow];         // Move slow pointer by 1 step
            fast = nums[nums[fast]];   // Move fast pointer by 2 steps
        } while (slow != fast);        // Continue until they meet

        // Step 3: Reset slow to the start and move both pointers by one step to find the entrance to the cycle (duplicate).
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];         // Move slow by 1 step
            fast = nums[fast];         // Move fast by 1 step
        }

        // Step 4: The meeting point is the duplicate number.
        return slow;
    }
};

/*
Dry Run Example:
----------------
Input: nums = [1,3,4,2,2]

Step 1: Initialize slow = nums[0] = 1, fast = nums[0] = 1

Step 2:
- slow = nums[1] = 3
- fast = nums[nums[1]] = nums[3] = 2

- slow = nums[3] = 2
- fast = nums[nums[2]] = nums[4] = 2

Now slow = 2, fast = 2 (intersection found)

Step 3:
- Reset slow = nums[0] = 1
- slow = nums[1] = 3, fast = nums[2] = 4
- slow = nums[3] = 2, fast = nums[4] = 2

Now slow = 2, fast = 2 (entrance found)

Return 2 (duplicate number)

Time Complexity: O(n)
Space Complexity: O(1)
*/