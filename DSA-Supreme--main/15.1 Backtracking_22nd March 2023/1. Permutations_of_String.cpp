#include <iostream>
#include <string>
using namespace std;

// Function to generate all permutations of the input string using backtracking
// Parameters:
//   str - the current configuration of the string being permuted
//   l   - the starting index for this recursion (which character to permute next)
//   r   - the ending index of the string
void permute(string &str, int l, int r) {
    // Base case: if l == r, we've fixed all positions, so print the current permutation
    if (l == r) {
        cout << str << endl; // Output a complete permutation
        return;
    }

    // Try placing every possible character at index l
    for (int i = l; i <= r; i++) {
        swap(str[l], str[i]);          // Swap the current index with i (choose character i for position l)
        permute(str, l + 1, r);        // Recursively generate permutations for the remaining substring
        swap(str[l], str[i]);          // Backtrack: restore the original string before the next iteration
    }
}

int main() {
    string s;
    cout << "Enter a string: "; // Prompt user for input
    cin >> s;                   // Read the string

    cout << "All permutations of the string are:\n";
    // Call the permute function with initial left index 0 and right index s.size() - 1
    // This will display all possible arrangements of the given string
    // cout start time
    permute(s, 0, s.size() - 1);
    // cout end time

    return 0; // Program executed successfully
}
