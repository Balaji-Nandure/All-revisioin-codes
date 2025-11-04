#include<iostream>
using namespace std;

/*
Approach:
- We need to count the number of 0s and 1s in a given array.
- We'll traverse the array once and count the number of 0s and 1s separately.
- For this, we use two functions: zeroArr (to count 0s) and oneArr (to count 1s).
*/

// Function to count number of zeroes in the array
int zeroArr(int arr[], int size) {
    int cnt = 0; // Initialize counter for zeroes
    for(int i = 0; i < size; i++) { // Traverse the array from index 0 to size-1
        if(arr[i] == 0) // If current element is 0, increment the counter
            cnt++;
    }
    return cnt; // Return the total count of zeroes
}

// Function to count number of ones in the array
int oneArr(int arr[], int size) {
    int cnt = 0; // Initialize counter for ones
    for(int i = 0; i < size; i++) { // Traverse the array from index 0 to size-1
        if(arr[i] == 1) // If current element is 1, increment the counter
            cnt++;
    }
    return cnt; // Return the total count of ones
}

int main() {
    int arr[10] = {1,1,0,1,0,0,1,0,1,1}; // Input array containing 0s and 1s
    int size = 10; // Size of the array

    // Call zeroArr to count number of zeroes in the array
    int zeroCount = zeroArr(arr, size);

    // Call oneArr to count number of ones in the array
    int oneCount = oneArr(arr, size);

    // Output the results
    cout << "Number of zeroes are " << zeroCount << endl;
    cout << "Number of ones are " << oneCount << endl;

    return 0;
}

/*
Dry Run:
Input: arr = {1,1,0,1,0,0,1,0,1,1}
Step-by-step for zeroArr:
- i=0: arr[0]=1 -> not zero
- i=1: arr[1]=1 -> not zero
- i=2: arr[2]=0 -> cnt=1
- i=3: arr[3]=1 -> not zero
- i=4: arr[4]=0 -> cnt=2
- i=5: arr[5]=0 -> cnt=3
- i=6: arr[6]=1 -> not zero
- i=7: arr[7]=0 -> cnt=4
- i=8: arr[8]=1 -> not zero
- i=9: arr[9]=1 -> not zero
Final zeroCount = 4

Step-by-step for oneArr:
- i=0: arr[0]=1 -> cnt=1
- i=1: arr[1]=1 -> cnt=2
- i=2: arr[2]=0 -> not one
- i=3: arr[3]=1 -> cnt=3
- i=4: arr[4]=0 -> not one
- i=5: arr[5]=0 -> not one
- i=6: arr[6]=1 -> cnt=4
- i=7: arr[7]=0 -> not one
- i=8: arr[8]=1 -> cnt=5
- i=9: arr[9]=1 -> cnt=6
Final oneCount = 6

Output:
Number of zeroes are 4
Number of ones are 6
*/