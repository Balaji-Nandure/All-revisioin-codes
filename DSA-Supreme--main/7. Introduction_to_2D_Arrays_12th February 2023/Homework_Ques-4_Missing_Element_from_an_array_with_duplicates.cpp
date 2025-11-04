/*
Approach Used:
---------------
This code finds all the missing elements from an array of size n containing numbers from 1 to n, where some elements may be duplicated and some may be missing. The approach is to use the input array itself for marking visited numbers by negating the value at the index corresponding to each number. After marking, the indices with positive values correspond to the missing numbers.

Time Complexity: O(n)
Space Complexity: O(1) (ignoring output and input array)

Steps:
1. For each element in the array, use its absolute value as an index (after subtracting 1 for 0-based indexing).
2. Negate the value at that index to mark it as visited (if not already negative).
3. After processing, the indices with positive values correspond to missing numbers.

Better Alternatives:
--------------------
1. Using Hashing (Extra Space):
   - Use an auxiliary array or unordered_set to keep track of seen numbers.
   - Time: O(n), Space: O(n)
   - See code in comments below.

2. Cyclic Sort Approach:
   - Place each number at its correct index (i.e., arr[i] = i+1).
   - Then, missing numbers are those where arr[i] != i+1.
   - Time: O(n), Space: O(1)
   - See code in comments below.

3. Mathematical Approach (only for single missing, no duplicates):
   - Use sum formula to find the missing number.
   - Not suitable for duplicates.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include<iostream>
#include<vector>
#include<cmath> // use <cmath> instead of <math.h>
using namespace std;

// Function to print all missing elements in the array
void printMissingElement(vector<int>& arr) {
    int n = arr.size();

    // Mark the presence of each number by negating the value at its corresponding index
    for(int i = 0; i < n; i++) {
        int index = abs(arr[i]); // Get the absolute value in case it's already been marked

        // Only mark if the value at (index-1) is positive (not yet visited)
        if(arr[index - 1] > 0) {
            arr[index - 1] = -arr[index - 1]; // Mark as visited by negating
        }
    }

    // After marking, the indices with positive values are the missing numbers
    cout << "Missing elements are: ";
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) { // If value is positive, (i+1) is missing
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}

/*
Alternative 1: Using Hashing (Extra Space)
------------------------------------------
#include<unordered_set>
void printMissingElementHashing(const vector<int>& arr) {
    int n = arr.size();
    unordered_set<int> s(arr.begin(), arr.end());
    cout << "Missing elements are: ";
    for(int i = 1; i <= n; i++) {
        if(s.find(i) == s.end()) {
            cout << i << " ";
        }
    }
    cout << endl;
}
*/

/*
Alternative 2: Cyclic Sort Approach (In-place, O(1) space)
----------------------------------------------------------
void printMissingElementCyclicSort(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    while(i < n) {
        int correctIdx = arr[i] - 1;
        if(arr[i] != arr[correctIdx]) {
            swap(arr[i], arr[correctIdx]);
        } else {
            i++;
        }
    }
    cout << "Missing elements are: ";
    for(int i = 0; i < n; i++) {
        if(arr[i] != i + 1) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}
*/

int main() {
    vector<int> arr{1, 3, 3, 3, 4};
    printMissingElement(arr);

    // Uncomment below to test alternative approaches:
    // printMissingElementHashing(arr);
    // printMissingElementCyclicSort(arr);

    return 0;
}

/*
Dry Run:
--------
Input: arr = {1, 3, 3, 3, 4}
Step 1: Marking
i=0: index=1, arr[0]=1 > 0 => arr[0]=-1 => arr={-1,3,3,3,4}
i=1: index=3, arr[2]=3 > 0 => arr[2]=-3 => arr={-1,3,-3,3,4}
i=2: index=3, arr[2]=-3 < 0 => already marked, do nothing
i=3: index=3, arr[2]=-3 < 0 => already marked, do nothing
i=4: index=4, arr[3]=3 > 0 => arr[3]=-3 => arr={-1,3,-3,-3,4}

Step 2: Find missing
arr[0]=-1 (negative) => 1 is present
arr[1]=3 (positive) => 2 is missing
arr[2]=-3 (negative) => 3 is present
arr[3]=-3 (negative) => 4 is present
arr[4]=4 (positive) => 5 is missing

Output: Missing elements are: 2 5
*/