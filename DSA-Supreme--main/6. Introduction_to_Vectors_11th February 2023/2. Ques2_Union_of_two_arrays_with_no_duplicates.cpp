/*
Approach Used:
---------------
Brute Force Approach:
- We simply append all elements of both arrays into a single vector (ans).
- This approach does NOT remove duplicates, nor does it sort the result.
- The union here is just the concatenation of both arrays.

Logic/Comments for Important Lines:
-----------------------------------
- We define two arrays, arr and brr, and their sizes.
- We create a vector<int> ans to store the union result.
- First loop: Insert all elements of arr into ans.
- Second loop: Insert all elements of brr into ans.
- Final loop: Print all elements of ans.

Alternative Detailed Approach (with No Duplicates):
---------------------------------------------------
1. Use a set<int> to store unique elements from both arrays.
2. Insert all elements of arr and brr into the set (automatically removes duplicates).
3. Copy set elements into a vector if required (for further processing or printing).
4. This approach gives a sorted union with no duplicates.

Example code for alternative approach:
--------------------------------------
    set<int> s;
    for(int i=0; i<sizea; i++) s.insert(arr[i]);
    for(int i=0; i<sizeb; i++) s.insert(brr[i]);
    for(auto it : s) cout << it << " ";

Dry Run of Current Code:
------------------------
arr = {1,3,5,7,9}
brr = {2,4,6,8}
ans after first loop: {1,3,5,7,9}
ans after second loop: {1,3,5,7,9,2,4,6,8}
Printed Output: 1 3 5 7 9 2 4 6 8

*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[] = {1,3,5,7,9};      // First input array
    int sizea = 5;                // Size of first array
    int brr[] = {2,4,6,8};        // Second input array
    int sizeb = 4;                // Size of second array
    vector<int> ans;              // Vector to store the union (with possible duplicates)

    // Insert all elements of arr into ans
    for(int i=0; i<sizea; i++){
        ans.push_back(arr[i]);    // Appending arr[i] to ans
    }

    // Insert all elements of brr into ans
    for(int i=0; i<sizeb; i++){
        ans.push_back(brr[i]);    // Appending brr[i] to ans
    }

    // Print all elements of ans (union with duplicates)
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";    // Output each element
    }

    return 0;
}

/*
Dry Run:
--------
arr = {1,3,5,7,9}
brr = {2,4,6,8}
Step 1: ans = {}
Step 2: After inserting arr: ans = {1,3,5,7,9}
Step 3: After inserting brr: ans = {1,3,5,7,9,2,4,6,8}
Step 4: Output: 1 3 5 7 9 2 4 6 8
*/