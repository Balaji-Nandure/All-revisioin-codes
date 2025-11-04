/*
Approach Used:
---------------
- The function `compareStrings` checks if two strings are equal by:
    1. First comparing their lengths. If lengths differ, they can't be equal.
    2. If lengths are same, it compares each character one by one.
    3. If any character mismatches, returns false.
    4. If all characters match, returns true.

Better Alternatives (without code):
-----------------------------------
- Use the built-in equality operator (`==`) for strings in C++: `if(a == b)`.
    - This is more concise, readable, and optimized.
- For C-style strings (char arrays), use `strcmp()` from `<cstring>`.
- For case-insensitive comparison, use `std::equal` with a custom comparator or transform both strings to lower/upper case before comparing.
- For large strings, consider hashing for faster repeated comparisons.

*/

#include<iostream>
using namespace std;

// Function to compare two strings for equality
bool compareStrings(const string& a, const string& b){
    // Check if lengths are different; if so, strings can't be equal
    if(a.length() != b.length()){
        return false;
    }
    int n = a.length(); // Store length for iteration
    // Compare each character of both strings
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){ // If any character doesn't match, return false
            return false;
        }
    }
    // All characters matched, strings are equal
    return true;
}

int main(){
    string a = "bhavya"; // First string
    string b = "bhavya"; // Second string

    // Compare the two strings using compareStrings function
    if(compareStrings(a, b)){
        cout << "Equal"; // Output if strings are equal
    }
    else{
        cout << "Not Equal"; // Output if strings are not equal
    }
    return 0;
}

/*
Dry Run:
--------
Input:
    a = "bhavya"
    b = "bhavya"

Step 1: compareStrings("bhavya", "bhavya")
    - Lengths: 6 == 6 -> continue
    - Compare each character:
        i=0: 'b' == 'b' -> continue
        i=1: 'h' == 'h' -> continue
        i=2: 'a' == 'a' -> continue
        i=3: 'v' == 'v' -> continue
        i=4: 'y' == 'y' -> continue
        i=5: 'a' == 'a' -> continue
    - All characters matched, return true

Step 2: Output "Equal"

Output:
    Equal
*/