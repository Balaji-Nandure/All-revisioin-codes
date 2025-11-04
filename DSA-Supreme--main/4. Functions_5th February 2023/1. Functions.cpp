#include<iostream> // including input-output stream library for cout and endl
using namespace std; // using standard namespace to avoid std:: prefix

// Approach:
// We want to print the name "Bhavya" 5 times using a function. 
// We'll define a function 'printName' that contains a loop to print the name, 
// and call this function from main.

// Function to print name 5 times
void printName(){ // defining a function to print name
    // function body
    for(int i = 0; i < 5; i++){ // loop runs 5 times (from 0 to 4)
        cout << "Bhavya " << endl; // prints "Bhavya" followed by a newline
    }
}

int main(){
    printName(); // function call to printName, which prints "Bhavya" 5 times
    return 0; // indicates successful program termination
}

/*
Dry Run:
-------------
Step 1: main() starts.
Step 2: printName() is called.
Step 3: Inside printName(), for loop starts with i = 0.
    - i = 0: prints "Bhavya"
    - i = 1: prints "Bhavya"
    - i = 2: prints "Bhavya"
    - i = 3: prints "Bhavya"
    - i = 4: prints "Bhavya"
Step 4: Loop ends after i = 4.
Step 5: printName() ends, returns to main().
Step 6: main() returns 0, program ends.

Output:
Bhavya 
Bhavya 
Bhavya 
Bhavya 
Bhavya 
*/