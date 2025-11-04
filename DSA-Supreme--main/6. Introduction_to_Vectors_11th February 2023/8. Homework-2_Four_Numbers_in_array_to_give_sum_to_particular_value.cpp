#include<iostream>
using namespace std;

/*
Approach Used in This Code:
---------------------------
Brute Force Approach:
- We use 4 nested loops to generate all possible unique quadruplets (i, j, k, l) such that i < j < k < l.
- For each quadruplet, we check if the sum of the four elements equals the target sum.
- If yes, we print the quadruplet.

Time Complexity: O(n^4), where n is the size of the array.
Space Complexity: O(1), as we use no extra space.

Alternative Detailed Approach (with code):
------------------------------------------

1. Sorting + Two Pointer Approach (O(n^3) time):
------------------------------------------------
- Sort the array.
- Fix the first two elements using two loops.
- Use two pointers (left, right) to find the remaining two elements.

Example code:
-------------
#include <algorithm>
void fourSumTwoPointer(int a[], int n, int sum) {
    sort(a, a+n); // Sort the array to use two pointers
    for(int i=0; i<n-3; i++) {
        for(int j=i+1; j<n-2; j++) {
            int left = j+1, right = n-1;
            while(left < right) {
                int total = a[i] + a[j] + a[left] + a[right];
                if(total == sum) {
                    cout << "(" << a[i] << "," << a[j] << "," << a[left] << "," << a[right] << ")" << endl;
                    left++; right--;
                } else if(total < sum) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
}

*/

/*
Dry Run:
---------
Array: [1,2,3,4,5,6,7,8,9,10], sum = 10

i=0 (a[i]=1)
  j=1 (a[j]=2)
    k=2 (a[k]=3)
      l=3 (a[l]=4) -> 1+2+3+4=10 (prints (1,2,3,4))
      l=4 (a[l]=5) -> 1+2+3+5=11 (not printed)
      ...
    k=3 (a[k]=4)
      l=4 (a[l]=5) -> 1+2+4+5=12 (not printed)
      ...
  ...
No other quadruplet sums to 10 in this array.
*/

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10}; // input array
    int sum = 10; // target sum
    int sizea = 10; // size of array

    // Loop for first element
    for(int i = 0; i < sizea; i++){
        // Loop for second element, always after i to avoid duplicates
        for(int j = i+1; j < sizea; j++){
            // Loop for third element, always after j
            for(int k = j+1; k < sizea; k++){
                // Loop for fourth element, always after k
                for(int l = k+1; l < sizea; l++){
                    // Check if sum of four elements is equal to target sum
                    if(a[i] + a[j] + a[k] + a[l] == sum)
                        cout << "(" << a[i] << "," << a[j] << "," << a[k] << "," << a[l] << ")" << endl; // print the quadruplet
                }
            }
        }
    }
    return 0;
}