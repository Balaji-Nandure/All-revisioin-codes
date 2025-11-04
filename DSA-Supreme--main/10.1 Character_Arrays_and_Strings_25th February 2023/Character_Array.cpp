/*
Approach Used:
---------------
This code demonstrates two ways to take character input in C++ using character arrays:
1. Taking a string input (without spaces) using cin and storing it in a character array.
2. Taking a single character input and storing it in a character array.

Better Alternatives (without code):
-----------------------------------
- For reading full lines (including spaces), use cin.getline() or getline() with string class.
- Prefer using std::string for string manipulations as it is safer and more flexible than character arrays.
- Always check for buffer overflows and input size when using character arrays.
- For single character input, you can use cin.get() for more control (e.g., to read whitespace).

*/

// Include the input-output stream library for cin and cout
#include<iostream>
using namespace std;

int main(){
    // First way: Taking a string input (without spaces) using character array
    char name[100]; // Declare a character array of size 100 to store the name

    cout << "Enter your name: "; // Prompt user for input

    cin >> name; // Reads input until whitespace (space, tab, newline) is encountered

    cout << "Your name is: " << name << endl; // Output the entered name

    // Second way: Taking a single character input
    char ch1[2]; // Declare a character array of size 2 (1 for character, 1 for null terminator)

    cout << "Enter a single character: "; // Prompt user for input

    cin >> ch1[0]; // Reads a single character (skips whitespace)

    ch1[1] = '\0'; // Null-terminate the character array to safely print as string

    cout << "Character entered = " << ch1 << endl; // Output the entered character

    /*
    Better Alternatives (detailed):
    -------------------------------
    - To read a full line (including spaces), use: cin.getline(name, 100);
    - To use dynamic and safer strings, use: string name; getline(cin, name);
    - For single character input, use: char c; cin >> c; or cin.get(c);
    - Always validate input size to avoid buffer overflow.
    */

    return 0;
}

/*
Dry Run:
--------
Suppose user input is:
Enter your name: John Doe
Your name is: John

Enter a single character: A
Character entered = A

Explanation:
- For the name, only "John" is stored because cin stops at the first space.
- For the character, 'A' is stored and printed.
*/