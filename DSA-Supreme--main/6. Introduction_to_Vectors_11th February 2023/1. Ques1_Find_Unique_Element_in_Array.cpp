#include<iostream>
#include<vector>
using namespace std;

/*
Approach Used:
--------------
- The problem is to find the unique element in an array where every other element appears exactly twice except one.
- We use the XOR operation to solve this efficiently.
- XOR of a number with itself is 0 (a ^ a = 0), and XOR of a number with 0 is the number itself (a ^ 0 = a).
- By XORing all elements, pairs cancel out and only the unique element remains.

Alternative Detailed Approach:
-----------------------------
- We can use a hash map (unordered_map) to count the frequency of each element.
- Traverse the array and store the count of each element in the map.
- Then, traverse the map to find the element with frequency 1, which is the unique element.
- This approach uses extra space (O(n)), while the XOR approach uses O(1) space.

Example of Alternative Approach (in code):
------------------------------------------
    unordered_map<int, int> freq;
    for(int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }
    for(auto it : freq) {
        if(it.second == 1) {
            return it.first;
        }
    }

*/

int findUniqueElement(vector<int> arr){
    int ans = 0; // Initialize ans to 0, as XOR with 0 returns the number itself
    for(int i = 0; i < arr.size(); i++){
        ans = ans ^ arr[i]; // XOR all elements; duplicates cancel out, leaving the unique element
    }
    return ans; // Return the unique element
}

int main(){
    int n;
    cout << "Enter the size of array " << endl;
    cin >> n; // Input the size of the array

    vector<int> arr(n); // Declare a vector of size n

    cout << "Enter the elements " << endl;
    for(int i = 0; i < arr.size(); i++){
        cin >> arr[i]; // Input array elements
    }

    int uniqueElement = findUniqueElement(arr); // Call function to find unique element

    cout << "Unique element in the array is " << uniqueElement << endl; // Output the unique element

    return 0; // Indicate successful program termination
}

/*
Dry Run:
--------
Input:
n = 5
arr = [2, 3, 1, 6, 3, 6, 2]

Step-by-step XOR:
ans = 0
i=0: ans = 0 ^ 2 = 2
i=1: ans = 2 ^ 3 = 1
i=2: ans = 1 ^ 1 = 0
i=3: ans = 0 ^ 6 = 6
i=4: ans = 6 ^ 3 = 5
i=5: ans = 5 ^ 6 = 3
i=6: ans = 3 ^ 2 = 1

Final Output:
Unique element in the array is 1

Explanation:
All elements except 1 appear twice, so after XORing all, only 1 remains.
*/