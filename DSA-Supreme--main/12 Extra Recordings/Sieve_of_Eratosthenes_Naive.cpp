/*
    Approach Used:
    ----------------
    This code implements the Sieve of Eratosthenes (naive version) to find all prime numbers up to a given number n.
    The idea is to mark all multiples of each prime number as non-prime (false) in a boolean array.

    Steps:
    1. Create a boolean vector of size n+1 and initialize all entries as true (assuming all numbers are prime).
    2. Set sieve[0] and sieve[1] to false, as 0 and 1 are not prime numbers.
    3. For each number i from 2 to n:
        - If i is marked as prime (sieve[i] == true), mark all its multiples as non-prime.
    4. Return the sieve vector.

    Better Alternative (Optimized Sieve):
    -------------------------------------
    - Instead of starting to mark multiples from i*2, start from i*i, because all smaller multiples would have already been marked by smaller primes.
    - Only iterate i up to sqrt(n), as any composite number greater than sqrt(n) will have a smaller factor already processed.
    - This reduces unnecessary iterations and improves efficiency.

    Example of Optimized Approach (in words, not code):
    - For i = 2 to sqrt(n):
        - If sieve[i] is true:
            - For j = i*i to n, incrementing by i:
                - Mark sieve[j] as false.

    Time Complexity:
    ----------------
    - Naive Sieve: O(n log n)
    - Optimized Sieve: O(n log log n)
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to generate sieve of Eratosthenes up to n
vector<bool> Sieve(int n) {
    // Step 1: Initialize a boolean vector of size n+1 with all entries as true
    vector<bool> sieve(n+1, true); // Assume all numbers are prime initially

    // Step 2: 0 and 1 are not prime numbers
    sieve[0] = sieve[1] = false;

    // Step 3: Mark non-primes using the naive approach
    for(int i = 2; i <= n; i++) { // Start from the first prime number, 2
        if(sieve[i] == true) { // If i is still marked as prime
            int j = i * 2; // Start marking multiples of i from 2*i
            while(j <= n) {
                sieve[j] = false; // Mark j as non-prime
                j = j + i; // Move to the next multiple of i
            }
        }
    }
    // Step 4: Return the sieve vector
    return sieve;
}

int main() {
    int n = 25; // Set the upper limit for primes
    vector<bool> sieve = Sieve(n); // Generate sieve up to n

    // Print all prime numbers up to n
    cout << "Prime numbers up to " << n << " are: ";
    for(int i = 2; i <= n; i++) { // Start from 2, as 0 and 1 are not prime
        if(sieve[i] == true) { // If i is prime
            cout << i << " "; // Print the prime number
        }
    }
    cout << endl;
    return 0;
}

/*
    Dry Run for n = 10:
    --------------------
    Initial sieve: [F, F, T, T, T, T, T, T, T, T, T]
    i = 2: sieve[2] is true
        Mark 4, 6, 8, 10 as false
        sieve: [F, F, T, T, F, T, F, T, F, T, F]
    i = 3: sieve[3] is true
        Mark 6, 9 as false (6 already false)
        sieve: [F, F, T, T, F, T, F, T, F, F, F]
    i = 4: sieve[4] is false, skip
    i = 5: sieve[5] is true
        Mark 10 as false (already false)
    i = 6: sieve[6] is false, skip
    i = 7: sieve[7] is true
        No multiples <= 10
    i = 8,9,10: all false or no multiples <= 10

    Final primes: 2, 3, 5, 7

    Note:
    -----
    - For large n, use the optimized approach for better performance.
    - The current code is for educational/demonstration purposes.
*/