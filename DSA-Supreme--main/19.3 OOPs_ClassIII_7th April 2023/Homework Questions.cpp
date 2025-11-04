
/*
Approach:
1. Demonstrate constructor usage and method overriding in C++ using base and derived classes.
2. Explain compile-time vs run-time polymorphism with code and comments.
3. Clarify how data members are handled in inheritance (copy vs reference).
4. Provide better alternatives and dry run for clarity.
*/

// 1) Implement constructor and overriding through code and try different cases.

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    int age;
    // Constructor for Animal
    Animal(int a) {
        age = a;
        cout << "Animal constructor called, age = " << age << endl; // Shows constructor call
    }
    // Virtual function for overriding
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    string name;
    // Constructor for Dog, calls base class constructor
    Dog(int a, string n) : Animal(a) {
        name = n;
        cout << "Dog constructor called, name = " << name << endl; // Shows constructor call
    }
    // Overriding speak() method
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

/*
Better Alternative:
- Use 'override' keyword for clarity and safety.
- Use initializer list for all members.
- Use smart pointers for dynamic allocation (if needed).
*/

// 2) Difference between compile time and run time polymorphism. (Very famous question in interview)

/*
Compile Time Polymorphism:
- Achieved using function overloading or operator overloading.
- Decision is made at compile time.

Example:
*/
class Math {
public:
    // Function overloading: same function name, different parameters
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

/*
Run Time Polymorphism:
- Achieved using inheritance and virtual functions.
- Decision is made at run time.

Example:
*/
void demonstratePolymorphism() {
    Animal* a; // Base class pointer
    Dog d(5, "Tommy");
    a = &d;
    a->speak(); // Calls Dog's speak() due to virtual function (run time polymorphism)
}

// 3) In inheritance, copy of data members is created in derived class or is passed by reference??

/*
Explanation:
- In C++, when a class is derived from a base class, the data members of the base class are copied into the derived class object.
- Each derived class object has its own copy of base class data members.
- They are NOT passed by reference.
- This allows derived class to have its own state independent of other objects.

Example:
*/
void inheritanceDataMemberDemo() {
    Dog d1(3, "Bruno");
    Dog d2(4, "Max");
    d1.age = 10; // d1's age is independent of d2's age
    cout << "d1 age: " << d1.age << ", d2 age: " << d2.age << endl;
}

/*
Dry Run:
- Create Dog object d(5, "Tommy"):
    - Animal constructor called, age = 5
    - Dog constructor called, name = Tommy
- Call a->speak() where a is Animal* pointing to Dog:
    - Output: Dog barks (run time polymorphism)
- inheritanceDataMemberDemo():
    - d1 and d2 have independent 'age' values.
    - Output: d1 age: 10, d2 age: 4
*/

/*
Summary of Better Alternatives:
- Always use 'override' for overridden methods.
- Prefer smart pointers for dynamic memory.
- Use initializer lists for all member initialization.
- For polymorphism, always use base class pointers/references and virtual functions.
*/
