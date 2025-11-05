// Problem (Short): For a given integer n consisting only of digits 4 and 7, 
// find its position among all such numbers when sorted in increasing order.

// Approach (Short): Treat numbers made up of only 4 and 7 as binary numbers (4=0, 7=1). 
// Count numbers with fewer digits, then for equal-length numbers, convert to binary and add 1.

// Solution:
#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    int len = n.size();
    int binVal = 0;

    for (char c : n) {
        binVal = (binVal << 1) + (c == '7');  // 4→0, 7→1
    }

    int pos = (1 << len) - 1 + binVal;
    cout << pos << "\n";
}