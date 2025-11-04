/*
    Approach:
    ----------
    This code uses the Sieve of Eratosthenes algorithm to count the number of prime numbers strictly less than a given number n.
    The Sieve of Eratosthenes is an efficient algorithm to find all primes smaller than n in O(n log log n) time.

    Steps:
    1. Create a boolean vector 'prime' of size n, initialized to true. Each index represents whether the number is prime.
    2. Mark 0 and 1 as non-prime.
    3. For each number i from 2 to sqrt(n), if i is prime, mark all multiples of i (starting from i*i) as non-prime.
    4. Count the number of true values in the 'prime' vector from 2 to n-1.

    Better Alternatives:
    --------------------
    - Start marking multiples from i*i instead of 2*i, as all smaller multiples would have already been marked by smaller primes.
    - Use a bitset instead of vector<bool> for memory efficiency.
    - For very large n, use segmented sieve to reduce memory usage.
    - For counting primes up to n, use a precomputed sieve and prefix sum array for multiple queries.

    Dry Run Example (n = 21):
    --------------------------
    Initial: prime[0..20] = {F, F, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T}
    i=2: Mark 4,6,8,10,12,14,16,18,20 as F
    i=3: Mark 9,12,15,18 as F
    i=4: Already marked as F, skip
    ...
    Final primes: 2,3,5,7,11,13,17,19 (count = 8)

    Code:
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to count number of primes strictly less than n using Sieve of Eratosthenes
int countPrimes(int n){
    // If n <= 2, there are no primes less than n
    if(n <= 2) 
        return 0;

    // Create a boolean vector to mark prime numbers; initially assume all numbers are prime
    vector<bool> prime(n, true);

    // 0 and 1 are not prime numbers
    prime[0] = false;
    prime[1] = false;

    // Sieve of Eratosthenes main logic
    // Only need to check up to sqrt(n) for marking multiples
    for(int i = 2; i * i < n; i++){
        if(prime[i]){ // If i is still marked as prime
            // Mark all multiples of i as non-prime, starting from i*i
            for(int j = i * i; j < n; j += i){
                prime[j] = false;
            }
        }
    }

    // Count the number of primes found
    int count = 0;
    for(int i = 2; i < n; i++){
        if(prime[i]) count++;
    }
    return count; // Return the number of primes less than n
}

int main(){
    int n = 21;
    int ans = countPrimes(n);
    cout << ans; // Output: 8

    /*
    Dry Run for n = 21:
    --------------------
    prime[0] = F, prime[1] = F
    i=2: Mark 4,6,8,10,12,14,16,18,20 as F
    i=3: Mark 9,12,15,18 as F
    i=4: Already F, skip
    ...
    Remaining primes: 2,3,5,7,11,13,17,19 (count = 8)
    */
    return 0;
}

/*
    Alternative Approaches (without code):
    --------------------------------------
    1. Segmented Sieve: For very large n, process in blocks to reduce memory.
    2. Bitset Sieve: Use std::bitset for memory efficiency.
    3. Linear Sieve: For generating primes in O(n) time, though not needed for just counting.
    4. Precompute and use prefix sums for multiple queries.
*/