#include<iostream>
using namespace std;

/*
Approach:
----------
This code demonstrates the concept of Function Overloading in C++. 
Function overloading allows multiple functions to have the same name but different parameter lists (type or number of parameters).
Here, the 'sum' function is overloaded to handle different types and numbers of arguments.

Better Alternatives:
--------------------
1. Use default arguments to reduce the number of overloaded functions.
2. Use templates for more generic code (if you want to support more types).
3. Use double instead of float for more precision in real-world applications.

Alternative 1: Using Default Arguments
--------------------------------------
int sum(int a, int b, int c = 0) {
    return a + b + c;
}

Alternative 2: Using Templates
------------------------------
template<typename T, typename U>
auto sum(T a, U b) -> decltype(a + b) {
    return a + b;
}
template<typename T, typename U, typename V>
auto sum(T a, U b, V c) -> decltype(a + b + c) {
    return a + b + c;
}
*/

// Class definition for Maths
class Maths{
    public:
        // Function to sum two integers
        int sum(int a, int b){
            // Returns the sum of two integers
            return a + b;
        }
        // Function to sum three integers
        int sum(int a, int b, int c){
            // Returns the sum of three integers
            return a + b + c;
        }
        // Function to sum an integer and a float
        int sum(int a, float b){
            // Returns the sum of an integer and a float (result will be truncated to int)
            return a + static_cast<int>(b); // Explicit cast to avoid warnings and clarify truncation
        }
};

int main(){
    Maths obj; // Create an object of Maths class

    // Call sum with two integers
    cout << obj.sum(2, 3) << endl; // Output: 5

    // Call sum with three integers
    cout << obj.sum(2, 3, 5) << endl; // Output: 10

    // Call sum with an integer and a float
    cout << obj.sum(2, 5.6f) << endl; // Output: 7 (5.6 is truncated to 5)

    return 0;
}

/*
Dry Run:
--------
main():
    Maths obj; // Creates object

    obj.sum(2, 3):
        Calls sum(int, int)
        Returns 2 + 3 = 5
        Output: 5

    obj.sum(2, 3, 5):
        Calls sum(int, int, int)
        Returns 2 + 3 + 5 = 10
        Output: 10

    obj.sum(2, 5.6f):
        Calls sum(int, float)
        5.6f is cast to int (5)
        Returns 2 + 5 = 7
        Output: 7

Better Approach Example (Using Default Arguments):
-------------------------------------------------
class Maths {
    public:
        int sum(int a, int b, int c = 0) {
            return a + b + c;
        }
};

int main() {
    Maths obj;
    cout << obj.sum(2, 3) << endl;      // 5
    cout << obj.sum(2, 3, 5) << endl;   // 10
    return 0;
}

Better Approach Example (Using Templates):
------------------------------------------
template<typename T, typename U>
auto sum(T a, U b) -> decltype(a + b) {
    return a + b;
}
template<typename T, typename U, typename V>
auto sum(T a, U b, V c) -> decltype(a + b + c) {
    return a + b + c;
}

int main() {
    cout << sum(2, 3) << endl;         // 5
    cout << sum(2, 3, 5) << endl;      // 10
    cout << sum(2, 5.6f) << endl;      // 7.6
    return 0;
}
*/