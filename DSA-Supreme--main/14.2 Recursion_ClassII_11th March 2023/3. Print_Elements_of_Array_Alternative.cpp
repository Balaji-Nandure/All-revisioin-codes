
// Include input-output stream library
#include<iostream>
using namespace std;

// Recursive function to print all elements of an array
void printArrayElements(int arr[], int size) {
    // Base Case: If size is 0, stop recursion
    if(size == 0)
        return;

    // Print the first element of the current array
    cout << arr[0] << " ";

    // Recursive Call: Move to the next element (arr+1) and decrease size by 1
    printArrayElements(arr + 1, size - 1);
}

// Recursive function to print array elements in reverse order
void printArrayReverse(int arr[], int size) {
    // Base Case: If size is 0, stop recursion
    if(size == 0)
        return;
    
    // Recursive Call: Move to the next element (arr+1) and decrease size by 1
    printArrayReverse(arr + 1, size - 1);

    // Print the first element of the current (sub)array after recursion
    cout << arr[0] << " ";
}


int main() {
    // Initialize array with 5 elements
    int arr[] = {1, 2, 3, 4, 5};
    // Store the size of the array
    int size = 5;

    // Call the recursive function to print array elements
    printArrayElements(arr, size);
    cout << endl;
    cout << "Array elements in reverse order: ";
    // Call the recursive function to print array elements in reverse order
    printArrayReverse(arr, size);

    // Return 0 to indicate successful execution
    return 0;
}

