#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------
A. Multiples Check
Given: Two integers x, y (x, y > 0, up to 1e9).
Output: "Multiples" if one is a multiple of the other, "No Multiples" otherwise.
----------------------------------------
*/
void problemA() {
    long long x, y;
    cin >> x >> y;
    if (x % y == 0 || y % x == 0)
        cout << "Multiples\n";
    else
        cout << "No Multiples\n";
}

/*
----------------------------------------
D. Range Sum
Given: Two integers a, b (1 <= a, b <= 1e9).
Output: Print the sum of all integers between a and b inclusive.
----------------------------------------
*/
void problemD() {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    long long sumB = b * (b + 1) / 2;
    long long sumA_1 = (a - 1) * a / 2;
    cout << sumB - sumA_1 << "\n";
}

/*
----------------------------------------
D2. Difference
Given: Four integers A, B, C, D.
Output: Print (A * B) - (C * D).
----------------------------------------
*/
void problemD2() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << (A * B - C * D) << "\n";
}

/*
----------------------------------------
L. The Brothers
Given: Two persons' names (F1 S1), (F2 S2). Each first name and surname is a string.
Output: "ARE Brothers" if S1 == S2, else "NOT"
----------------------------------------
*/
void problemL() {
    string F1, S1, F2, S2;
    cin >> F1 >> S1 >> F2 >> S2;
    if (S1 == S2)
        cout << "ARE Brothers\n";
    else
        cout << "NOT\n";
}

/*
----------------------------------------
N. Char
Given: Char X (English letter).
Output: Print X in opposite case (uppercase <-> lowercase).
----------------------------------------
*/
void problemN() {
    char X;
    cin >> X;
    if (islower(X))
        cout << (char)toupper(X) << "\n";
    else
        cout << (char)tolower(X) << "\n";
}

/*
----------------------------------------
Sort 3 Numbers
Given: 3 integers A, B, C.
Output: Print them sorted in ascending order, then print original order (same format as code).
----------------------------------------
*/
void problemSort3() {
    long long A, B, C;
    cin >> A >> B >> C;
    vector<long long> v = {A, B, C};
    sort(v.begin(), v.end());
    for (auto &x : v) cout << x << "\n";
    cout << "\n";
    cout << A << "\n" << B << "\n" << C << "\n";
}

/*
----------------------------------------
D. Difference
Given: Four integers A, B, C, D.
Output: Print "Difference = X", where X = (A * B) - (C * D).
----------------------------------------
*/
void problemD() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    long long X = (A * B) - (C * D);
    cout << "Difference = " << X << "\n";
}

/*
----------------------------------------
Sum, Product, Difference
Given: Two integers X, Y.
Output:
X + Y = ...
X * Y = ...
X - Y = ...
----------------------------------------
*/
void problemSumProdDiff() {
    long long X, Y;
    cin >> X >> Y;
    cout << X << " + " << Y << " = " << (X + Y) << "\n";
    cout << X << " * " << Y << " = " << (X * Y) << "\n";
    cout << X << " - " << Y << " = " << (X - Y) << "\n";
}

/*
----------------------------------------
Expression Evaluation
Given: One line A S B = C (A,B,C integers, S in {'+','-','*'}).
Output: Print "Yes" if correct, else print correct result.
----------------------------------------
*/
void problemExpressionEval() {
    int A, B, C;
    char S, eq;
    cin >> A >> S >> B >> eq >> C;
    int res;
    if (S == '+') res = A + B;
    else if (S == '-') res = A - B;
    else if (S == '*') res = A * B;
    else return;
    if (res == C)
        cout << "Yes\n";
    else
        cout << res << "\n";
}

/*
----------------------------------------
Last Two Digits of Multiplication
Given: Four integers A, B, C, D (could be large).
Output: Print the last 2 digits (including leading zero if <10) of A*B*C*D.
----------------------------------------
*/
void problemLastTwoDigits() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    long long result = 1;
    // result = (result * (A % 100)) % 100;
    // result = (result * (B % 100)) % 100;
    // result = (result * (C % 100)) % 100;
    // result = (result * (D % 100)) % 100;
    A = A % 100;
    B = B % 100;
    C = C % 100;
    D = D % 100;
    result = (A * B * C * D) % 100;
    if (result < 10)
        cout << "0" << result << "\n";
    else
        cout << result << "\n";
}

/*
----------------------------------------
Comparison Check
Given: One line with three items: A S B (A, B are integers, S in {'<', '>', '='}).
Output: Print "Right" if the comparison A S B is true, otherwise print "Wrong".
----------------------------------------
*/
void problemComparisonCheck() {
    int A, B;
    char S;
    cin >> A >> S >> B;
    if (S == '<') {
        if (A < B)
            cout << "Right\n";
        else
            cout << "Wrong\n";
    } else if (S == '>') {
        if (A > B)
            cout << "Right\n";
        else
            cout << "Wrong\n";
    } else if (S == '=') {
        if (A == B)
            cout << "Right\n";
        else
            cout << "Wrong\n";
    }
}

/*
----------------------------------------
Float or Integer Check

Given a number N.
Determine whether N is a float number or integer number.

Note:
If N is float number then print "float" followed by the integer part followed by decimal part separated by space.
If N is integer number then print "int" followed by the integer part separated by space.

Input
Only one line containing a number N (1≤N≤10^3)

Output
Print the answer required above.

Examples

Input
234.000

Output
int 234

Input
12.920

Output
float 12 920
----------------------------------------
*/
void problemFloatOrInt() {
    string s;
    cin >> s;

    int pos = s.find('.');
    if (pos < 0) {
        cout << "int " << s << "\n";
    } else {
        string integerPart = s.substr(0, pos);
        string decimalPart = s.substr(pos + 1);
        // Check if the decimal part is all zeros
        bool allZero = true;
        for (char c : decimalPart) {
            if (c != '0') {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            cout << "int " << integerPart << "\n";
        } else {
            cout << "float " << integerPart << " " << decimalPart << "\n";
        }
    }
}

void problemFloatOrInt2() {
    // this trick used in so many competative questions
    long double n;
    cin >> n;
    if(ceil(n) == flloor(n)){
        // this is int part
        cout << "int " << n << endl; 
    } else {
        // thsi is float number
        cout << "float " << floor(n) << " " << n-floor(n) << endl;
    }
}

/*
Given 4 numbers A,B,C and D.
If A^B > C^D, print "YES" otherwise, print "NO".

Input
Only one line containing 4 numbers A,B,C and D (1≤A,C≤10^7), (1≤B,D≤10^12)

Output
Print "YES" or "NO" according to the problem above.
*/
void problemPowerComparison() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    // Use logarithms to prevent overflow
    // Compare B*log(A) vs D*log(C)
    long double left = B * logl(A);
    long double right = D * logl(C);
    if (left > right) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}






/*
----------------------------------------
Main Function
Uncomment the problem you want to run below.
----------------------------------------
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // problemA();       // Multiples Check
    // problemD();       // Range Sum
    // problemD2();      // Difference (A*B-C*D)
    // problemL();       // The Brothers
    // problemN();       // Char case swap
    // problemSort3();   // Sort 3 Numbers
    // problemD();       // Difference (prints with text)

    return 0;
}
