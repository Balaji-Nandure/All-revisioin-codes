#include<iostream> // Include the input-output stream library for using cout, cin, etc.
using namespace std; // Use the standard namespace to avoid prefixing std::

// Approach:
// The code demonstrates initialization of a character array (C-style string).
// It tries to store the string "love" in a char array of size 4.
// However, C-style strings require an extra space for the null terminator '\0' at the end.
// So, the array should be of size 5 to store "love" + '\0'.
// The code as given will cause a warning or undefined behavior because the null terminator cannot be stored.

int main(){
    // char name[4] = "love"; // Incorrect: size 4 is not enough for "love" + '\0'
    
    // Correct way: Allocate one extra space for the null terminator
    char name[5] = "love"; // "love" + '\0' (null terminator)
    
    // Output the string to verify correct storage and null termination
    cout << "The name is: " << name << endl; // Prints: The name is: love

    // Alternative approaches (without code):
    // 1. Let the compiler decide the size automatically:
    //      char name[] = "love";
    //    This will automatically allocate 5 bytes (4 for characters + 1 for '\0').
    //
    // 2. Use std::string for safer and more flexible string handling:
    //      string name = "love";
    //    This avoids manual memory management and is recommended in C++.
    //
    // 3. If you want to read input from user:
    //      char name[100];
    //      cin >> name; // Reads a word (not spaces)
    //    Or, for full line:
    //      cin.getline(name, 100);

    return 0; // Indicate successful program termination
}

/*
Dry Run:
----------
Step 1: char name[5] = "love";
        // name[0] = 'l'
        // name[1] = 'o'
        // name[2] = 'v'
        // name[3] = 'e'
        // name[4] = '\0' (null terminator automatically added)
Step 2: cout << "The name is: " << name << endl;
        // Output: The name is: love
Step 3: return 0;
        // Program ends successfully

Key Point:
- Always allocate one extra space for the null terminator when using C-style strings.
- Prefer std::string in modern C++ for better safety and convenience.
*/