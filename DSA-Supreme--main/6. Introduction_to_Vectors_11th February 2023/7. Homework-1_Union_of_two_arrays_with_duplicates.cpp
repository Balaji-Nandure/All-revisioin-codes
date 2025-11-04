/*
Approach Used:
--------------
- The code finds the union of two arrays (a and b) and stores the result in a vector 'output' without duplicates.
- First, all elements of array 'a' are inserted into 'output'.
- Then, for each element in array 'b', it checks if the element is already present in 'output'. If not, it inserts the element.
- This ensures that each element appears only once in the union.

Logic/Comments for Important Lines:
-----------------------------------
- int a[] = {1,2,3,9,10,5}; // First input array
- int sizea = 6;            // Size of first array
- int b[] = {2,3,4,5,6,7,8}; // Second input array
- int sizeb = 7;            // Size of second array
- vector<int>output;        // Vector to store the union result (no duplicates)
- for(int i = 0; i < sizea; i++) output.push_back(a[i]); // Insert all elements of 'a' into 'output'
- For each element in 'b', check if it is already in 'output' using a flag and a loop.
- If not present (flag remains false), insert the element into 'output'.
- Finally, print all elements of 'output' as the union.

Alternative Detailed Approaches:
-------------------------------
1. Using set<int>:
   - Insert all elements of both arrays into a set (automatically removes duplicates).
   - Copy set elements into a vector if needed.
   - This approach gives a sorted union.
   Example:
       set<int> s;
       for(int i=0; i<sizea; i++) s.insert(a[i]);
       for(int i=0; i<sizeb; i++) s.insert(b[i]);
       for(auto it : s) cout << it << " ";

2. Using unordered_set<int> (for unsorted union, but faster insert/search):
   - Same as above, but order is not guaranteed.

3. If arrays are sorted:
   - Use two pointers to merge both arrays, skipping duplicates.
   - This is more efficient (O(n+m) time).

Dry Run:
--------
a = {1,2,3,9,10,5}
b = {2,3,4,5,6,7,8}
Step 1: Insert all elements of 'a' into output:
    output = {1,2,3,9,10,5}
Step 2: For each element in 'b', check if present in output:
    b[0]=2: already in output -> skip
    b[1]=3: already in output -> skip
    b[2]=4: not in output -> insert -> output={1,2,3,9,10,5,4}
    b[3]=5: already in output -> skip
    b[4]=6: not in output -> insert -> output={1,2,3,9,10,5,4,6}
    b[5]=7: not in output -> insert -> output={1,2,3,9,10,5,4,6,7}
    b[6]=8: not in output -> insert -> output={1,2,3,9,10,5,4,6,7,8}
Final output: 1 2 3 9 10 5 4 6 7 8

*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a[] = {1,2,3,9,10,5};      // First input array
    int sizea = 6;                  // Size of first array
    int b[] = {2,3,4,5,6,7,8};     // Second input array
    int sizeb = 7;                  // Size of second array
    bool flag = false;              // Used to check if element is already present in output
    vector<int>output;              // Vector to store the union result

    // Insert all elements of array 'a' into output
    for(int i = 0; i < sizea; i++){
        output.push_back(a[i]);     // Directly insert all elements of 'a'
    }

    // For each element in 'b', check if it is already present in output
    for(int i = 0; i < sizeb; i++){
        flag = false;               // Reset flag for each element of 'b'
        for(int j = 0; j < output.size(); j++){
            if(b[i] == output[j]){  // If element already present
                flag = true;        // Set flag to true
                break;              // No need to check further
            }
        }
        if(!flag){                  // If element not found in output
            output.push_back(b[i]); // Insert element into output
        }
    }

    // Print the union of both arrays (no duplicates)
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    return 0;
}