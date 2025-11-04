#include <iostream> // Include the standard input-output stream library // This is required to use cout and other IO features
using namespace std; // Use the standard namespace // Avoids the need to prefix std:: everywhere

int lastOccurLTR(const string& str, char c, int idx) { // Function to find last occurrence from left to right recursively // 'str' is the string to search, 'c' is the character, 'idx' is the current index
    if (idx == str.length()) return -1; // Base case: if idx reaches length, no occurrence found, return -1 // Checks if the end of string is reached
    int res = lastOccurLTR(str, c, idx + 1); // Recursive call to move to the next character // Searches for 'c' in the rest of the string
    if (res != -1) return res; // If character found in deeper recursion, return its index // Avoids overwriting a later occurrence if found
    return (str[idx] == c) ? idx : -1; // If not found ahead, check current index for match // Returns current index if match found, else -1
}

int lastOccurRTL(const string& str, char c, int idx) { // Function to find last occurrence from right to left recursively // Parameters: the string, the character to find, and the current index to check
    if (idx < 0) return -1; // Base case: if idx is negative, search is out of bounds // Return -1 indicating character not found
    if (str[idx] == c) return idx; // If the current character matches, return its index // Captures the first-found match from the right
    return lastOccurRTL(str, c, idx - 1); // Recursive call to move to previous character // Continues search backwards through the string
}

int main() { // Entry point of the program // main runs the test cases for the functions
    string str = "abcbdbefb"; // Test string to search in // Contains multiple occurrences of 'b'
    char ch = 'b'; // Character to find in the string // Looking for the last 'b'
    int ltr = lastOccurLTR(str, ch, 0); // Find last 'b' using left-to-right recursion // Initial call starts at index 0
    cout << "LTR: " << ltr << endl; // Output the index found by left-to-right method // Displays result with label

    int rtl = lastOccurRTL(str, ch, str.size()-1); // Find last 'b' using right-to-left recursion // Initial call starts at last index
    cout << "RTL: " << rtl << endl; // Output the index found by right-to-left method // Displays result with label
    return 0; // Indicate successful program termination // Standard return from main function
}
