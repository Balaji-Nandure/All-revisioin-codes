#include <bits/stdc++.h>
using namespace std;

double sqrtBinarySearch(double n, double epsilon = 1e-6) {
    double low = 0;
    double high = max(1.0, n); // handle n < 1
    double mid;

    while (high - low > epsilon) { // loop until precision is reached
        mid = (low + high) / 2.0;

        if (mid * mid < n) {
            low = mid;  // mid is smaller than sqrt(n)
        } else {
            high = mid; // mid is bigger than sqrt(n)
        }
    }

    return (low + high) / 2.0; // approximate sqrt
}

int main() {
    double n = 10;
    double sqrtValue = sqrtBinarySearch(n);

    cout << fixed << setprecision(6) << sqrtValue << endl; // 3.162278
    return 0;
}
