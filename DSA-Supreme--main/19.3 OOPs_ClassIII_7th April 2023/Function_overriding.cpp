/*
Approach:
-----------
This code demonstrates the concept of function overriding in C++ using inheritance. 
A base class `Animal` has a method `speak()`. The derived class `Dog` overrides this method.
When we call `speak()` on an object of type `Dog`, the overridden method in `Dog` is called.
However, in this code, the function is not marked as `virtual`, so if we use base class pointers, 
the base class method will be called (static binding). To achieve dynamic binding (runtime polymorphism), 
we should use the `virtual` keyword.

Below, all important lines are commented for clarity. 
At the end, a better alternative using `virtual` and pointers is provided in comments.
A dry run is also included at the end.
*/

#include<iostream>
using namespace std;

// Base class Animal
class Animal{
    public:
        // Base class method speak
        void speak(){
            cout<<"Speaking"<<endl; // Prints "Speaking" when called
        }
};

// Derived class Dog inherits from Animal
class Dog : public Animal{
    public:
        // Overriding speak method of Animal
        void speak(){
            cout<<"Barking"<<endl; // Prints "Barking" when called
        }
};

int main(){
    Animal a;      // Creating object of base class Animal
    a.speak();     // Calls Animal::speak(), outputs: Speaking

    Dog d;         // Creating object of derived class Dog
    d.speak();     // Calls Dog::speak(), outputs: Barking

    // --- Better Alternative: Using Virtual Functions for Runtime Polymorphism ---
    /*
    class Animal{
        public:
            virtual void speak(){
                cout<<"Speaking"<<endl;
            }
    };
    class Dog : public Animal{
        public:
            void speak() override {
                cout<<"Barking"<<endl;
            }
    };
    int main(){
        Animal* a = new Animal();
        a->speak(); // Output: Speaking

        Animal* b = new Dog();
        b->speak(); // Output: Barking (because of virtual function, dynamic binding)

        delete a;
        delete b;
        return 0;
    }
    */
    // In the above approach, using virtual functions allows us to achieve runtime polymorphism.
    // When a base class pointer points to a derived class object and calls the overridden function,
    // the derived class's function is invoked.

    return 0;
}

/*
Dry Run:
---------
1. Animal a; a.speak();
   - Creates an Animal object 'a'.
   - Calls a.speak(), which prints "Speaking".

2. Dog d; d.speak();
   - Creates a Dog object 'd'.
   - Calls d.speak(), which prints "Barking".

If we use pointers and virtual functions (see alternative above):
   - Animal* b = new Dog();
   - b->speak(); // prints "Barking" due to dynamic binding.

Key Points:
-----------
- Function overriding allows derived classes to provide specific implementations of functions defined in base classes.
- Without 'virtual', function call is resolved at compile time (static binding).
- With 'virtual', function call is resolved at runtime (dynamic binding), enabling true polymorphism.
*/