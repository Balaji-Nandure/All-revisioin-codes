/* 
Question (Inshort): 
Given a number n, Hulk wants to reach from step 0 to step n using minimum energy. 
He can jump any distance that is a power of 2 (1, 2, 4, 8, ...). 
Find the minimum number of jumps required.

Approach (Pointwise):
1. Each power-of-2 jump can be seen as a bit in the binary representation of n.
2. Counting the number of set bits in n gives the minimum number of jumps.
3. For each set bit, Hulk jumps the corresponding power of 2.

Solution (C++):
*/

#include <iostream>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        while(n) {
            ans += (n & 1); // count set bits
            n = n >> 1;
        }
        cout << ans << endl;
    }
    return 0;
}

