/*
Approach Used:
---------------
We use recursion to print all elements of an array. The function printArrayElements takes the array, the current index, and the size of the array as arguments. At each recursive call, it prints the current element and then calls itself for the next index, until the base case (index == size) is reached.

Key Points:
- Recursion is used to traverse the array.
- Base case ensures recursion stops when all elements are printed.
- Processing step prints the current element.
- Recursive call moves to the next element.

*/

// Function to print all elements of an array recursively
void printArrayElements(int arr[], int i, int size){
    // Base Case: If current index reaches size, stop recursion
    if(i == size)
        return;
    // Processing: Print the current element at index i
    cout << arr[i] << " ";
    // Recursive Relation: Call function for next index
    printArrayElements(arr, i+1, size);
}

int main(){
    int arr[] = {1,2,3,4,5}; // Initialize array
    int size = 5;            // Size of the array
    int i = 0;               // Start index
    printArrayElements(arr, i, size); // Print all elements recursively
    return 0;
}

/*
Dry Run:
--------
arr = {1,2,3,4,5}, size = 5, i = 0

Call Stack:
printArrayElements(arr, 0, 5)
    prints 1
    printArrayElements(arr, 1, 5)
        prints 2
        printArrayElements(arr, 2, 5)
            prints 3
            printArrayElements(arr, 3, 5)
                prints 4
                printArrayElements(arr, 4, 5)
                    prints 5
                    printArrayElements(arr, 5, 5)
                        returns (base case)
Output: 1 2 3 4 5

Time Complexity: O(n)
Space Complexity: O(n) (due to recursion stack)
*/