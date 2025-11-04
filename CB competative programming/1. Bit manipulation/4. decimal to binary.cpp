#include <iostream>
#include <cmath>
using namespace std;

// Function to convert a decimal number to binary
// tc = O(logn)
// sc = O(1)
void decimalToBinary(int n) {
    int binary = 0;
    int i = 0;
    while (n > 0) {
        binary += (n & 1) * pow(10, i);
        n >>= 1;
        i++;
    }
}

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    decimalToBinary(n);
    return 0;
}