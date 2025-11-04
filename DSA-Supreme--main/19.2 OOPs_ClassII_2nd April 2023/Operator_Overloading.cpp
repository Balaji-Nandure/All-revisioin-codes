/*
Approach:
-----------
- Demonstrate operator overloading in C++ by overloading the '+' operator for a custom class.
- Instead of performing addition, the overloaded '+' operator will print the difference between two objects' values.
- The code also shows how to use 'this' pointer and how operator overloading can be used for custom behavior.

Improvements:
-------------
- Make the operator+ function 'const' and 'const Param&' to follow best practices.
- Return the result instead of printing directly, for better reusability.
- Provide an alternative approach using friend function and operator- for more intuitive difference operation.
- Add detailed comments for each important line.
- Provide a dry run at the end.

*/

#include<iostream>
using namespace std;

// Class to demonstrate operator overloading
class Param{
    public:
    int val; // Data member to store integer value

    // Overloading '+' operator as a member function
    // Best practice: pass parameter as const reference and mark function as const
    int operator+(const Param& obj2) const {
        // 'this->val' is value of current object
        // 'obj2.val' is value of passed object
        int value1 = this->val;
        int value2 = obj2.val;
        // Return the difference instead of printing directly
        return (value1 - value2);
    }

    // Alternative: Overload '-' operator for difference (more intuitive)
    /*
    int operator-(const Param& obj2) const {
        return this->val - obj2.val;
    }
    */

    // Alternative: Use friend function for operator overloading
    /*
    friend int operator+(const Param& obj1, const Param& obj2) {
        return obj1.val - obj2.val;
    }
    */
};

int main(){
    Param obj1, obj2; // Create two objects of Param

    obj1.val = 7; // Assign value 7 to obj1
    obj2.val = 2; // Assign value 2 to obj2

    // This should print the difference between them using overloaded '+'
    cout << (obj1 + obj2) << endl; // Output: 5

    // Alternative: Using overloaded '-' operator (if implemented)
    // cout << (obj1 - obj2) << endl;

    // Alternative: Using friend function (if implemented)
    // cout << (operator+(obj1, obj2)) << endl;

    return 0;
}

/*
Dry Run:
---------
obj1.val = 7
obj2.val = 2

obj1 + obj2 calls operator+:
    value1 = obj1.val = 7
    value2 = obj2.val = 2
    return (7 - 2) = 5

cout << (obj1 + obj2) << endl; // prints 5
*/