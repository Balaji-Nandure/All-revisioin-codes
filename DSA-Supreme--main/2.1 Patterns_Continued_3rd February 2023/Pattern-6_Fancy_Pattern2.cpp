#include<iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace

/*
Approach:
- The pattern is divided into two halves: upper and lower.
- The upper half prints increasing numbers with '*' in between, for each row.
- The lower half prints decreasing numbers with '*' in between, for each row.
- For both halves, the last number in each row does not have a '*' after it.
*/

int main(){
    int n = 4; // Initialize the number of rows for the pattern

    // Upper half of the pattern
    for(int i = 0; i < n; i++){ // Loop for each row from 0 to n-1
        for(int j = 0; j < i + 1; j++){ // Loop to print numbers and stars in each row
            cout << i + 1; // Print the number (i+1) for the current row
            if(j != i){ // If not the last number in the row
                cout << "*"; // Print '*' after the number
            }
        }
        cout << endl; // Move to the next line after each row
    }

    // Lower half of the pattern
    for(int i = 0; i < n; i++){ // Loop for each row from 0 to n-1
        for(int j = 0; j < n - i; j++){ // Loop to print numbers and stars in each row
            cout << n - i; // Print the number (n-i) for the current row
            if(j != n - i - 1){ // If not the last number in the row
                cout << "*"; // Print '*' after the number
            }
        }
        cout << endl; // Move to the next line after each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run:

n = 4

Upper half:
i=0: j=0 -> print 1 (no star, as j==i)         => 1
i=1: j=0 -> print 2*, j=1 -> print 2           => 2*2
i=2: j=0 -> print 3*, j=1 -> print 3*, j=2->3  => 3*3*3
i=3: j=0 -> print 4*, j=1 -> print 4*, j=2->4*, j=3->4 => 4*4*4*4

Lower half:
i=0: j=0 -> print 4*, j=1->4*, j=2->4*, j=3->4 => 4*4*4*4
i=1: j=0 -> print 3*, j=1->3*, j=2->3          => 3*3*3
i=2: j=0 -> print 2*, j=1->2                   => 2*2
i=3: j=0 -> print 1                            => 1

Final Output:
1
2*2
3*3*3
4*4*4*4
4*4*4*4
3*3*3
2*2
1
*/