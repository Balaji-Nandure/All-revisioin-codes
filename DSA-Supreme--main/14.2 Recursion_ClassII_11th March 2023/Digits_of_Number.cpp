#include <iostream> // includes the iostream header file // necessary for input and output
using namespace std; // uses the standard namespace // avoids prefixing std::

// Recursive function to print digits of a number
void printDigits(int n) { // function to print individual digits // takes integer n
    // Handle negative numbers
    if (n < 0) { // checks if n is negative // for sign handling
        cout << "- "; // prints negative sign // separates sign from digits
        n = -n; // make it positive // ensures recursion on positive value
    }

    // Base case: if n has only one digit
    if (n < 10) { // true if only one digit remains // base case for recursion
        cout << n << " "; // output the single digit // space for separation
        return; // end recursion here // no further digits
    }

    // Recursive step: print all digits except last
    printDigits(n / 10); // recursive call on all digits except last // integer division removes last digit

    // Print last digit
    cout << n % 10 << " "; // outputs current last digit // modulus gets last digit
}

int main() { // execution starts here // main entry point
    int n; // integer to store input number // will be read from user

    cout << "Enter number: "; // ask user for input // prompts on console
    cin >> n; // read integer value from user // store in n

    cout << "Digits: "; // display description before printing digits // label output
    printDigits(n); // call function to print digits recursively // process input number

    cout << endl; // print newline for output formatting // end the line

    return 0; // signals successful program execution // end of main
}
