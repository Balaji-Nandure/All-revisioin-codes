#include<iostream>
using namespace std;

/*
    Problem: Given an array of size n containing numbers from 1 to n (with possible duplicates), 
    find all the missing numbers in the array.

    Approach Used (Cyclic Sort / Index Placement):
    ------------------------------------------------
    - The idea is to place each number at its correct index (i.e., value x should be at index x-1).
    - After rearrangement, if at any index i, arr[i] != i+1, then (i+1) is missing.
    - This approach works in O(n) time and O(1) extra space (modifies the input array).

    Alternative Approaches (with code in comments):
    ------------------------------------------------
    1. Marking Visited Indices (Negation Method):
        - For each value x in arr, mark arr[x-1] as negative.
        - After processing, indices with positive values correspond to missing numbers.
        - See commented code below for implementation.

    2. Using Hashing (Extra Space):
        - Use a boolean or integer array of size n+1 to mark presence.
        - Traverse arr and mark present numbers.
        - Traverse the marker array to find missing numbers.
        - This uses O(n) extra space.

    3. Mathematical Approach (Sum Formula):
        - Not suitable for duplicates, as it only works when exactly one number is missing and no duplicates.

    Dry Run is provided at the end of the code.
*/

void findMissing(int arr[], int n) {
    // Cyclic Sort / Index Placement Approach
    int i = 0;
    while (i < n) {
        int correctIndex = arr[i] - 1; // The index where arr[i] should be placed
        // Only swap if arr[i] is not at its correct position and arr[i] is not already at its correct position (to avoid infinite loop with duplicates)
        if (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[correctIndex]) {
            swap(arr[i], arr[correctIndex]); // Place arr[i] at its correct position
        } else {
            i++; // Move to next index if already placed or duplicate found
        }
    }

    // After placement, if arr[i] != i+1, then (i+1) is missing
    cout << "Missing elements: ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << (i + 1) << " ";
            found = true;
        }
    }
    if (!found) cout << "None";
    cout << endl;
    
    /*
    // Alternative 1: Marking Visited Indices (Negation Method)
    // (Uncomment to use)
    // for (int i = 0; i < n; i++) {
    //     int index = abs(arr[i]) - 1;
    //     if (index >= 0 && index < n && arr[index] > 0) {
    //         arr[index] = -arr[index]; // Mark as visited
    //     }
    // }
    // cout << "Missing elements: ";
    // for (int i = 0; i < n; i++) {
    //     if (arr[i] > 0) {
    //         cout << (i + 1) << " ";
    //     }
    // }
    // cout << endl;

    // Alternative 2: Using Hashing (Extra Space)
    // (Uncomment to use)
    // bool present[n+1] = {false};
    // for (int i = 0; i < n; i++) {
    //     if (arr[i] >= 1 && arr[i] <= n)
    //         present[arr[i]] = true;
    // }
    // cout << "Missing elements: ";
    // for (int i = 1; i <= n; i++) {
    //     if (!present[i]) cout << i << " ";
    // }
    // cout << endl;
    */
}

int main() {
    int n = 5;
    int arr[] = {5, 3, 5, 3, 5};
    findMissing(arr, n);
    return 0;
}

/*
Dry Run:
--------
Input: arr = {5, 3, 5, 3, 5}, n = 5

Step 1: Cyclic sort to place each number at its correct index:
    i=0: arr[0]=5, correctIndex=4, arr[0]!=arr[4] => swap arr[0] and arr[4] => arr={5,3,5,3,5} (no change, as arr[0]==arr[4])
    i=0: arr[0]=5, correctIndex=4, arr[0]==arr[4] => i++
    i=1: arr[1]=3, correctIndex=2, arr[1]!=arr[2] => swap arr[1] and arr[2] => arr={5,5,3,3,5}
    i=1: arr[1]=5, correctIndex=4, arr[1]==arr[4] => i++
    i=2: arr[2]=3, correctIndex=2, arr[2]==arr[2] => i++
    i=3: arr[3]=3, correctIndex=2, arr[3]!=arr[2] => swap arr[3] and arr[2] => arr={5,5,3,3,5}
    i=3: arr[3]=3, correctIndex=2, arr[3]==arr[2] => i++
    i=4: arr[4]=5, correctIndex=4, arr[4]==arr[4] => i++

Step 2: Find missing numbers:
    i=0: arr[0]=5 != 1 => 1 is missing
    i=1: arr[1]=5 != 2 => 2 is missing
    i=2: arr[2]=3 == 3 => not missing
    i=3: arr[3]=3 != 4 => 4 is missing
    i=4: arr[4]=5 == 5 => not missing

Output: Missing elements: 1 2 4

Time Complexity: O(n)
Space Complexity: O(1) (ignoring input array modification)
*/