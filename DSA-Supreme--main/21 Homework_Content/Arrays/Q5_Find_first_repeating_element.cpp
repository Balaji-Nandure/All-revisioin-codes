// https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1

/*
Approach Used (Current):
------------------------
1. Count the frequency of each element using an unordered_map.
2. Traverse the array again and return the index (1-based) of the first element whose frequency is >= 2.

Time Complexity: O(n)
Space Complexity: O(n)

Why this works:
- The first pass counts occurrences.
- The second pass finds the first element that repeats.

Better Alternative (Optimized Approach):
---------------------------------------
We can optimize space by storing the first occurrence index of each element.
Or, we can use an unordered_set to track seen elements and return the first index where an element is already seen.

Alternative Code (using unordered_set):
---------------------------------------
    unordered_set<int> seen;
    for(int i = 0; i < n; i++) {
        if(seen.find(arr[i]) != seen.end()) {
            return i+1;
        }
        seen.insert(arr[i]);
    }
    return -1;

This also runs in O(n) time and O(n) space, but avoids counting all frequencies.

Brute Force Approach (for reference):
-------------------------------------
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                return i+1;
            }
        }
    }
    return -1;
Time Complexity: O(n^2), not recommended for large n.

Dry Run Example:
----------------
Input: arr = [1, 5, 3, 4, 3, 5, 6], n = 7

First pass (count frequencies):
    hash = {1:1, 5:2, 3:2, 4:1, 6:1}
Second pass (find first repeating):
    i=0: arr[0]=1, hash[1]=1 -> not repeating
    i=1: arr[1]=5, hash[5]=2 -> repeating, return 2

So, output is 2 (1-based index of first repeating element).

*/

#include <unordered_map>
using namespace std;

class Solution {
  public:
    int firstRepeated(int arr[], int n) {
        // Create a hash map to store the frequency of each element
        unordered_map<int, int> hash;
        for(int i = 0; i < n; i++) {
            // Increment the count for arr[i]
            hash[arr[i]]++;
        }
        // Traverse the array to find the first element with frequency >= 2
        for(int i = 0; i < n; i++) {
            // If current element appears more than once, it's the first repeating
            if(hash[arr[i]] >= 2) {
                return i + 1; // Return 1-based index
            }
        }
        // If no repeating element found, return -1
        return -1;
    }
};

/*
Alternative Optimized Approach (using unordered_set):

#include <unordered_set>
using namespace std;

class Solution {
  public:
    int firstRepeated(int arr[], int n) {
        unordered_set<int> seen;
        for(int i = 0; i < n; i++) {
            // If element is already seen, it's the first repeating
            if(seen.find(arr[i]) != seen.end()) {
                return i + 1; // Return 1-based index
            }
            // Mark element as seen
            seen.insert(arr[i]);
        }
        // No repeating element found
        return -1;
    }
};

*/

/*
Dry Run for arr = [1, 5, 3, 4, 3, 5, 6], n = 7

First pass (hash):
    i=0: hash[1]=1
    i=1: hash[5]=1
    i=2: hash[3]=1
    i=3: hash[4]=1
    i=4: hash[3]=2
    i=5: hash[5]=2
    i=6: hash[6]=1

Second pass:
    i=0: arr[0]=1, hash[1]=1 -> not repeating
    i=1: arr[1]=5, hash[5]=2 -> repeating, return 2

Output: 2

*/