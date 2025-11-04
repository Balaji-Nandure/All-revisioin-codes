/*
Approach:
-----------
- Demonstrate declaration and initialization of arrays of different data types in C++.
- Show how to print the elements of an integer array using a loop.
- Show how to take input from the user and store it in an array.
- Use comments to explain the logic behind each important line.
*/

#include<iostream>
using namespace std;

int main(){
    // Declaration of integer array of size 7 (allocates 28 bytes if int is 4 bytes)
    int arr[7]; // arr can store 7 integers

    // Declaration of integer array of size 53
    int a[53]; // a can store 53 integers

    // Declaration of character array of size 106
    char ch[106]; // ch can store 106 characters

    // Declaration of boolean array of size 10
    bool arr1[10]; // arr1 can store 10 boolean values (true/false)

    // Initialization of integer array with 5 elements
    int arr2[] = {1,2,3,4,5}; // arr2 is initialized with values 1,2,3,4,5

    // Printing array values
    int array[5] = {1,2,3,4,5}; // Declare and initialize array with 5 elements

    // Loop to print each element of the array
    for(int i = 0; i < 5; i++){ // i is the index, loop runs from 0 to 4
        cout << array[i] << " "; // Print the value at index i
    }
    cout << endl; // Print newline after printing array

    // Taking the input and initializing the array
    int array1[10]; // Declare an integer array of size 10

    cout << "Enter array values " << endl; // Prompt user for input

    // Loop to take input for each element of the array
    for(int i = 0; i < 10; i++){
        cin >> array1[i]; // Store user input at index i
    }

    // (Optional) Print the entered values to verify input
    cout << "You entered: ";
    for(int i = 0; i < 10; i++){
        cout << array1[i] << " ";
    }
    cout << endl;

    return 0;   
}

/*
Dry Run:
-----------
Suppose user enters: 11 22 33 44 55 66 77 88 99 100

Step-by-step:
- array[5] is initialized as {1,2,3,4,5}
- The loop prints: 1 2 3 4 5

- Prompt: "Enter array values"
- User enters: 11 22 33 44 55 66 77 88 99 100
- array1[0] = 11
- array1[1] = 22
- array1[2] = 33
- array1[3] = 44
- array1[4] = 55
- array1[5] = 66
- array1[6] = 77
- array1[7] = 88
- array1[8] = 99
- array1[9] = 100

- The program prints: "You entered: 11 22 33 44 55 66 77 88 99 100"
*/