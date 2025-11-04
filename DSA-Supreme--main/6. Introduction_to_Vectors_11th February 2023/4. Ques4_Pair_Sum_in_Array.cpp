/*
Approach Used:
--------------
- The code finds and prints all unique pairs in the array whose sum is equal to a given value (sum = 9).
- It uses two nested loops:
    - The outer loop picks the first element of the pair.
    - The inner loop picks the second element, starting from the next index to avoid duplicate and self-pairs.
- For each pair, it checks if their sum equals the target sum and prints the pair if it does.

Logic/Comments for Important Lines:
-----------------------------------
- vector<int>a{1,3,5,7,2,4,6}; // Initialize vector with given elements.
- int sum = 9;                 // Target sum for which pairs are to be found.
- for(int i = 0; i < a.size(); i++) // Outer loop to pick first element of pair.
- for(int j = i + 1; j < a.size(); j++) // Inner loop to pick second element, ensuring unique pairs.
- if(a[i] + a[j] == sum) // Check if the sum of the pair equals the target sum.
- cout << "(" << a[i] << "," << a[j] << ")" << endl; // Print the pair if condition is met.

Alternative Detailed Approach:
-----------------------------
- Use a hash set to store elements seen so far.
- For each element x in the array:
    - Check if (sum - x) exists in the set.
    - If yes, print the pair (sum - x, x).
    - Insert x into the set.
- This approach finds all unique pairs in O(n) time and avoids printing duplicate pairs.

Example code for alternative approach:
--------------------------------------
    unordered_set<int> s;
    for(int i = 0; i < a.size(); i++) {
        int complement = sum - a[i];
        if(s.find(complement) != s.end()) {
            cout << "(" << complement << "," << a[i] << ")" << endl;
        }
        s.insert(a[i]);
    }

*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>a{1,3,5,7,2,4,6}; // Initialize vector with elements
    int sum = 9;                  // Target sum for pairs

    // Printing all unique pairs (regardless of sum)
    cout << "All unique pairs:" << endl;
    for(int i = 0; i < a.size(); i++){ // Pick first element
        for(int j = i + 1; j < a.size(); j++){ // Pick second element after i
            cout << "(" << a[i] << "," << a[j] << ")" << endl; // Print the pair
        }
    }

    // Printing pairs whose sum is equal to 'sum'
    cout << "Printing pairs whose sum is " << sum << ":" << endl;
    for(int i = 0; i < a.size(); i++){ // Pick first element
        for(int j = i + 1; j < a.size(); j++){ // Pick second element after i
            if(a[i] + a[j] == sum) // Check if sum matches
                cout << "(" << a[i] << "," << a[j] << ")" << endl; // Print the pair
        }
    }
    return 0;
}

/*
Dry Run:
--------
Array: [1, 3, 5, 7, 2, 4, 6]
Target sum: 9

All unique pairs:
(1,3) (1,5) (1,7) (1,2) (1,4) (1,6)
(3,5) (3,7) (3,2) (3,4) (3,6)
(5,7) (5,2) (5,4) (5,6)
(7,2) (7,4) (7,6)
(2,4) (2,6)
(4,6)

Pairs whose sum is 9:
(1,8) // not present
(3,6) -> 3+6=9, print (3,6)
(5,4) -> 5+4=9, print (5,4)
(7,2) -> 7+2=9, print (7,2)

So, output will be:
(3,6)
(5,4)
(7,2)
*/