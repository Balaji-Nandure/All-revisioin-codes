/*
Question: Little Girl and Maximum XOR

Given two integers l and r (l <= r). Choose any two integers a and b such that l ≤ a ≤ b ≤ r, and maximize (a xor b). Print this maximum value.

Approach:
1. Compute x = l XOR r.
2. Find the position of the most significant set bit in x.
3. The answer = (1 << (number_of_bits_in_x)) - 1

Solution:
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l, r;
    cin >> l >> r;

    long long x = l ^ r;
    long long ans = 0;

    while (x) {
        ans = (ans << 1) | 1; // for each differing bit, set one more bit in ans
        x >>= 1;
    }

    cout << ans << "\n";
}
