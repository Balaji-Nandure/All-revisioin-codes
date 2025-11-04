#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

// Function to find maximum element using recursion
int findMax(int arr[], int n) {
    if (n == 1) return arr[0]; // base case: only one element
    int maxRest = findMax(arr + 1, n - 1); // find max in rest of array
    return (arr[0] > maxRest) ? arr[0] : maxRest; // compare first element with max of rest
}

// Function to find minimum element using recursion
int findMin(int arr[], int n) {
    if (n == 1) return arr[0]; // base case: only one element
    int minRest = findMin(arr + 1, n - 1); // find min in rest of array
    return (arr[0] < minRest) ? arr[0] : minRest; // compare first element with min of rest
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Maximum element: " << findMax(arr, n) << endl;
    cout << "Minimum element: " << findMin(arr, n) << endl;

    return 0;
}
