#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------
Check if Number is Prime

Given a number X, determine if it is a prime number.
A prime number is a natural number greater than 1 that is not divisible by any number other than 1 and itself.

Input
A single integer X (1 ≤ X ≤ 10^9)

Output
Print "YES" if X is a prime number, otherwise print "NO".

Examples

Input
7

Output
YES

Input
10

Output
NO

----------------------------------------

Solution Explanation:
We use trial division to check primality. For all numbers up to sqrt(X), check if any divides X. If none do, X is prime; else, it is composite.

*/

bool isPrimeProblem(long long x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    long long r = sqrtl(x);
    for (long long d = 3; d <= r; d += 2) {
        if (x % d == 0) return false;
    }
    return true;
}

/*
------------------------------------------------------------
C. Even, Odd, Positive and Negative
------------------------------------------------------------
Problem:
Given N numbers. Count how many of these values are even, odd, positive and negative.

Input:
- First line contains one number N (1 ≤ N ≤ 10^3)
- Second line contains N integers (-10^5 ≤ Xi ≤ 10^5)

Output:
Print four lines:
1. "Even: X"      → number of even numbers
2. "Odd: X"       → number of odd numbers
3. "Positive: X"  → number of positive numbers
4. "Negative: X"  → number of negative numbers

Example:
Input
5
-5 0 -3 -4 12

Output
Even: 3
Odd: 2
Positive: 1
Negative: 3
------------------------------------------------------------
*/

// 🧠 Function to process the numbers and print results
void countNumbers(const vector<int> &arr) {
    int even = 0, odd = 0, positive = 0, negative = 0;

    for (int x : arr) {
        // Check even or odd
        if (x % 2 == 0)
            even++;
        else
            odd++;

        // Check positive or negative
        if (x > 0)
            positive++;
        else if (x < 0)
            negative++;
    }

    // Print results
    cout << "Even: " << even << "\n";
    cout << "Odd: " << odd << "\n";
    cout << "Positive: " << positive << "\n";
    cout << "Negative: " << negative << "\n";
}

/*
------------------------------------------------------------
Z. Three Numbers
------------------------------------------------------------
Problem:
Given two numbers K and S.
Count the number of different values (X, Y, Z) such that:
    0 ≤ X, Y, Z ≤ K
    X + Y + Z = S

Input:
Two integers K and S
(0 ≤ K ≤ 3000, 0 ≤ S ≤ 3K)

Output:
Print the total number of valid triplets (X, Y, Z).

------------------------------------------------------------
Examples:
Input:
2 1
Output:
3
Explanation:
Possible triplets:
(0, 0, 1)
(0, 1, 0)
(1, 0, 0)

------------------------------------------------------------
Logic:
We need to count how many (X, Y, Z) satisfy:
X + Y + Z = S  and  0 ≤ X, Y, Z ≤ K.

Approach:
- For each X from 0 to K:
    For each Y from 0 to K:
        Z = S - X - Y
        If (0 ≤ Z ≤ K), it is a valid triplet → count++

Time Complexity: O(K²)
K ≤ 3000 ⇒ 9 million iterations max, which is fast enough.
------------------------------------------------------------
*/

// 🧠 Function to count valid (X, Y, Z)
int countTriplets(int K, int S) {
    int count = 0;
    for (int X = 0; X <= K; X++) {
        for (int Y = 0; Y <= K; Y++) {
            int Z = S - X - Y;
            if (Z >= 0 && Z <= K)
                count++;
        }
    }
    return count;
}

/*
Problem: K. Divisors
Given a number N. Print all the divisors of N in ascending order.

Input:
Only one line containing a number N (1 ≤ N ≤ 10^4).

Output:
Print all positive divisors of N, one number per line.

Example:
Input:
6

Output:
1
2
3
6
*/

// Function to find and return all divisors of N in ascending order
vector<int> getDivisors(int N) {
    vector<int> divisors;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            divisors.push_back(i);
            if (i != N / i) { // avoid duplicates for perfect squares
                divisors.push_back(N / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end()); // sort in ascending order
    return divisors;
}

/*
Problem: J. Primes from 1 to N
Given a number N. Print all prime numbers between 1 and N inclusive.

A prime number is a number that is greater than 1 and has only two factors: 1 and itself.
1 is NOT a prime number.
*/

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to print all primes from 1 to N
void printPrimes(int N) {
    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }
}

/*
Problem: O. Fibonacci
Given a number N, print the N-th Fibonacci number.

The Fibonacci sequence is defined as:
- fib(1) = 0
- fib(2) = 1
- fib(n) = fib(n - 1) + fib(n - 2) for n > 2

Input:
- A single integer N (1 ≤ N ≤ 50)

Output:
- The N-th Fibonacci number
*/

int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    int a = 0, b = 1;
    for (int i = 3; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

/*
Problem: A. Theatre Square
Theatre Square in Berland has size n × m meters. Each square flagstone has size a × a.
Find the minimum number of flagstones needed to cover the Square completely.
- Flagstones cannot be broken.
- Sides of flagstones should be parallel to the Square.
- It's allowed to cover area larger than the Square.

Input:
- Three integers: n m a (1 ≤ n, m, a ≤ 10^9)

Output:
- Minimum number of flagstones needed
*/

// Function to calculate minimum number of flagstones
long long minFlagstones(long long n, long long m, long long a) {
    // ceil division can be done as (x + y - 1) / y
    long long rows = (n + a - 1) / a;
    long long cols = (m + a - 1) / a;
    return rows * cols;
}

/*
Problem: G. Even Hate Odd
Given an array a of n integers. You can:
1. Increment any element by 1
2. Decrement any element by 1

Goal: Make the number of even elements equal to the number of odd elements
or detect if impossible.

Input:
- First line: t (number of test cases, 1 ≤ t ≤ 10)
- For each test case:
  - n (number of elements, 1 ≤ n ≤ 10^5)
  - a1 a2 ... an (elements of array, 1 ≤ ai ≤ 10^5)

Output:
- For each test case: minimum number of operations, or -1 if impossible
*/

// Function to compute minimum operations for one array
int minOperations(vector<int> &a) {
    int n = a.size();
    if (n % 2 != 0) return -1; // impossible if n is odd

    int evenCount = 0;
    int oddCount = 0;
    for (int num : a) {
        if (num % 2 == 0) evenCount++;
        else oddCount++;
    }

    // Number of changes needed to balance evens and odds
    return abs(evenCount - oddCount) / 2;
}

/*
Problem: A. Again Twenty Five!
Given a number n (2 ≤ n ≤ 2*10^18), calculate the last two digits of 5^n.

Input:
- A single integer n

Output:
- Last two digits of 5^n without spaces
*/

// Function to get last two digits of 5^n
string lastTwoDigits(long long n) {
    // Observation: For n >= 2, 5^n always ends with "25"
    return "25";
}

/*
Problem: A. Beautiful Year
Given a year y (1000 ≤ y ≤ 9000), find the minimum year strictly larger than y
such that all its digits are distinct.

Input:
- Single integer y

Output:
- Minimum year strictly larger than y with all distinct digits
*/

// Function to check if all digits in a number are distinct
bool hasDistinctDigits(int year) {
    set<int> digits;
    while (year > 0) {
        int d = year % 10;
        if (digits.count(d)) return false; // duplicate found
        digits.insert(d);
        year /= 10;
    }
    return true;
}

// Function to find the next beautiful year
int nextBeautifulYear(int y) {
    y++; // start checking from the next year
    while (!hasDistinctDigits(y)) {
        y++;
    }
    return y;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // long long X;
    // if (!(cin >> X)) return 0;
    // cout << (isPrimeSimple(X) ? "YES\n" : "NO\n");
    // ------------------------------------------------------
    // int N;
    // cin >> N;
    // vector<int> arr(N);
    // for (int i = 0; i < N; ++i) {
    //     cin >> arr[i];
    // }
    // -----------------------------------------------------------
    // int K, S;
    // cin >> K >> S;

    // cout << countTriplets(K, S) << endl;
    // -----------------------------------------------------------
    // int N;
    // cin >> N;
    // vector<int> divisors = getDivisors(N);
    // for (int d : divisors) {
    //     cout << d << endl;
    // }

    // -----------------------------------------------------------
    // int N;
    // cin >> N;
    // printPrimes(N);

    // -----------------------------------------------------------
    // int N;
    // cin >> N;
    // cout << fibonacci(N) << endl;
    // -----------------------------------------------------------
    // long long n, m, a;
    // cin >> n >> m >> a;
    // cout << minFlagstones(n, m, a) << endl;
    // -----------------------------------------------------------
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++) cin >> a[i];
    // cout << minOperations(a) << endl;

    // -----------------------------------------------------------
    // long long n;
    // cin >> n;
    // cout << lastTwoDigits(n) << endl;

    // -----------------------------------------------------------
    // int y;
    // cin >> y;
    // cout << nextBeautifulYear(y) << endl;
    // -----------------------------------------------------------

    // -----------------------------------------------------------

    // -----------------------------------------------------------

    // -----------------------------------------------------------
    
    

    return 0;
}
 