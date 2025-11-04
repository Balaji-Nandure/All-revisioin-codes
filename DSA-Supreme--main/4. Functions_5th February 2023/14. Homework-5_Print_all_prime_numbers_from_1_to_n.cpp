/*
Approach:
-----------
- The goal is to print all prime numbers from 1 to n using functions in C++.
- We'll use a helper function `checkPrime(int num)` to check if a number is prime.
- For each number from 2 to n, we check if it is prime and print it if true.
- A number is prime if it is greater than 1 and has no divisors other than 1 and itself.
*/

#include<iostream>
using namespace std;

// Function to check if a number is prime
bool checkPrime(int num){
    int factor = 0; // To count if any factor is found
    if(num < 2){ // Numbers less than 2 are not prime
        return false;
    }
    // Check divisibility from 2 to num-1
    for(int i = 2; i < num; i++){
        if(num % i == 0){ // If num is divisible by i, it's not prime
            factor++;     // Increment factor count
            break;        // No need to check further, exit loop
        }
    }   
    if(factor == 1){ // If any factor found, not prime
        return false;
    }
    else{ // No factors found, number is prime
        return true;
    }
}

// Function to print all prime numbers from 2 to n
void printPrime(int n){
    for(int i = 2; i <= n; i++){ // Loop from 2 to n
        if(checkPrime(i)){       // If i is prime
            cout << i << endl;   // Print the prime number
        }
    }
}

int main(){
    int n = 100; // Set the upper limit to print primes up to 100
    printPrime(n); // Call function to print all primes up to n
    return 0;
}

/*
Dry Run:
-----------
n = 10

Loop i from 2 to 10:
- i = 2: checkPrime(2) -> true (prime) -> print 2
- i = 3: checkPrime(3) -> true (prime) -> print 3
- i = 4: checkPrime(4) -> false (not prime)
- i = 5: checkPrime(5) -> true (prime) -> print 5
- i = 6: checkPrime(6) -> false (not prime)
- i = 7: checkPrime(7) -> true (prime) -> print 7
- i = 8: checkPrime(8) -> false (not prime)
- i = 9: checkPrime(9) -> false (not prime)
- i = 10: checkPrime(10) -> false (not prime)

Output:
2
3
5
7
*/