/*
Approach Used:
---------------
- The code takes a character array (C-style string) and converts all lowercase letters to uppercase in-place.
- It iterates through each character, checks if it is a lowercase letter, and if so, converts it to uppercase using ASCII manipulation.

Better Alternatives (without code):
-----------------------------------
1. Use C++ STL's `std::transform` with `toupper` for more readable and safer code.
2. Use `std::string` instead of C-style arrays for better safety and flexibility.
3. Use locale-aware functions for internationalization (e.g., `std::toupper` with locale).
4. For large strings, consider parallelization if performance is critical.

*/

#include<iostream>
#include<string.h> // For strlen
using namespace std;

// Function to convert all lowercase characters in a char array to uppercase
void convertStringToUpper(char name[]){
    int n = strlen(name); // Get the length of the string
    for(int i = 0; i < n; i++){ // Loop through each character
        // Check if the character is a lowercase letter
        if(name[i] >= 'a' && name[i] <= 'z')
            name[i] = name[i] - 'a' + 'A'; // Convert to uppercase using ASCII value difference
            // 'a' - 'A' = 32, so this shifts the character to its uppercase equivalent
    }
}

int main(){
    char name[100] = "bhavya"; // Initialize character array with a lowercase string

    convertStringToUpper(name); // Call function to convert to uppercase

    cout << name << endl; // Output the converted string

    return 0; // Indicate successful program termination
}

/*
Dry Run:
--------
Input: name = "bhavya"
Step-by-step:
- n = 6 (length of "bhavya")
- i = 0: name[0] = 'b' -> is lowercase -> convert to 'B'
- i = 1: name[1] = 'h' -> is lowercase -> convert to 'H'
- i = 2: name[2] = 'a' -> is lowercase -> convert to 'A'
- i = 3: name[3] = 'v' -> is lowercase -> convert to 'V'
- i = 4: name[4] = 'y' -> is lowercase -> convert to 'Y'
- i = 5: name[5] = 'a' -> is lowercase -> convert to 'A'
- Final string: "BHAVYA"
Output: BHAVYA

*/