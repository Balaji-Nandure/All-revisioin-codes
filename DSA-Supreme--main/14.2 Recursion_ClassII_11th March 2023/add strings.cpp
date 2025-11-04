#include <iostream>
using namespace std;

// Helper function to perform addition of two digits from the end recursively
string addStringsHelper(const string& num1, int i, const string& num2, int j, int carry) {
    // Base case: When both indices are out of bounds and no carry left
    if (i < 0 && j < 0 && carry == 0) return "";
    int digit1 = i >= 0 ? num1[i] - '0' : 0;
    int digit2 = j >= 0 ? num2[j] - '0' : 0;
    int sum = digit1 + digit2 + carry;
    // Recursive call to handle previous digits
    string prev = addStringsHelper(num1, i - 1, num2, j - 1, sum / 10);
    // Append the current digit to the result string
    return prev + char('0' + (sum % 10));
}

// Main function as per Leetcode requirement
string addStrings(string num1, string num2) {
    return addStringsHelper(num1, num1.size() - 1, num2, num2.size() - 1, 0);
}

int main() {
    string num1 = "123456";
    string num2 = "98765";
    cout << "Sum: " << addStrings(num1, num2) << endl; // Output should be 222221
    // Test large numbers
    cout << "Sum: " << addStrings("999", "1") << endl; // Output should be 1000
    return 0;
}
