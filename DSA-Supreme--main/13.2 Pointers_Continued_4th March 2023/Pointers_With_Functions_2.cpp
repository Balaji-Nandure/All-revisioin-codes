#include<iostream>
using namespace std;

/*
Approach:
- The code demonstrates how to use pointers to modify specific elements of an array via a function.
- By passing pointers to array elements into a function, we can directly update the values at those memory locations.
- This is an example of pass-by-address (using pointers) to achieve in-place modification of data structures.
- The function 'update' takes two pointers and updates the values they point to.
*/

/*
Better Alternatives (in comments):
- Instead of passing two separate pointers, we could pass the array and the indices to be updated, which is more readable and less error-prone.
- Using references (if only single elements are to be updated) can make the code safer and clearer.
- For more generic updates, consider passing a lambda or function pointer for custom update logic.
- For large arrays or more complex data, consider using std::vector for bounds safety and flexibility.
*/

void update(int *p, int *q) {
    // *p dereferences pointer p, updating the value at the memory location it points to (arr[1])
    *p = 100; // Set value at arr[1] to 100

    // *q dereferences pointer q, updating the value at the memory location it points to (arr[2])
    *q = 200; // Set value at arr[2] to 200
}

int main() {
    int arr[4] = {10, 20, 30, 40}; // Initialize array with 4 elements

    int *p = &arr[1]; // p points to the second element (index 1) of the array
    int *q = &arr[2]; // q points to the third element (index 2) of the array

    update(p, q); // Pass pointers to arr[1] and arr[2] to update their values

    // Print the updated array
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " "; // Output each element of the array
    }
    cout << endl; // Print newline for better output formatting

    return 0; // Indicate successful program termination
}

/*
Dry Run:
Initial array: arr = [10, 20, 30, 40]
p = &arr[1] (points to 20)
q = &arr[2] (points to 30)

Call update(p, q):
    *p = 100  => arr[1] = 100
    *q = 200  => arr[2] = 200

After update:
arr = [10, 100, 200, 40]

Output:
10 100 200 40

Summary:
- Only arr[1] and arr[2] are modified by the update function.
- The use of pointers allows direct modification of array elements from another function.
*/

/*
Alternative Approach (no code, just idea):
- Pass the array and indices to update, e.g., update(arr, idx1, val1, idx2, val2)
- Use std::vector for dynamic arrays and bounds checking.
- Use references for single element updates: void update(int &a, int &b)
- For more complex updates, pass a function or lambda to apply to selected elements.
*/