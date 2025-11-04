/*
Approach Used:
---------------
We are using a modified Binary Search to find the first occurrence of a target element in a sorted array (vector).
- Standard binary search finds any occurrence, but to get the *first* occurrence, whenever we find the target, we store the index and continue searching in the left half.
- Time Complexity: O(log n)
- Space Complexity: O(1)

Better Alternatives:
--------------------
1. STL lower_bound:
   - Use C++ STL's lower_bound to find the first occurrence in O(log n) time.
   - Example:
        int idx = lower_bound(v.begin(), v.end(), target) - v.begin();
        if(idx < v.size() && v[idx] == target) return idx; else return -1;

2. Recursive Binary Search:
   - Can be implemented recursively for the same logic.

3. Linear Search:
   - O(n) time, not efficient for large sorted arrays.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to find the first occurrence of target in sorted vector v
int firstOccurence(const vector<int>& v, int target) {
    int s = 0;                      // Start index of search space
    int e = v.size() - 1;           // End index of search space
    int ans = -1;                   // To store the answer (index of first occurrence), -1 if not found

    while (s <= e) {                 // Continue while search space is valid
        int mid = s + (e - s) / 2;   // Calculate mid to avoid integer overflow

        if (v[mid] == target) {      // If mid element is target
            ans = mid;               // Store current index as possible answer
            e = mid - 1;             // Move left to find earlier occurrence
        }
        else if (target < v[mid]) {  // If target is less, search left half
            e = mid - 1;
        }
        else {                       // If target is greater, search right half
            s = mid + 1;
        }
    }
    return ans;                      // Return the index of first occurrence or -1 if not found
}

int main() {
    vector<int> v{1, 3, 4, 4, 4, 4, 4, 6, 7, 9}; // Sorted input vector
    int target = 4;
    int index = firstOccurence(v, target);        // Call function to find first occurrence
    cout << index << endl;                        // Output the result
    return 0;
}

/*
Alternative using STL lower_bound (uncomment to use):

#include<algorithm>
int main() {
    vector<int> v{1, 3, 4, 4, 4, 4, 4, 6, 7, 9};
    int target = 4;
    auto it = lower_bound(v.begin(), v.end(), target);
    if (it != v.end() && *it == target)
        cout << (it - v.begin()) << endl;
    else
        cout << -1 << endl;
    return 0;
}
*/

/*
Dry Run:
--------
Input: v = {1, 3, 4, 4, 4, 4, 4, 6, 7, 9}, target = 4

Initial: s=0, e=9, ans=-1

1st Iteration:
    mid = 0 + (9-0)/2 = 4
    v[4]=4 == target
    ans = 4
    e = 3

2nd Iteration:
    s=0, e=3
    mid = 0 + (3-0)/2 = 1
    v[1]=3 < target
    s = 2

3rd Iteration:
    s=2, e=3
    mid = 2 + (3-2)/2 = 2
    v[2]=4 == target
    ans = 2
    e = 1

Loop ends (s=2, e=1)
Return ans = 2

Output: 2 (first occurrence of 4 is at index 2)
*/