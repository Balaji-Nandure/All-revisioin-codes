/*
Approach:
- The goal is to print an alphabet palindrome pattern for a given number of rows n.
- For each row i (from 0 to n-1):
    - Print increasing alphabets from 'A' up to the (i+1)th alphabet.
    - Then, print decreasing alphabets back to 'A', skipping the last printed character to avoid repetition.
    - Each row forms a palindrome of alphabets.
- Each row ends with a newline.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here
    int n = 6; // Initialize the number of rows for the pattern

    // Loop for each row from 0 to n-1
    for(int i = 0; i < n; i++){ // i represents the current row number
        char ch = 'A'; // Start from alphabet 'A' for each row

        // Print increasing sequence of alphabets
        for(int j = 0; j < i + 1; j++){ // Loop to print (i+1) alphabets
            cout << ch; // Print the current alphabet
            ch = ch + 1; // Move to the next alphabet
        }

        ch = ch - 2; // Move back to the previous alphabet (since ch is now one past the last printed)

        // Print decreasing sequence of alphabets (only if not the first row)
        if(i != 0){ // No reverse for the first row
            for(; ch >= 'A'; ch--){ // Loop to print alphabets in reverse order
                cout << ch; // Print the current alphabet
            }
        }

        cout << endl; // Move to the next line after each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 4):

Row 0 (i=0):
    ch = 'A'
    Print: A
    Output: A

Row 1 (i=1):
    ch = 'A'
    Print: A
    ch = 'B'
    Print: B
    ch = 'C' (after loop)
    ch = 'B' (ch = ch-2)
    Print: A (for ch='B', ch--)
    Output: ABA

Row 2 (i=2):
    ch = 'A'
    Print: A
    ch = 'B'
    Print: B
    ch = 'C'
    Print: C
    ch = 'D' (after loop)
    ch = 'B' (ch = ch-2)
    Print: B, A (for ch='B', ch--)
    Output: ABCBA

Row 3 (i=3):
    ch = 'A'
    Print: A
    ch = 'B'
    Print: B
    ch = 'C'
    Print: C
    ch = 'D'
    Print: D
    ch = 'E' (after loop)
    ch = 'C' (ch = ch-2)
    Print: C, B, A (for ch='C', ch--)
    Output: ABCDCBA

Final Output for n=4:
A
ABA
ABCBA
ABCDCBA
*/