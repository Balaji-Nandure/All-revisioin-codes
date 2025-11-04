#include <iostream>
using namespace std;

// Function 1: Check if key is present
bool isPresent(string s, int index, char key) {
    if (index == s.size()) return false;       // reached end
    if (s[index] == key) return true;          // found key
    return isPresent(s, index + 1, key);       // check rest
}

// Function 2: Find index of first occurrence
int firstOccurrence(string s, int index, char key) {
    if (index == s.size()) return -1;          // key not found
    if (s[index] == key) return index;         // found at current index
    return firstOccurrence(s, index + 1, key); // check rest
}

// Function 3: Find index of last occurrence
int lastOccurrence(string s, int index, char key) {
    if (index == s.size()) return -1; // reached end of string
    
    // recursive call first → check rest of string
    int restIndex = lastOccurrence(s, index + 1, key);
    
    if (restIndex != -1) return restIndex; // if found in rest, return it
    if (s[index] == key) return index;     // else check current index
    
    return -1; // not found
}

int main() {
    string s;
    char key;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter character to search: ";
    cin >> key;

    // Check presence
    if (isPresent(s, 0, key))
        cout << "Key is present in string" << endl;
    else
        cout << "Key is NOT present in string" << endl;

    // First occurrence
    int first = firstOccurrence(s, 0, key);
    if (first != -1)
        cout << "First occurrence at index: " << first << endl;
    else
        cout << "Character not found in string" << endl;

    // Last occurrence
    int last = lastOccurrence(s, 0, key);
    if (last != -1)
        cout << "Last occurrence at index: " << last << endl;
    else
        cout << "Character not found in string" << endl;

    return 0;
}
