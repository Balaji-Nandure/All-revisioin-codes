/*
    Approach Used:
    ----------------
    - This code uses the naive approach to count the number of prime numbers strictly less than a given number n.
    - For each number from 2 to n-1, it checks if the number is prime by checking divisibility from 2 to sqrt(number).
    - If a number is prime, it increments the count.
    - Finally, it returns the count of prime numbers found.

    Better Alternatives (without code):
    -----------------------------------
    1. Sieve of Eratosthenes:
        - Create a boolean array of size n, initialized to true.
        - Mark all multiples of each prime starting from 2 as false (not prime).
        - Count the number of true values (primes) in the array.
        - Time Complexity: O(n log log n), much faster than the naive approach.
    2. Optimized Prime Check:
        - Instead of checking divisibility up to n-1, check up to sqrt(n).
        - Skip even numbers after checking for 2.
        - Reduces the number of iterations for each prime check.

    Dry Run Example (n = 5):
    ------------------------
    - Check numbers: 2, 3, 4
    - 2: Prime (count = 1)
    - 3: Prime (count = 2)
    - 4: Not prime
    - Output: 2
*/

#include<iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n){
    // 0 and 1 are not prime numbers
    if(n == 0 || n == 1)
        return false;

    // Check divisibility from 2 to sqrt(n) for better efficiency
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) // If n is divisible by i, it's not prime
            return false;
    }
    return true; // No divisors found, n is prime
}

// Function to count number of primes strictly less than n
int countPrimes(int n){
    int count = 0; // Initialize count of primes

    // Iterate from 2 to n-1 (since we want strictly less than n)
    for(int i = 2; i < n; i++){
        if(isPrime(i)) // If i is prime
            count++;   // Increment count
    }
    return count; // Return total count of primes found
}

int main(){
    int n = 5; // Input value
    int ans = countPrimes(n); // Get count of primes less than n
    cout << ans << endl; // Output the result
    return 0;
}

/*
    Dry Run for n = 5:
    -------------------
    i = 2: isPrime(2) -> true  => count = 1
    i = 3: isPrime(3) -> true  => count = 2
    i = 4: isPrime(4) -> false => count = 2
    Output: 2
*/