// Euclidean Algorithm for GCD (Greatest Common Divisor)
// Short formula: gcd(a, b) = gcd(b, a % b), with gcd(a, 0) = a

// write short approach without code
// 1. Iterative version
// 2. Recursive version (short formula)
// 3. Better approach: use __gcd(a, b) from <algorithm>
// 4. Use built-in libraries (for some languages) or optimized GCD algorithms.
// 5. Use BigInteger/Arbitrary Precision Libraries:
//    - For very large numbers, use libraries that support big integers to avoid integer overflow.



#include <iostream>
using namespace std;

// Iterative version
// tc: O(log(min(a,b)))
// sc: O(1)
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}



int gcd2(int A, int B)
{
    if(A == 0) return B;

    if(B == 0) return A;

    while(A > 0 && B > 0){
        if(A > B){
            A = A - B;
        }
        else{
            B = B - A;
        }
    }
    return A == 0 ? B : A;
}

// lcm using gcd
// lcm = (a * b) / gcd(a, b)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}


// Recursive version (short formula)
// int gcd(int a, int b) {
//     if(b == 0) return a;
//     return gcd(b, a % b);
// }

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    cout << "LCM of " << a << " and " << b << " is " << lcm(a, b) << endl;
    return 0;
}