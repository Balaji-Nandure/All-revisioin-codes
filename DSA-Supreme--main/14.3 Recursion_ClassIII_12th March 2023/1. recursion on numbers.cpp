#include <iostream> // include input/output stream library for cin/cout, required for console IO
using namespace std; // use standard namespace, so we don't need std:: prefix everywhere

// 1. Print numbers from 1 to N in increasing order using recursion
void print1toN(int n) {
    // Base case: if n is 0, stop recursion; we've reached before 1
    if (n == 0) return; // stopping point, prevents negative numbers and infinite loop
    print1toN(n - 1);   // recursive call with decreased n, prints smaller numbers first
    cout << n << " ";   // print current n after the recursive call, ensuring increasing order
}

// 2. Print numbers from N to 1 in decreasing order using recursion
void printNto1(int n) {
    // Base case: if n is 0, no more numbers to print
    if (n == 0) return;     // stop recursion when n reaches 0
    cout << n << " ";       // print current n before recursive call, gives decreasing order
    printNto1(n - 1);       // recursive call with n decremented by 1
}

// 3. Sum of first N natural numbers recursively
int sumN(int n) {
    // Base case: sum of 0 numbers is 0
    if (n == 0) return 0;           // stopping condition, handles empty sum
    return n + sumN(n - 1);         // add n to sum of previous numbers, classic recursion case
}

// 4. Factorial of N using recursion
int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) return 1; // handles smallest cases to prevent further recursion
    return n * factorial(n - 1);    // multiply n with factorial of previous number (n-1)
}

// 5. Fibonacci number at Nth position (recursive approach, exponential time)
int fibonacci(int n) {
    // Base case: fib(0) = 0, fib(1) = 1
    if (n == 0) return 0;           // first number of Fibonacci sequence is 0
    if (n == 1) return 1;           // second number of Fibonacci sequence is 1
    // Recursive case: sum of previous two Fibonacci numbers
    return fibonacci(n - 1) + fibonacci(n - 2); // main property of Fibonacci numbers used here
}

// 6. Helper function to check divisors recursively for primality
bool isPrimeHelper(int n, int divisor) {
    // Base case: reached divisor 1 means no divisor found, n is prime
    if (divisor == 1) return true;      // all checks done, number is prime
    // If n is divisible by current divisor, not prime
    if (n % divisor == 0) return false; // found divisor other than 1 and n, so not prime
    // Check next smaller divisor recursively
    return isPrimeHelper(n, divisor - 1); // recursive check for next possible divisor
}

// Main function to check if a number is prime
bool isPrime(int n) {
    // Handle invalid and trivial cases: numbers <= 1 are not prime
    if (n <= 1) return false;          // negative, 0 or 1 are not prime by definition
    // Start checking divisors from n/2 downward (as no factor above n/2 except n itself)
    return isPrimeHelper(n, n / 2);    // check all numbers from n/2 down to 1 for divisor
}

// 7. Count number of digits in n recursively
int countDigits(int n) {
    if (n < 0) n = -n;                    // convert negative number to positive, digits are positive
    // Base case: n == 0 means no more digits left
    if (n == 0) return 0;                 // return 0 for the completed process, no more digits
    // Recursive case: divide by 10 to remove last digit, count +1 for each recursion
    return 1 + countDigits(n / 10);       // count current digit, recurse for rest
}

// 8. Sum all digits of an integer recursively
int sumDigits(int n) {
    if (n < 0) n = -n;                        // handle negative input, only magnitudes matter for digit sum
    // Base case: when n reaches 0, no more digits to process
    if (n == 0) return 0;                     // sum is zero if there are no more digits
    // Recursive case: add last digit to sum of remaining digits
    return (n % 10) + sumDigits(n / 10);      // add last digit, recur for the remaining digits
}

// 9. Helper for reversing the digits of a number recursively
int reverseNumberHelper(int n, int rev) {
    // Base case: when n is 0, all digits processed, rev holds the result
    if (n == 0) return rev;               // reversed number fully constructed, return it
    // Add last digit to rev (shifted one place left), recurse with the rest
    return reverseNumberHelper(n / 10, rev * 10 + (n % 10)); // process next digit
}

// Public interface to reverse a number, supports negative numbers
int reverseNumber(int n) {
    bool neg = n < 0;                         // check if number is negative to restore sign at end
    if (neg) n = -n;                          // use absolute for reversal logic
    int res = reverseNumberHelper(n, 0);      // call helper with accumulator starting at 0
    return neg ? -res : res;                  // restore negative sign if input was negative
}

// 10. Check if number is palindrome by comparing to its reverse
bool isPalindrome(int n) {
    return n == reverseNumber(n);         // a number is palindrome if equal to its reversal
}

// 11. Find greatest common divisor (gcd) using Euclid's algorithm (recursive)
int gcd(int a, int b) {
    if (b == 0) return a;                     // base case: if b is zero, a is the gcd
    return gcd(b, a % b);                     // otherwise, recur with remainder of a/b as next b
}

// 12. Calculate 'a' to the power 'b' recursively
int power(int a, int b) {
    if (b == 0) return 1;                     // base case: any number to power 0 is 1
    return a * power(a, b - 1);               // multiply a recursively for b times
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "\n1. Print 1 to N: ";
    print1toN(n);
    cout << "\n2. Print N to 1: ";
    printNto1(n);

    cout << "\n3. Sum of first N numbers = " << sumN(n);
    cout << "\n4. Factorial of N = " << factorial(n);
    cout << "\n5. Fibonacci(" << n << ") = " << fibonacci(n);

    cout << "\n6. Is Prime? " << (isPrime(n) ? "Yes" : "No");

    cout << "\n7. Count digits = " << countDigits(n);
    cout << "\n8. Sum of digits = " << sumDigits(n);

    cout << "\n9. Reverse number = " << reverseNumber(n);
    cout << "\n10. Is Palindrome? " << (isPalindrome(n) ? "Yes" : "No");

    int a, b;
    cout << "\n\nEnter two numbers for GCD: ";
    cin >> a >> b;
    cout << "11. GCD = " << gcd(a, b);

    int base, exp;
    cout << "\n\nEnter base and exponent: ";
    cin >> base >> exp;
    cout << "12. Power = " << power(base, exp);

    cout << endl;
    return 0;
}


// Output:
// Enter a number: 5

// 1. Print 1 to N: 1 2 3 4 5
// 2. Print N to 1: 5 4 3 2 1
// 3. Sum of first N numbers = 15
// 4. Factorial of N = 120
// 5. Fibonacci(5) = 5
// 6. Is Prime? No
// 7. Count digits = 1
// 8. Sum of digits = 5
// 9. Reverse number = 5
// 10. Is Palindrome? Yes

// Enter two numbers for GCD: 36 48
// 11. GCD = 12

// Enter base and exponent: 2 5
// 12. Power = 32
