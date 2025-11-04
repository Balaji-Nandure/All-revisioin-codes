#include<iostream>
using namespace std;

/*
    Approach Used:
    ----------------
    This code implements the Euclidean Algorithm to find the Greatest Common Divisor (GCD) or Highest Common Factor (HCF) of two numbers.
    The approach is based on the principle that the GCD of two numbers also divides their difference.
    The code also calculates the Least Common Multiple (LCM) using the relation: LCM(a, b) = (a * b) / GCD(a, b)

    Better Alternative:
    -------------------
    - The subtraction-based Euclidean algorithm (as used here) is less efficient than the modulo-based version.
    - The modulo-based approach replaces repeated subtraction with a single modulo operation, which is much faster, especially for large numbers.
    - Recursive implementation is also possible and often more concise.
    - For very large numbers, built-in functions or optimized libraries can be used.

    Detailed Alternative Approach (without code):
    ---------------------------------------------
    1. Modulo-based Euclidean Algorithm:
        - While b != 0, set a = b, b = a % b.
        - When b becomes 0, a is the GCD.
    2. Recursive version:
        - If b == 0, return a; else return gcd(b, a % b).
    3. Built-in functions (like __gcd in GCC) can be used for simplicity and efficiency.
*/

// Function to compute GCD (HCF) using subtraction-based Euclidean Algorithm
int gcd(int a, int b) {
    // If either number is zero, return the other (GCD of 0 and b is b)
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Loop until one of the numbers becomes zero
    while (a > 0 && b > 0) {
        if (a > b)
            a = a - b; // Subtract smaller from larger
        else
            b = b - a;
    }

    // When one number becomes zero, the other is the GCD
    return (a == 0) ? b : a;
}

int main() {
    int a = 72; // First number
    int b = 24; // Second number

    // Calculate GCD (HCF) of a and b
    int ans = gcd(a, b);

    // Output the GCD
    cout << "HCF = " << ans << endl;

    // Calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
    int ans1 = (a * b) / ans;

    // Output the LCM
    cout << "LCM = " << ans1 << endl;

    return 0;
}

/*
    Dry Run:
    --------
    Input: a = 72, b = 24

    gcd(72, 24):
        a = 72, b = 24
        a > b => a = a - b = 72 - 24 = 48
        a = 48, b = 24
        a > b => a = a - b = 48 - 24 = 24
        a = 24, b = 24
        a == b => b = b - a = 24 - 24 = 0
        a = 24, b = 0
        (a == 0)? No, so return a = 24

    HCF = 24

    LCM = (72 * 24) / 24 = 72

    Output:
    HCF = 24
    LCM = 72

    Note:
    -----
    For large numbers, prefer the modulo-based approach for efficiency.
*/