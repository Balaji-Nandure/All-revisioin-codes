#include <iostream>
using namespace std;

// Recursive function to check if a string is a palindrome
bool isPalindrome(const string& s, int left, int right) {
    // Base case: If left index crosses right, entire string checked
    if (left >= right) return true;
    // If characters at current indices don't match, not a palindrome
    if (s[left] != s[right]) return false;
    // Move towards the center
    return isPalindrome(s, left + 1, right - 1);
}

int main() {
    // Fixed test string
    string s = "madam"; // You can change this string to test other cases

    // Check and display the result
    if (isPalindrome(s, 0, s.length() - 1)) {
        cout << s << " is a Palindrome" << endl;
    } else {
        cout << s << " is Not a Palindrome" << endl;
    }
    return 0;
}