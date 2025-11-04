/*
Approach Used:
---------------
- The code counts the number of prime numbers strictly less than a given integer n.
- It uses a helper function `isPrime` to check if a number is prime by trial division up to sqrt(n).
- For each number from 2 to n-1, it checks if the number is prime and increments the count if true.

Better/Alternative Approaches (without code):
---------------------------------------------
1. Sieve of Eratosthenes:
   - Use a boolean array to mark multiples of each prime as non-prime.
   - Much more efficient for large n (O(n log log n) time, O(n) space).
   - Avoids repeated work of checking each number individually.
2. Segmented Sieve:
   - Useful for very large n where memory is a concern.
   - Processes numbers in segments to reduce memory usage.
3. Bitset Sieve:
   - Use bitsets instead of bool arrays to save space.
4. Wheel Factorization:
   - Skip obvious non-primes (multiples of 2, 3, 5, etc.) to speed up trial division.
5. Use built-in libraries (for some languages) or optimized prime-checking algorithms.

Improvements Made:
------------------
- Added detailed comments explaining the logic behind each important line.
- Used <cmath> instead of <math.h> for C++ compatibility.
- Used 'int' for loop variable in sqrt to avoid repeated computation.
- Added input prompt for user to enter n.
- Added dry run at the end of the code.

*/

#include <iostream>
#include <cmath> // Use <cmath> for C++ instead of <math.h>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1)
        return false;
    // Check divisibility from 2 up to sqrt(n)
    // If any divisor found, n is not prime
    int limit = sqrt(n); // Compute sqrt(n) once for efficiency
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) // If n is divisible by i, it's not prime
            return false;
    }
    // No divisors found, n is prime
    return true;
}

// Function to count number of primes strictly less than n
int countPrimes(int n) {
    int count = 0; // Initialize count of primes
    // Iterate from 2 up to n-1 (since strictly less than n)
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) // Check if i is prime
            count++;    // Increment count if prime
    }
    return count; // Return total count of primes found
}

int main() {
    int n;
    cout << "Enter n: "; // Prompt user for input
    cin >> n;            // Read value of n
    int ans = countPrimes(n); // Count primes less than n
    cout << "Number of primes strictly less than " << n << " is: " << ans << endl;
    return 0;
}

/*
Dry Run:
--------
Input: n = 5

Loop i from 2 to 4:
- i = 2: isPrime(2) -> true (prime), count = 1
- i = 3: isPrime(3) -> true (prime), count = 2
- i = 4: isPrime(4) -> false (not prime), count remains 2

Output: Number of primes strictly less than 5 is: 2

Explanation:
- Primes less than 5 are 2 and 3.
*/