/*
Approach:
- Read an integer `bro_num` and decide output using a simple if-else.
- If there are zero brothers, print a positive message; otherwise, print the negative case.
*/

#include<iostream> // Include standard I/O
using namespace std; // Use the standard namespace

int main(){ // Program entry
    int bro_num; // Number of brothers
    cout << "enter the number of brothers "; // Prompt
    cin >> bro_num; // Read input
    if(bro_num == 0){ // Check if zero
        cout << "Baat ban jayegi" << endl; // Positive case
    }
    else{ // Non-zero case
        cout << "Baat nhi banegi " << endl; // Negative case
    }
    return 0; // Successful execution
}

/*
Dry Run:
Input: 0  -> prints "Baat ban jayegi"
Input: 2  -> prints "Baat nhi banegi "
*/