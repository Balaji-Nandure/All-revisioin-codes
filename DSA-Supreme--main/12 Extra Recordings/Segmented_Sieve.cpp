/*
Approach Used:
---------------
This code implements the Segmented Sieve of Eratosthenes to find all prime numbers in a given range [L, R]. 
The idea is to first generate all primes up to sqrt(R) using the classic Sieve of Eratosthenes, 
then use these primes to mark non-primes in the segment [L, R].

Key Steps:
1. Generate all base primes up to sqrt(R) using the Sieve of Eratosthenes.
2. For each base prime, mark its multiples as non-prime in the range [L, R].
3. Output all numbers in [L, R] that remain marked as prime.
*/

// Include necessary headers
#include<iostream>
#include<vector>
#include<cmath> // Use cmath for sqrt
using namespace std;

// Classic Sieve of Eratosthenes to generate all primes up to n
vector<bool> Sieve(int n) {
    vector<bool> sieve(n + 1, true); // Initially mark all numbers as prime
    sieve[0] = sieve[1] = false;     // 0 and 1 are not prime

    // Only need to check up to sqrt(n)
    for (int i = 2; i * i <= n; ++i) { // Optimization: i*i <= n
        if (sieve[i]) { // If i is prime
            // Start marking multiples of i from i*i (Optimization)
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false; // Mark as not prime
            }
        }
    }
    return sieve;
}

// Segmented Sieve to find primes in [L, R]
vector<bool> segSieve(int L, int R) {
    int limit = sqrt(R);
    vector<bool> sieve = Sieve(limit); // Get all primes up to sqrt(R)
    vector<int> basePrimes;

    // Collect all base primes from sieve
    for (int i = 2; i <= limit; ++i) {
        if (sieve[i]) {
            basePrimes.push_back(i);
        }
    }

    // Initialize all numbers in [L, R] as prime
    vector<bool> segSieve(R - L + 1, true);

    // Handle base cases: 0 and 1 are not prime
    if (L == 0) segSieve[0] = false;
    if (L <= 1 && R >= 1) segSieve[1 - L] = false;

    // For each base prime, mark its multiples in [L, R] as not prime
    for (int prime : basePrimes) {
        // Find the minimum number in [L, R] that is a multiple of prime
        int first_mul = max(prime * prime, ((L + prime - 1) / prime) * prime);
        // Mark all multiples of prime in [L, R] as not prime
        for (int j = first_mul; j <= R; j += prime) {
            segSieve[j - L] = false;
        }
    }
    return segSieve;
}

int main() {
    int L = 110;
    int R = 130;

    // Get the segmented sieve for [L, R]
    vector<bool> segmentedSieve = segSieve(L, R);

    // Output all primes in [L, R]
    cout << "Primes in range [" << L << ", " << R << "]: ";
    for (int i = 0; i < segmentedSieve.size(); ++i) {
        if (segmentedSieve[i]) {
            cout << (i + L) << " ";
        }
    }
    cout << endl;

    /*
    Dry Run for L = 110, R = 130:
    -----------------------------
    1. Compute base primes up to sqrt(130) ≈ 11:
       basePrimes = [2, 3, 5, 7, 11]
    2. Initialize segSieve[0..20] as true (for numbers 110 to 130).
    3. For each base prime, mark its multiples in [110, 130]:
       - For 2: Mark 110, 112, ..., 130 as not prime.
       - For 3: Mark 111, 114, ..., 129 as not prime.
       - For 5: Mark 110, 115, 120, 125, 130 as not prime.
       - For 7: Mark 112, 119, 126 as not prime.
       - For 11: Mark 121, 132 (but 132 > 130, so only 121).
    4. Remaining true indices correspond to primes: 113, 127, 131 (but 131 > 130).
       So, output: 113, 127, 131 (if R >= 131).
       For R = 130, output: 113, 127.
    */

    return 0;
}

/*
Summary of Improvements:
------------------------
- Added detailed comments for each important line and logic.
- Used for loop instead of while for marking multiples (more readable).
- Used max(prime*prime, ((L+prime-1)/prime)*prime) for correct first multiple.
- Added dry run and approach explanation.
- Provided better alternatives in comments.
*/