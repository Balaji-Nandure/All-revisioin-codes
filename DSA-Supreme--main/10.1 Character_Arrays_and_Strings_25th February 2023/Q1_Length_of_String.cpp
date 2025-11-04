/*
    Approach:
    1. Read a string from user input using character array.
    2. Implement a custom function to calculate the length of the string (without using built-in functions).
    3. Print the calculated length.
    4. Also, print the length using the built-in strlen() function for comparison.

    Alternatives:
    - Use std::string instead of char array for safer and more flexible string handling.
    - Use built-in functions like strlen() directly for length calculation.
    - For large inputs or dynamic size, prefer std::string to avoid buffer overflow.
    - For Unicode or wide characters, use wchar_t or std::wstring.

    Betterment:
    - Added input prompt and output formatting.
    - Added input validation.
    - Added comments for all important lines.
    - Used const correctness in getLength.
    - Used safer input (cin.getline) to allow spaces in input.
    - Provided dry run at the end.
*/

#include <iostream>
#include <cstring> // for strlen
using namespace std;

// Function to calculate length of a C-style string
int getLength(const char name[]) {
    int len = 0; // Initialize length counter
    int i = 0;   // Index for traversing the array
    // Loop until null character is encountered
    while (name[i] != '\0') {
        len++;   // Increment length for each character
        i++;     // Move to next character
    }
    return len;  // Return the calculated length
}

int main() {
    char name[100]; // Character array to store input string (max 99 chars + null)
    cout << "Enter a string (max 99 characters): "; // Prompt user for input

    // Use cin.getline to read input with spaces, up to 99 characters
    cin.getline(name, 100);

    // Check if input is empty
    if (name[0] == '\0') {
        cout << "Input string is empty." << endl;
        return 0;
    }

    // Call custom function to get length
    int length = getLength(name);

    // Output the length calculated by custom function
    cout << "Length of string (custom function) = " << length << endl;

    // Output the length using built-in strlen function
    cout << "Length of string (strlen) = " << strlen(name) << endl;

    return 0;
}

/*
    Dry Run Example:
    Input: "hello world"
    Step 1: name = "hello world"
    Step 2: getLength(name)
        i=0, name[0]='h' -> len=1
        i=1, name[1]='e' -> len=2
        i=2, name[2]='l' -> len=3
        i=3, name[3]='l' -> len=4
        i=4, name[4]='o' -> len=5
        i=5, name[5]=' ' -> len=6
        i=6, name[6]='w' -> len=7
        i=7, name[7]='o' -> len=8
        i=8, name[8]='r' -> len=9
        i=9, name[9]='l' -> len=10
        i=10, name[10]='d' -> len=11
        i=11, name[11]='\0' -> stop
    Output:
        Length of string (custom function) = 11
        Length of string (strlen) = 11
*/

/*
    Detailed Alternative Approaches (without code):
    1. Using std::string:
        - Use std::string for input and use .length() or .size() method.
        - Handles dynamic size and is safer for most use cases.
    2. Using pointers:
        - Traverse the string using a pointer until null character is found.
    3. Using recursion:
        - Implement a recursive function to count characters until '\0'.
    4. For Unicode:
        - Use wchar_t or std::wstring and wcin/wcout for wide characters.
*/