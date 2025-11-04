#include <iostream>
using namespace std;

// Function to count the number of set bits in an integer
// tc = O(logn)
// sc = O(1)
int countSetBits(int n) {
    int cnt = 0;
    while (n) {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

// count setbits fast
// tc = O(no. of setbits)
// sc = O(1)
// approach: Brian Kernighan's Algorithm
// n = n & (n-1) will remove the last set bit from n
int countSetBitsFast(int n) {
    int cnt = 0;
    while (n) {
        // it makes the last set bit 0
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}
    
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of set bits: " << countSetBits(n) << endl;
    cout << "Number of set bits: " << countSetBitsFast(n) << endl;
    return 0;
}
