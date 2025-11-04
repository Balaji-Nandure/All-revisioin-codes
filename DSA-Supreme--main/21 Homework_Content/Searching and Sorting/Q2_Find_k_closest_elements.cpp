// https://leetcode.com/problems/find-k-closest-elements/description/

/*
Approach Used in This Code (Optimal Two Pointer Expansion from Lower Bound):
----------------------------------------------------------------------------

1. **Find the lower bound** (first index where arr[i] >= x) using binary search.
   - This gives us a split: elements to the left are < x, to the right are >= x.
2. **Expand two pointers** (`l` to the left of lower bound, `h` at lower bound) outwards to select the k closest elements:
   - At each step, compare which side (left or right) is closer to x.
   - If both sides are equally close, prefer the left side (smaller element).
   - Move the pointer accordingly and repeat k times.
3. **Return the subarray** between the two pointers after k expansions.

Time Complexity: O(log n + k)
- O(log n) for lower bound binary search, O(k) for expanding pointers.

Space Complexity: O(1) extra (excluding output).

----------------------------------------------------------------------------

**Better Alternative Approaches:**

1. **Two Pointer Shrinking Window (Sliding Window):**
   - Start with the whole array as a window.
   - While window size > k, remove the farther end (compare arr[s] and arr[e]).
   - Time: O(n - k), Space: O(1)
   - See code in comments below.

2. **Heap-based Approach:**
   - Push all elements with their distance to x into a min-heap.
   - Pop k elements with smallest distance.
   - Time: O(n log k), Space: O(k)
   - Not optimal for sorted arrays.

3. **STL lower_bound + Two Pointer Expansion (as in this code):**
   - Most optimal for sorted arrays.

----------------------------------------------------------------------------

**Alternative 1: Two Pointer Shrinking Window (Sliding Window)**
---------------------------------------------------------------
/*
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size() - 1;
    // Shrink window until its size is k
    while (right - left + 1 > k) {
        if (abs(arr[left] - x) > abs(arr[right] - x))
            left++;
        else
            right--;
    }
    return vector<int>(arr.begin() + left, arr.begin() + right + 1);
}
*/

**Alternative 2: Using STL lower_bound and Two Pointers**
---------------------------------------------------------
/*
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int left = right - 1;
    while (k--) {
        if (left < 0) right++;
        else if (right >= arr.size()) left--;
        else if (abs(arr[left] - x) <= abs(arr[right] - x)) left--;
        else right++;
    }
    return vector<int>(arr.begin() + left + 1, arr.begin() + right);
}
*/

----------------------------------------------------------------------------

**Dry Run Example:**
--------------------
arr = [1,2,3,4,5], k = 4, x = 3

- lowerBound(arr, 3) => 2 (arr[2] = 3)
- l = 1, h = 2
- k = 4
  1. l=1, h=2: arr[l]=2, arr[h]=3; |2-3|=1, |3-3|=0 => h++ (h=3)
  2. l=1, h=3: arr[l]=2, arr[h]=4; |2-3|=1, |4-3|=1 => l-- (l=0)
  3. l=0, h=3: arr[l]=1, arr[h]=4; |1-3|=2, |4-3|=1 => h++ (h=4)
  4. l=0, h=4: arr[l]=1, arr[h]=5; |1-3|=2, |5-3|=2 => l-- (l=-1)
- Now, l = -1, h = 4
- Return arr[l+1:h] = arr[0:4] = [1,2,3,4]

----------------------------------------------------------------------------

*/

class Solution {
public:
    // Custom lowerBound function: finds the first index where arr[i] >= x
    int lowerBound(vector<int>& arr, int x) {
        int start = 0;
        int end = arr.size() - 1;
        int ans = arr.size(); // Default to arr.size() if x is greater than all elements
        while (start <= end) {
            int mid = start + (end - start) / 2;
            // If current element is greater or equal to x, it could be our answer
            if (arr[mid] >= x) {
                ans = mid;
                end = mid - 1; // Try to find an even smaller index
            } else {
                start = mid + 1; // Move right
            }
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Find the lower bound index for x
        int h = lowerBound(arr, x); // h points to first element >= x
        int l = h - 1;              // l points to last element < x

        // Expand window to include k closest elements
        while (k--) {
            // If left pointer is out of bounds, move right pointer
            if (l < 0) {
                h++;
            }
            // If right pointer is out of bounds, move left pointer
            else if (h >= arr.size()) {
                l--;
            }
            // Compare which side is closer to x
            else if (abs(arr[l] - x) <= abs(arr[h] - x)) {
                l--; // Prefer left if equally close (smaller value)
            } else {
                h++;
            }
        }
        // Return the subarray of k closest elements
        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }
};

/*
Dry Run Example:
----------------
Input: arr = [1,2,3,4,5], k = 4, x = 3

Step 1: lowerBound(arr, 3) => 2 (arr[2]=3)
         l = 1, h = 2

Step 2: Expand k=4 times:
    1. l=1, h=2: arr[l]=2, arr[h]=3; |2-3|=1, |3-3|=0 => h++
    2. l=1, h=3: arr[l]=2, arr[h]=4; |2-3|=1, |4-3|=1 => l--
    3. l=0, h=3: arr[l]=1, arr[h]=4; |1-3|=2, |4-3|=1 => h++
    4. l=0, h=4: arr[l]=1, arr[h]=5; |1-3|=2, |5-3|=2 => l--

Step 3: l = -1, h = 4
        Return arr[l+1:h] = arr[0:4] = [1,2,3,4]
*/