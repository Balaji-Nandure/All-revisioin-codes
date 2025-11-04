/*
Approach:
-----------
- Demonstrate function overriding and polymorphism in C++ using base and derived classes.
- Use the 'virtual' keyword to enable runtime polymorphism.
- Show the effect of upcasting and downcasting pointers.
- Add comments to explain logic and best practices.
- Suggest better alternatives and improvements in comments.
- Provide a dry run at the end.

Better Alternatives:
--------------------
1. Always use 'override' keyword in derived class for clarity (C++11 onwards).
2. Avoid raw pointers; prefer smart pointers to manage memory automatically.
3. Avoid downcasting unless absolutely necessary; use dynamic_cast for safety.
4. Use destructors as virtual in base class to avoid memory leaks.

*/

#include<iostream>
using namespace std;

// Base class
class Animal {
    public:
        // 'virtual' enables runtime polymorphism for speak()
        virtual void speak() {
            cout << "Speaking" << endl; // Base class implementation
        }
        // Always declare virtual destructor in base class for proper cleanup
        virtual ~Animal() {}
};

// Derived class
class Dog : public Animal {
    public:
        // Function overriding: provides Dog-specific implementation
        void speak() override { // 'override' ensures correct overriding (C++11+)
            cout << "Barking" << endl;
        }
        ~Dog() override {}
};

int main() {
    // Creating base class object pointer
    Animal *a = new Animal();
    a->speak(); // Output: Speaking (calls Animal::speak)
    delete a; // Clean up memory

    // Creating derived class object pointer
    Dog *b = new Dog();
    b->speak(); // Output: Barking (calls Dog::speak)
    delete b; // Clean up memory

    // Upcasting: Derived object assigned to base class pointer
    Animal *c = new Dog();
    c->speak(); // Output: Barking (calls Dog::speak due to virtual)
    delete c; // Clean up memory

    // Downcasting: Base object assigned to derived class pointer (unsafe)
    // This is dangerous and leads to undefined behavior!
    // Use dynamic_cast for safety (returns nullptr if cast fails)
    Animal* basePtr = new Animal();
    Dog* d = dynamic_cast<Dog*>(basePtr);
    if (d) {
        d->speak(); // Will not execute, as basePtr is not actually a Dog
    } else {
        cout << "Downcasting failed: basePtr is not a Dog" << endl;
    }
    delete basePtr;

    /*
    // Better alternative: Use smart pointers (C++11+)
    #include <memory>
    std::unique_ptr<Animal> a = std::make_unique<Animal>();
    a->speak();
    std::unique_ptr<Animal> c = std::make_unique<Dog>();
    c->speak();
    // No need to manually delete, memory is managed automatically.
    */

    return 0;
}

/*
Dry Run:
---------
1. Animal *a = new Animal(); a->speak(); // Output: Speaking
2. Dog *b = new Dog(); b->speak(); // Output: Barking
3. Animal *c = new Dog(); c->speak(); // Output: Barking (virtual function)
4. Animal* basePtr = new Animal(); Dog* d = dynamic_cast<Dog*>(basePtr);
   - dynamic_cast fails, d is nullptr, prints: Downcasting failed: basePtr is not a Dog

Key Points:
-----------
- 'virtual' enables runtime polymorphism.
- 'override' ensures correct overriding.
- Always use virtual destructors in base class.
- Prefer smart pointers over raw pointers.
- Avoid unsafe downcasting; use dynamic_cast for safety.
*/