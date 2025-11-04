/*
    Approach Used:
    --------------
    - The code finds the index of the element that occurs an odd number of times in a sorted array where every other element occurs an even number of times (usually twice).
    - It uses a modified binary search to achieve O(log n) time complexity.
    - The key observation is: 
        * In a sorted array with pairs, the first occurrence of each pair is at an even index, and the second at an odd index, until the odd-occurring element disrupts this pattern.
        * By checking the parity of mid and comparing with neighbors, we can decide which half to search next.

    Better/Alternative Approaches (without code):
    ---------------------------------------------
    1. **Linear Scan:**
        - Traverse the array and compare each element with its neighbor.
        - Time Complexity: O(n)
        - Not efficient for large arrays.

    2. **XOR Approach:**
        - XOR all elements. Pairs cancel out, leaving the odd-occurring element.
        - Time Complexity: O(n), Space: O(1)
        - Does not give index, only the value.

    3. **Hash Map:**
        - Count occurrences of each element.
        - Time Complexity: O(n), Space: O(n)
        - Overkill for sorted arrays.

    4. **Modified Binary Search (Used Here):**
        - O(log n) time, O(1) space.
        - Efficient for sorted arrays.

    Dry Run Example:
    ----------------
    Input: v = [1,1,2,2,3,3,4,4,3,600,600,4,4]
    Let's find the odd-occurring element:
    - Initial: s=0, e=12, mid=6, v[6]=4
      mid is even, v[6]==v[7] (4==4), so s=8
    - Now: s=8, e=12, mid=10, v[10]=600
      mid is even, v[10]==v[11] (600==600), so s=12
    - Now: s=12, e=12, only one element left, return s=12
    - v[12]=4 is the answer (odd-occurring element).

    Code with detailed comments:
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to find the index of the odd-occurring element in a sorted array
int solve(const vector<int>& v) {
    int s = 0;                          // Start index of search space
    int e = v.size() - 1;               // End index of search space

    // Binary search loop
    while (s < e) {
        int mid = s + (e - s) / 2;      // Calculate mid to avoid overflow

        // Ensure mid is even for comparison with next element
        if (mid % 2 == 1) {
            mid--;                      // Make mid even (so pairs are at mid and mid+1)
        }

        // If the pair at mid and mid+1 is equal, odd element is in right half
        if (mid + 1 < v.size() && v[mid] == v[mid + 1]) {
            s = mid + 2;                // Move start to the right of this pair
        } else {
            // Otherwise, odd element is at mid or in left half
            e = mid;                    // Move end to mid (could be the answer)
        }
    }
    // When s == e, we've found the odd-occurring element
    return s;
}

int main() {
    // Example input: all elements occur even number of times except one
    vector<int> v{1,1,2,2,3,3,4,4,3,600,600,4,4};

    int ans = solve(v);                 // Find index of odd-occurring element

    cout << v[ans] << endl;             // Output the odd-occurring element

    return 0;
}

/*
Dry Run:
--------
Input: v = [1,1,2,2,3,3,4,4,3,600,600,4,4]
Step 1: s=0, e=12, mid=6 (even), v[6]=4, v[7]=4 -> equal, s=8
Step 2: s=8, e=12, mid=10 (even), v[10]=600, v[11]=600 -> equal, s=12
Step 3: s=12, e=12, only one element left, return s=12
Output: v[12]=4
*/