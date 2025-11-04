/*
Approach Used:
---------------
- This code demonstrates how to read and store a full name (with spaces) in a character array in C++.
- It first shows the limitation of using 'cin' for character arrays (it stops reading at whitespace).
- Then, it uses 'cin.getline()' to read the entire line including spaces.

Better Alternatives (without code):
-----------------------------------
1. Use 'cin.getline()' directly to read the full name, skipping the initial 'cin' which only reads up to the first space.
2. Use 'std::string' and 'getline(cin, str)' for more flexibility, dynamic sizing, and safety.
3. For robust input, clear the input buffer before using 'getline' if mixing 'cin' and 'getline'.
4. For Unicode or wide characters, use 'wchar_t' and related functions.

Improved Code with Detailed Comments:
-------------------------------------
*/

#include<iostream>
using namespace std;

int main(){
    // Declare a character array of size 100 to store the full name
    char ch[100];

    // Prompt the user to enter their full name
    cout << "Enter full name: ";

    // Use cin.getline to read the entire line including spaces into the character array
    // Syntax: cin.getline(array_name, size)
    // This reads up to (size-1) characters or until a newline is encountered
    cin.getline(ch, 100);

    // Output the full name entered by the user
    cout << "Full name = " << ch << endl;

    /*
    // Alternative: Using std::string for safer and more flexible input
    // string fullName;
    // cout << "Enter full name: ";
    // getline(cin, fullName);
    // cout << "Full name = " << fullName << endl;
    */

    return 0;
}

/*
Dry Run:
--------
Input:  John Doe

Step 1: Program prompts "Enter full name: "
Step 2: User types "John Doe" and presses Enter
Step 3: cin.getline(ch, 100) reads "John Doe" (including the space) into ch
Step 4: Program outputs "Full name = John Doe"

Key Points:
- Using cin.getline allows reading input with spaces.
- Using std::string and getline is even better for dynamic input size and safety.
*/