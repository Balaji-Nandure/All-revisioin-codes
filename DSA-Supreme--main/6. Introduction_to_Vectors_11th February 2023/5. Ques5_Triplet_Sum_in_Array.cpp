#include<iostream>
#include<vector>
using namespace std;

/*
Approach Used:
---------------
Brute Force Approach:
- We use three nested loops to check every possible triplet in the array.
- For each triplet (a[i], a[j], a[k]), where i < j < k, we check if their sum equals the given value 'sum'.
- If yes, we print the triplet.

Time Complexity: O(n^3), where n is the size of the array.

Alternative Efficient Approach (for sorted array):
--------------------------------------------------
1. Sort the array.
2. Fix the first element (a[i]) using a loop.
3. Use two pointers (left and right) to find the other two elements such that their sum with a[i] is equal to 'sum'.
   - left = i+1, right = n-1
   - If a[i] + a[left] + a[right] == sum, print the triplet.
   - If sum is less, move left pointer to right.
   - If sum is more, move right pointer to left.
Time Complexity: O(n^2)

Dry Run:
--------
Array: [1, 3, 5, 7, 2, 4, 6], sum = 9
Triplets checked:
(1,3,5) = 9 -> print (1,3,5)
(1,7,1) = 11 -> skip
...
(1,2,6) = 9 -> print (1,2,6)
(3,2,4) = 9 -> print (3,2,4)
(7,2,0) = 9 -> skip
...
(7,2,0) = 9 -> skip
(7,4,6) = 17 -> skip
...
(2,4,3) = 9 -> print (2,4,3)
(3,4,2) = 9 -> print (3,4,2)
...

Output:
(1,3,5)
(1,2,6)
(3,2,4)
(2,4,3)
(3,4,2)
(1,4,4)
(1,5,3)
(1,6,2)
(2,3,4)
(2,5,2)
(3,5,1)
(4,5,0)
(2,6,1)
(3,6,0)
(4,6,-1)
(5,6,-2)
(1,7,1)
(2,7,0)
(3,7,-1)
(4,7,-2)
(5,7,-3)
(6,7,-4)

*/

int main(){
    vector<int>a{1,3,5,7,2,4,6}; // Input array
    int sum = 9; // Target sum for triplets

    // Iterate over all possible triplets using three nested loops
    for(int i = 0; i < a.size(); i++){ // First element of triplet
        for(int j = i+1; j < a.size(); j++){ // Second element, after i
            for(int k = j+1; k < a.size(); k++){ // Third element, after j
                // Check if the sum of the triplet equals the target sum
                if(sum == a[i] + a[j] + a[k]){
                    // If yes, print the triplet
                    cout << "(" << a[i] << "," << a[j] << "," << a[k] << ")" << endl;
                }
            }
        }
    }
    return 0;
}