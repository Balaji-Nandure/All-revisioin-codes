/*
Approach Used:
---------------
- The code reads a string from the user, then replaces every space character (' ') in the string with '@'.
- It uses a simple in-place traversal of the character array to perform the replacement.

Better Alternatives (without code):
-----------------------------------
1. Use C++ STL string and its replace/transform functions for more flexibility and safety.
2. If the replacement string is longer than one character (e.g., replacing " " with "%20"), process from the end to avoid overwriting.
3. For very large strings, consider using string streams or building a new string for efficiency.
4. Use regular expressions (std::regex) for more complex replacements.

Code with detailed comments and improvements:
--------------------------------------------
*/

#include <iostream>
#include <cstring> // For strlen
using namespace std;

// Function to replace all spaces in the character array with '@'
void replaceSpaces(char name[], int len) {
    // Traverse each character in the array
    for (int i = 0; i < len; i++) {
        // If the current character is a space
        if (name[i] == ' ') {
            name[i] = '@'; // Replace space with '@'
        }
    }
}

int main() {
    char name[100]; // Declare a character array to store input (max 99 chars + null terminator)

    // Read a line of input from the user (including spaces)
    cin.getline(name, 100);

    // Calculate the length of the input string
    int len = strlen(name);

    // Call the function to replace spaces with '@'
    replaceSpaces(name, len);

    // Output the modified string
    cout << name << endl;

    return 0; // Indicate successful program termination
}

/*
Dry Run Example:
----------------
Input:  "Hello World Program"
Step 1: Read input into name[]: ['H','e','l','l','o',' ','W','o','r','l','d',' ','P','r','o','g','r','a','m','\0']
Step 2: len = 19
Step 3: Traverse name[]:
    - At index 5: ' ' -> replaced with '@'
    - At index 11: ' ' -> replaced with '@'
Step 4: name[] becomes: ['H','e','l','l','o','@','W','o','r','l','d','@','P','r','o','g','r','a','m','\0']
Step 5: Output: "Hello@World@Program"

Note:
-----
- This approach works only for single character replacement and fixed-size arrays.
- For more complex replacements (e.g., replacing " " with "%20"), a different approach is needed.
- Using std::string is safer and more flexible in modern C++.
*/