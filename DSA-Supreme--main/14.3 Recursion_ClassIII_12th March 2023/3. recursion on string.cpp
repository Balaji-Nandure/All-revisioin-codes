#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// This function prints each character of the string one by one using recursion.
// It starts at index 0 and prints the character at that position, then moves to the next.
// If we've reached the end of the string, it stops.
void printChars(string s, int index = 0) {
    if (index == s.size()) return;      // Base case: if index is past last character, stop.
    cout << s[index] << " ";            // Print the current character.
    printChars(s, index + 1);           // Call function for next character.
}

// This function returns the reversed version of the input string using recursion.
// It moves to the end first (base case), then as the calls return it adds characters from back to front.
string reverseString(string s, int index = 0) {
    if (index == s.size()) return "";   // Base case: past end of string, return empty.
    // Go to next character, then add this one to the end of what comes back.
    return reverseString(s, index + 1) + s[index];
}

// This function checks if a string is a palindrome (reads the same backwards and forwards).
// It compares the first and last characters, moving inward recursively.
// If all pairs are equal, it's a palindrome.
bool isPalindrome(string s, int start = 0, int end = -1) {
    if (end == -1) end = s.size() - 1;   // Initialize end on first call if not given.
    if (start >= end) return true;       // If indices cross, all checks passed.
    if (s[start] != s[end]) return false; // Mismatch found, not a palindrome.
    return isPalindrome(s, start + 1, end - 1); // Check next pair inward.
}

// This function counts how many times a given character ('key') appears in the string.
// It looks at one character per call, counting it if it matches, then proceeds to the next.
int countChar(string s, char key, int index = 0) {
    if (index == s.size()) return 0;                // Base case: finished string.
    // Add 1 if current matches, plus what is found in the rest.
    return (s[index] == key ? 1 : 0) + countChar(s, key, index + 1);
}

// This function finds the position of the first time 'key' appears in the string.
// It searches from the left; if it's found, returns the index, else -1.
int firstOccurrence(string s, char key, int index = 0) {
    if (index == s.size()) return -1;          // Base case: not found at all.
    if (s[index] == key) return index;         // Found at current index.
    return firstOccurrence(s, key, index + 1); // Check rest of string.
}

// This function finds the position of the last time 'key' appears in the string.
// It searches all the way to the end, then as calls return, reports the latest found index.
int lastOccurrence(string s, char key, int index = 0) {
    if (index == s.size()) return -1; // Base case: checked all characters.
    // Search further right first.
    int restIndex = lastOccurrence(s, key, index + 1);
    if (restIndex != -1) return restIndex;     // If found in the rest, keep that location.
    if (s[index] == key) return index;         // If not, check current.
    return -1;                                // Not found at all.
}

// This function removes all occurrences of the given character from the string.
// It checks if current matches the character, skips it if so, otherwise keeps it and continues.
string removeChar(string s, char key, int index = 0) {
    if (index == s.size()) return "";                 // Base case: reached end, return empty string.
    if (s[index] == key) return removeChar(s, key, index + 1); // Skip this one.
    // Keep this character, add rest of result.
    return s[index] + removeChar(s, key, index + 1);
}

// This function replaces every occurrence of oldChar with newChar as it walks through the string.
// On each step, if it matches the target, puts the replacement in the result.
string replaceChar(string s, char oldChar, char newChar, int index = 0) {
    if (index == s.size()) return "";       // Reached end, nothing left.
    char c = (s[index] == oldChar) ? newChar : s[index]; // See if we should replace.
    return c + replaceChar(s, oldChar, newChar, index + 1); // Build up result recursively.
}

// This function prints all non-empty subsequences (which are just all possible groupings of characters in order).
// For each character, you have a choice: either include it, or do not.
void printSubsequences(string s, string output = "", int index = 0) {
    if (index == s.size()) {           // If we've checked every character,
        if (output != "") cout << output << endl; // print the collected answer as a subsequence (if non-empty).
        return;
    }
    printSubsequences(s, output, index + 1);                      // Exclude current character.
    printSubsequences(s, output + s[index], index + 1);           // Include current character.
}

// This is just a helper for printSubsequences, showing all subsets (subsequences).
void generateSubsets(string s, string output = "", int index = 0) {
    printSubsequences(s, output, index);
}

// This function prints all possible arrangements (permutations) of the string's letters.
// It swaps letters in place, trying all possibilities for each position.
void permute(string s, int l = 0) {
    if (l == s.size() - 1) {      // When at last letter, print the permutation.
        cout << s << endl;        // One possible arrangement.
        return;
    }
    for (int i = l; i < s.size(); i++) {       // Try each different possibility for this slot.
        swap(s[l], s[i]);                      // Swap character to current position.
        permute(s, l + 1);                     // Arrange rest.
        swap(s[l], s[i]);                      // Put back for the next loop.
    }
}

// This function checks if two strings are anagrams (made from the same letters in any order).
// It sorts both strings and checks if the sorted results match.
bool isAnagram(string s1, string s2) {
    if (s1.size() != s2.size()) return false;     // Different lengths means can't be anagrams.
    sort(s1.begin(), s1.end());                   // Sort letters in the first string.
    sort(s2.begin(), s2.end());                   // Sort letters in the second string.
    return s1 == s2;                              // They are anagrams if sorted letters are equal.
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "\n1. Print each character: ";
    printChars(s);

    cout << "\n2. Reverse string: " << reverseString(s);

    cout << "\n3. Is palindrome? " << (isPalindrome(s) ? "Yes" : "No");

    char key;
    cout << "\n\nEnter character for frequency/search/remove/replace: ";
    cin >> key;

    cout << "4. Count frequency: " << countChar(s, key);
    cout << "\n5. First occurrence: " << firstOccurrence(s, key);
    cout << "\n6. Last occurrence: " << lastOccurrence(s, key);
    cout << "\n7. String after removing character: " << removeChar(s, key);

    char newChar;
    cout << "\n8. Enter character to replace with: ";
    cin >> newChar;
    cout << "String after replacing: " << replaceChar(s, key, newChar);

    cout << "\n\n9. All subsequences:\n";
    printSubsequences(s);

    cout << "\n11. All permutations:\n";
    permute(s);

    string s2;
    cout << "\n12. Enter second string to check anagram: ";
    cin >> s2;
    cout << "Are anagrams? " << (isAnagram(s, s2) ? "Yes" : "No") << endl;

    return 0;
}


// Enter string: abc

// 1. Print each character: a b c 
// 2. Reverse string: cba
// 3. Is palindrome? No

// Enter character for frequency/search/remove/replace: b
// 4. Count frequency: 1
// 5. First occurrence: 1
// 6. Last occurrence: 1
// 7. String after removing character: ac
// 8. Enter character to replace with: x
// String after replacing: axc

// 9. All subsequences:
// c
// b
// bc
// a
// ac
// ab
// abc

// 11. All permutations:
// abc
// acb
// bac
// bca
// cab
// cba

// 12. Enter second string to check anagram: bca
// Are anagrams? Yes
