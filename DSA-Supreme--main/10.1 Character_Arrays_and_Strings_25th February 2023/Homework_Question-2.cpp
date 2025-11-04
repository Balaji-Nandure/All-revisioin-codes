/*
    Approach:
    1. Find the length of the input character array (C-style string).
    2. Traverse each character and check if it is an uppercase letter.
    3. If it is uppercase, convert it to lowercase by adjusting its ASCII value.
    4. Print the modified string.

    // Better alternatives (without code):
    - Use built-in functions like strlen() for length and tolower() for conversion (from <cstring> and <cctype>).
    - Use std::string instead of char array for safer and more flexible string handling.
    - Handle edge cases: empty string, non-alphabetic characters, already lowercase, etc.
    - For Unicode or non-ASCII, use libraries like ICU or std::wstring for wide characters.
*/

// Convert the string to lowercase string

#include<iostream>
using namespace std;

// Function to calculate the length of a C-style string
int getLength(char name[]){
    int len = 0; // Initialize length counter
    int i = 0;   // Index for traversing the array
    // Loop until null character is found
    while(name[i] != '\0'){
        len++;   // Increment length for each character
        i++;     // Move to next character
    }
    return len;  // Return the total length
}

// Function to convert all uppercase letters in the string to lowercase
void convertToLowerCaseString(char name[]){
    int n = getLength(name); // Get the length of the string
    for(int i = 0; i < n; i++){
        // Check if the character is an uppercase letter (A-Z)
        if(name[i] >= 'A' && name[i] <= 'Z'){
            // Convert to lowercase by adding the difference between 'a' and 'A'
            name[i] = name[i] - 'A' + 'a';
        }
        // If not uppercase, leave the character as is
    }
}

int main(){
    char name[7] = "BHAVYA"; // Input string (C-style char array)
    convertToLowerCaseString(name); // Convert to lowercase
    cout << name; // Output the modified string
    return 0;
}

/*
    Dry Run:
    Input: name = "BHAVYA"
    Step 1: getLength(name) returns 6
    Step 2: Loop through each character:
        i=0: 'B' -> 'b'
        i=1: 'H' -> 'h'
        i=2: 'A' -> 'a'
        i=3: 'V' -> 'v'
        i=4: 'Y' -> 'y'
        i=5: 'A' -> 'a'
    Output: "bhavya"

    // Note: If you use std::string and std::transform with ::tolower, code becomes more concise and robust.
    // For large or dynamic strings, prefer std::string over char arrays.
*/