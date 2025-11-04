#include <iostream>
using namespace std;

// Recursive function to print subsequences
void printSubsequences(string s, string output, int index) {
    // Base case: reached end of string
    if (index == s.size()) {
        if (output != "") // skip empty subsequence if you want
            cout << output << endl;
        return;
    }

    // Choice 1: exclude current character
    printSubsequences(s, output, index + 1);

    // Choice 2: include current character
    printSubsequences(s, output + s[index], index + 1);
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Subsequences of string:\n";
    printSubsequences(s, "", 0);

    return 0;
}
// Input:
// abc


// Output:
// c
// b
// bc
// a
// ac
// ab
// abc