#include<iostream>
#include<vector>
#include<cmath> // Use <cmath> instead of <math.h> for C++ best practice
using namespace std;

// Function to generate sieve of Eratosthenes up to n
vector<bool> Sieve(int n) {
    // Step 1: Initialize a boolean vector of size n+1, all set to true
    vector<bool> sieve(n + 1, true); // Assume all numbers are prime initially

    // Step 2: 0 and 1 are not prime numbers
    sieve[0] = sieve[1] = false;

    // Step 3: Iterate from 2 to sqrt(n)
    // Only need to check up to sqrt(n) because any composite number n must have a factor <= sqrt(n)
    for (int i = 2; i * i <= n; i++) { // More efficient than i <= sqrt(n)
        if (sieve[i]) { // If i is still marked as prime
            // Step 4: Mark all multiples of i as non-prime, starting from i*i
            // All smaller multiples have already been marked by smaller primes
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false; // Mark as non-prime
            }
        }
    }
    return sieve; // Return the sieve vector
}

int main() {
    int n = 25; // Example value, can be changed as needed
    vector<bool> sieve = Sieve(n); // Generate sieve up to n

    // Print all prime numbers up to n
    cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; i++) { // Start from 2, as 0 and 1 are not prime
        if (sieve[i]) { // If i is prime
            cout << i << " ";
        }
    }
    cout << endl;

    /*
        Dry Run for n = 25:
        -------------------
        Initial sieve: [F, F, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T]
        i = 2: Mark 4,6,8,10,12,14,16,18,20,22,24 as F
        i = 3: Mark 9,12,15,18,21,24 as F
        i = 4: Already F, skip
        i = 5: Mark 25 as F
        Remaining T indices: 2,3,5,7,11,13,17,19,23
    */

    return 0;
}