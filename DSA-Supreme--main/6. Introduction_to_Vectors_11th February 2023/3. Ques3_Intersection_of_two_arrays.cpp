#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/*
Approach Used:
---------------
- We are given two arrays and need to find their intersection (common elements).
- For each element in the first array (arr), we check every element in the second array (brr).
- If a match is found, we add it to the answer vector and mark the matched element in brr as INT_MIN to avoid counting duplicates.

Key Points:
-----------
- Marking brr[j] as INT_MIN ensures that if there are duplicate elements in arr, we don't count the same element from brr more than once.
- The time complexity is O(n*m), where n and m are the sizes of arr and brr respectively.

Alternative Approach (Efficient):
---------------------------------
1. Sort both arrays.
2. Use two pointers (i, j) starting from the beginning of both arrays.
3. If arr[i] == brr[j], add to result and increment both pointers.
4. If arr[i] < brr[j], increment i; else increment j.
5. This approach has time complexity O(n log n + m log m) due to sorting, but O(n + m) for the intersection step.

Example Dry Run:
----------------
arr = [1,2,3,3,4,6,8]
brr = [3,4,9,10]

Step-by-step:
- i=0: arr[0]=1, no match in brr
- i=1: arr[1]=2, no match in brr
- i=2: arr[2]=3, matches brr[0]=3 -> add 3 to ans, set brr[0]=INT_MIN
- i=3: arr[3]=3, brr[0]=INT_MIN (already used), no match
- i=4: arr[4]=4, matches brr[1]=4 -> add 4 to ans, set brr[1]=INT_MIN
- i=5: arr[5]=6, no match in brr
- i=6: arr[6]=8, no match in brr

Final ans = [3, 4]

*/

int main(){
    int arr[] = {1,2,3,3,4,6,8}; // First array
    int sizea = 7; // Size of first array
    int brr[] = {3,4,9,10}; // Second array
    int sizeb = 4; // Size of second array
    vector<int>ans; // To store intersection elements

    // Loop through each element of arr
    for(int i = 0; i < sizea; i++){
        // For each element in arr, check all elements in brr
        for(int j = 0; j < sizeb; j++){
            // If a common element is found
            if(arr[i] == brr[j]){
                brr[j] = INT_MIN; // Mark brr[j] as used to avoid duplicate counting
                ans.push_back(arr[i]); // Add to answer vector
                break; // Once matched, break to avoid multiple counts for same arr[i]
            }
        }
    }

    // Output the intersection elements
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Dry Run:
--------
arr = [1,2,3,3,4,6,8]
brr = [3,4,9,10]

Iteration:
i=0: arr[0]=1, no match in brr
i=1: arr[1]=2, no match in brr
i=2: arr[2]=3, matches brr[0]=3 -> ans=[3], brr=[INT_MIN,4,9,10]
i=3: arr[3]=3, brr[0]=INT_MIN (skip), no match
i=4: arr[4]=4, matches brr[1]=4 -> ans=[3,4], brr=[INT_MIN,INT_MIN,9,10]
i=5: arr[5]=6, no match in brr
i=6: arr[6]=8, no match in brr

Output: 3 4
*/