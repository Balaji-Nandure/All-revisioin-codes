#include<iostream>
#include<vector>
using namespace std;

/*
Approach Used:
--------------
- This code sorts an array containing only 0s and 1s in a single pass (O(n) time, O(1) space).
- It uses a two-pointer approach:
    - 's' (start) points to the beginning of the array.
    - 'e' (end) points to the end of the array.
    - 'i' is the current index being checked.
- The idea is to move all 0s to the front and all 1s to the back by swapping as needed.

Logic/Comments for Important Lines:
-----------------------------------
- vector<int>arr{...}; // Initialize the array with 0s and 1s.
- int s = 0;           // 's' is the pointer for the next position to place 0.
- int e = arr.size()-1;// 'e' is the pointer for the next position to place 1.
- int i = 0;           // 'i' is the current index being checked.
- while(s <= e){       // Continue until all elements are processed.
    - if(arr[i]==0){   // If current element is 0,
        swap(arr[s],arr[i]); // Move it to the front (position 's').
        i++;           // Move to next element (safe because swapped-in element at i is already processed).
        s++;           // Increment 's' to next front position.
    }
    - else if(arr[i]==1){ // If current element is 1,
        swap(arr[e],arr[i]); // Move it to the back (position 'e').
        e--;           // Decrement 'e' to next back position.
        // Do NOT increment i, because the swapped-in element at i may be 0 or 1 and needs to be checked.
    }
}
- for(int i = 0; i < arr.size(); i++){ cout << arr[i] << " "; } // Print the sorted array.

Alternative Detailed Approach:
-----------------------------
- Count the number of 0s and 1s in the array in a single pass.
- Fill the array with that many 0s followed by that many 1s.
Example:
    int count0 = 0, count1 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0) count0++;
        else count1++;
    }
    for(int i = 0; i < count0; i++) arr[i] = 0;
    for(int i = count0; i < arr.size(); i++) arr[i] = 1;
- This approach also works in O(n) time but requires two passes.

Dry Run:
--------
Initial array: [0,1,0,1,1,0,1,0,1,1,0,1,0]
s=0, e=12, i=0

Step 1: arr[i]=0 → swap arr[s],arr[i] (no change), s=1, i=1
Step 2: arr[i]=1 → swap arr[e],arr[i] (arr[12]=0, arr[1]=1) → arr=[0,0,0,1,1,0,1,0,1,1,0,1,1], e=11
Step 3: arr[i]=0 → swap arr[s],arr[i] (no change), s=2, i=2
Step 4: arr[i]=0 → swap arr[s],arr[i] (no change), s=3, i=3
Step 5: arr[i]=1 → swap arr[e],arr[i] (arr[11]=1, arr[3]=1), e=10
Step 6: arr[i]=1 → swap arr[e],arr[i] (arr[10]=0, arr[3]=1) → arr=[0,0,0,0,1,0,1,0,1,1,1,1,1], e=9
Step 7: arr[i]=0 → swap arr[s],arr[i] (arr[3]=0, arr[5]=0), s=4, i=6
Step 8: arr[i]=1 → swap arr[e],arr[i] (arr[9]=1, arr[6]=1), e=8
Step 9: arr[i]=0 → swap arr[s],arr[i] (arr[4]=1, arr[6]=0) → arr=[0,0,0,0,0,0,1,0,1,1,1,1,1], s=5, i=7
Step 10: arr[i]=0 → swap arr[s],arr[i] (arr[5]=0, arr[7]=0), s=6, i=8
Step 11: arr[i]=1 → swap arr[e],arr[i] (arr[8]=1, arr[8]=1), e=7

Loop ends (s=6, e=7, i=8, but s>e). Final array: [0,0,0,0,0,0,0,1,1,1,1,1,1]

Output: 0 0 0 0 0 0 0 1 1 1 1 1 1
*/

int main(){
    vector<int>arr{0,1,0,1,1,0,1,0,1,1,0,1,0}; // Input array with 0s and 1s
    int s = 0; // Start pointer for 0s
    int e = arr.size() - 1; // End pointer for 1s
    int i = 0; // Current index

    while(s <= e){
        // If current element is 0, move it to the front
        if(arr[i] == 0){
            swap(arr[s], arr[i]); // Place 0 at the front
            i++; // Move to next element (safe, as swapped-in element is already processed)
            s++; // Next position for 0
        }
        // If current element is 1, move it to the back
        else if(arr[i] == 1){
            swap(arr[e], arr[i]); // Place 1 at the back
            e--; // Next position for 1
            // Do not increment i, as swapped-in element needs to be checked
        }
    }

    // Print the sorted array
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}