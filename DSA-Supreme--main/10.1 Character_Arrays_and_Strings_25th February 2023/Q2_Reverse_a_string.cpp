/*
    Approach Used:
    - The code reverses a character array (C-style string) in place.
    - It first calculates the length of the string manually.
    - Then, it swaps characters from the start and end, moving towards the center.
    - The reversal is done in-place, so no extra space is used.
    - The main function demonstrates the process by taking input, showing the string before and after reversal.

    Better Alternatives (without code):
    1. Use the standard library function `strlen()` to get the length of the string instead of writing a custom function.
    2. Use `std::string` instead of character arrays for safer and more flexible string handling.
    3. Use `std::reverse()` from `<algorithm>` for in-place reversal if using `std::string`.
    4. For input, use `cin.getline()` to allow spaces in the input string.
    5. Add input validation and handle edge cases (like empty string).
*/

#include<iostream>
using namespace std;

// Function to calculate the length of a C-style string (character array)
int getLength(char name[]) {
    int len = 0; // Initialize length counter
    int i = 0;   // Index for traversing the array
    // Loop until null character is found (end of string)
    while(name[i] != '\0') {
        len++;   // Increment length for each character
        i++;     // Move to next character
    }
    return len;  // Return the total length
}

// Function to reverse a C-style string in place
void reverseString(char name[]) { // array passed by reference
    int s = 0; // Start index (beginning of string)
    int e = getLength(name) - 1; // End index (last character before null terminator)
    // Loop until start index is less than end index
    while(s < e) { // Only need to swap till the middle
        swap(name[s], name[e]); // Swap characters at start and end
        s++; // Move start pointer forward
        e--; // Move end pointer backward
    }
}

int main() {
    char name[100]; // Character array to store input string (max 99 chars + null)
    // Note: cin stops reading at whitespace, so only first word is read
    cin >> name; // Take input from user
    cout << "Before reverse, name = " << name << endl; // Output original string
    reverseString(name); // Reverse the string in place
    cout << "After reverse, name = " << name; // Output reversed string
    return 0; // Indicate successful execution
}

/*
    Dry Run Example:
    Input: "hello"
    Step 1: getLength(name) returns 5
    Step 2: reverseString swaps:
        - name[0] <-> name[4] ('h' <-> 'o') => "oellh"
        - name[1] <-> name[3] ('e' <-> 'l') => "olleh"
        - name[2] is the middle, no swap needed
    Output:
        Before reverse, name = hello
        After reverse, name = olleh

    If input is "abc":
        getLength = 3
        swap name[0] <-> name[2] ('a' <-> 'c') => "cba"
        name[1] is the middle, no swap needed
        Output: cba

    Note: If input contains spaces (e.g., "hello world"), only "hello" is read.
*/

/*
    Alternative Approaches (detailed, no code):
    - Use `cin.getline(name, 100)` to read full line including spaces.
    - Use `strlen(name)` from <cstring> to get string length.
    - Use `std::string` and `std::reverse(str.begin(), str.end())` for modern C++.
    - For Unicode or multibyte characters, use appropriate libraries or data structures.
    - Add error handling for buffer overflow or invalid input.
*/