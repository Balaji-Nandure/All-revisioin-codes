/*
Approach Used:
---------------
We use a modified Binary Search to find the last occurrence of a target element in a sorted array (vector).
- Standard binary search finds any occurrence, but to get the *last* occurrence, whenever we find the target, we store the index and continue searching in the right half.
- Time Complexity: O(log n)
- Space Complexity: O(1)

Better Alternatives:
--------------------
1. STL upper_bound:
   - Use C++ STL's upper_bound to find the last occurrence in O(log n) time.
   - Example:
        int idx = upper_bound(v.begin(), v.end(), target) - v.begin() - 1;
        if(idx >= 0 && v[idx] == target) return idx; else return -1;

2. Recursive Binary Search:
   - Can be implemented recursively for the same logic.

3. Linear Search:
   - O(n) time, not efficient for large sorted arrays.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to find the last occurrence of target in sorted vector v
int lastOccurence(const vector<int>& v, int target) {
    int s = 0;                      // Start index of search space
    int e = v.size() - 1;           // End index of search space
    int ans = -1;                   // To store the answer (index of last occurrence), -1 if not found

    while (s <= e) {                 // Continue while search space is valid
        int mid = s + (e - s) / 2;   // Calculate mid to avoid integer overflow

        if (v[mid] == target) {      // If mid element is target
            ans = mid;               // Store current index as possible answer
            s = mid + 1;             // Move right to find later occurrence
        }
        else if (target < v[mid]) {  // If target is less, search left half
            e = mid - 1;
        }
        else {                       // If target is greater, search right half
            s = mid + 1;
        }
    }
    return ans;                      // Return the index of last occurrence or -1 if not found
}

int main() {
    vector<int> v{1, 3, 4, 4, 4, 4, 4, 6, 7, 9}; // Sorted input vector
    int target = 4;
    int index = lastOccurence(v, target);         // Call function to find last occurrence
    cout << index << endl;                        // Output the result
    return 0;
}

/*
Alternative using STL upper_bound (uncomment to use):

#include<algorithm>
int main() {
    vector<int> v{1, 3, 4, 4, 4, 4, 4, 6, 7, 9};
    int target = 4;
    auto it = upper_bound(v.begin(), v.end(), target);
    if (it != v.begin() && *(it-1) == target)
        cout << (it - v.begin() - 1) << endl;
    else
        cout << -1 << endl;
    return 0;
}
*/

/*
Dry Run:
--------
v = [1, 3, 4, 4, 4, 4, 4, 6, 7, 9], target = 4

s = 0, e = 9

1st Iteration:
    mid = 4
    v[4] = 4 == 4
    ans = 4
    s = mid + 1 = 5

2nd Iteration:
    s = 5, e = 9
    mid = 7
    v[7] = 6 > 4
    e = mid - 1 = 6

3rd Iteration:
    s = 5, e = 6
    mid = 5
    v[5] = 4 == 4
    ans = 5
    s = mid + 1 = 6

4th Iteration:
    s = 6, e = 6
    mid = 6
    v[6] = 4 == 4
    ans = 6
    s = mid + 1 = 7

Loop ends (s > e). Final ans = 6 (last occurrence of 4).
*/