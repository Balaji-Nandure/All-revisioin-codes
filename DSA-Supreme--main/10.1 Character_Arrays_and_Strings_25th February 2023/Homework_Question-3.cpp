#include<iostream>
#include<string>
using namespace std;

/*
Approach:
- Demonstrate different variants of the std::string::replace function in C++.
- Each variant shows a different way to replace part of a string with another string or character(s).
- The code resets the string before each replace to show the effect of each variant independently.

Better Alternatives (in comments):
- For simple replacements, consider using std::replace (for single characters) or std::regex_replace (for pattern-based replacements).
- For multiple replacements or more complex logic, consider writing a utility function or using algorithms from <algorithm>.
- For performance-critical code, avoid repeated string copying by modifying in-place or using string views (C++17+).

*/

int main(){
    // 1st variant: Replace a substring with multiple copies of a character
    string str = "This is a short phrase";
    // str.replace(pos, len, n, ch): replaces 'len' characters at position 'pos' with 'n' copies of character 'ch'
    // Here, tries to replace 1 character at index 22 with 3 '!' characters.
    // Note: Index 22 is out of bounds for this string (length 22, last index 21), so nothing happens.
    str.replace(22, 1, 3, '!'); 
    cout << str << endl; // Output: "This is a short phrase"

    // 2nd variant: Replace a substring with a part of another string
    str = "This is a short phrase";
    // str.replace(pos, len, s, n): replaces 'len' characters at 'pos' with first 'n' characters of string 's'
    // Replaces 6 characters at index 8 ("a shor") with first 7 characters of "a shorty" ("a short")
    str.replace(8, 6, "a shorty", 7); 
    cout << str << endl; // Output: "This is a short phrase" -> "This is a short phrase" (no visible change, as replaced with same text)

    // 3rd variant: Replace a substring with a full string
    str = "This is a short phrase";
    // str.replace(pos, len, s): replaces 'len' characters at 'pos' with the entire string 's'
    // Replaces 6 characters at index 8 ("a shor") with "a shorty"
    str.replace(8, 6, "a shorty"); 
    cout << str << endl; // Output: "This is a shortty phrase"

    // 4th variant: Replace a substring with a substring of another string
    str = "This is a short phrase";
    // str.replace(pos, len, s, s_pos, s_len): replaces 'len' characters at 'pos' with 's_len' characters from 's' starting at 's_pos'
    // Replaces 6 characters at index 19 with 6 characters from "a shorty" starting at index 7 ("y")
    str.replace(19, 6, "a shorty", 7, 6); 
    cout << str << endl; // Output: "This is a short phry"

    return 0;
}

/*
Dry Run:
1. str = "This is a short phrase"
   str.replace(22, 1, 3, '!') -> No change (index out of bounds)
   Output: "This is a short phrase"

2. str = "This is a short phrase"
   str.replace(8, 6, "a shorty", 7)
   - Replaces "a shor" (positions 8-13) with "a short"
   Output: "This is a short phrase" (no visible change)

3. str = "This is a short phrase"
   str.replace(8, 6, "a shorty")
   - Replaces "a shor" (positions 8-13) with "a shorty"
   Output: "This is a shortty phrase"

4. str = "This is a short phrase"
   str.replace(19, 6, "a shorty", 7, 6)
   - Replaces "hrase" (positions 19-24) with "y" (from "a shorty", index 7, length 6, but only 1 char available)
   Output: "This is a short phry"

Note:
- Always check bounds when using replace to avoid undefined behavior.
- For more robust replacements, consider using string::find to locate substrings before replacing.
*/