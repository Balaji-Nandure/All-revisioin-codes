/*
Approach:
The code prints the Butterfly Pattern for a given number of rows (n = 5).
The pattern is divided into two halves:
1. The upper half: For each row, print increasing stars, then spaces, then increasing stars again.
2. The lower half: For each row, print decreasing stars, then spaces, then decreasing stars again.

Each line is commented for clarity.
A dry run is provided at the end.
*/

#include<iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function starts
    int n = 5; // Number of rows for the butterfly pattern

    // Upper half of the butterfly
    for(int i = 0; i < n; i++){ // Loop for each row in the upper half
        // Pattern - 1: Print stars on the left side
        for(int j = 0; j < i + 1; j++){ // Loop to print (i+1) stars
            cout << "* "; // Print star and space
        }
        // Space - 1: Print spaces in the middle
        int space = 2 * (n - i - 1); // Calculate number of spaces
        for(; space > 0; space--){ // Loop to print spaces
            cout << "  "; // Print two spaces
        }
        // Pattern - 2: Print stars on the right side
        for(int j = 0; j < i + 1; j++){ // Loop to print (i+1) stars
            cout << "* "; // Print star and space
        }
        cout << endl; // Move to next line after each row
    }

    // Lower half of the butterfly
    for(int i = 0; i < n; i++){ // Loop for each row in the lower half
        // Pattern - 3: Print stars on the left side
        for(int j = 0; j < n - i; j++){ // Loop to print (n-i) stars
            cout << "* "; // Print star and space
        }
        // Space - 2: Print spaces in the middle
        int space = 2 * i; // Calculate number of spaces
        for(; space > 0; space--){ // Loop to print spaces
            cout << "  "; // Print two spaces
        }
        // Pattern - 4: Print stars on the right side
        for(int j = 0; j < n - i; j++){ // Loop to print (n-i) stars
            cout << "* "; // Print star and space
        }
        cout << endl; // Move to next line after each row
    }
    return 0; // Indicate successful program termination
}

/*
Dry Run (for n = 5):

Upper Half:
i=0: *                 * 
i=1: * *             * * 
i=2: * * *         * * * 
i=3: * * * *     * * * * 
i=4: * * * * * * * * * * 

Lower Half:
i=0: * * * * * * * * * * 
i=1: * * * *     * * * * 
i=2: * * *         * * * 
i=3: * *             * * 
i=4: *                 * 

Pattern forms a butterfly shape.
*/