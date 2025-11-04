#include<iostream>
using namespace std;

/*
Approach:
-----------
- Demonstrate function overriding and constructor invocation order in inheritance.
- Show the effect of pointer types on function calls (static vs dynamic binding).
- Highlight the importance of using 'virtual' for achieving runtime polymorphism.
- Discuss pitfalls of unsafe downcasting.

Better Alternative:
-------------------
- Use 'virtual' keyword for base class function to enable dynamic binding.
- Always avoid unsafe downcasting (like Dog* d = (Dog*) new Animal()).
- Use smart pointers (e.g., unique_ptr) for better memory management (not shown here for simplicity).
*/

// Base class
class Animal{
    public:
        Animal(){
            cout<<"Animal constructor"<<endl; // Constructor of Animal called
        }
        // 'speak' is a normal method (not virtual), so static binding will occur
        void speak(){
            cout<<"Speaking"<<endl; // Animal's speak
        }
        // Better: Use virtual for runtime polymorphism
        // virtual void speak(){
        //     cout<<"Speaking"<<endl;
        // }
        // virtual ~Animal() {} // Good practice: virtual destructor in base class
};

// Derived class
class Dog : public Animal{
    public:
        Dog(){
            cout<<"Dog constructor"<<endl; // Constructor of Dog called after Animal's constructor
        }
        // Function overriding (but without 'virtual' in base, static binding will occur)
        void speak(){
            cout<<"Barking"<<endl; // Dog's speak
        }
        // Better: Use 'override' keyword for clarity
        // void speak() override {
        //     cout<<"Barking"<<endl;
        // }
};

int main(){
    // Creating an Animal object using base class pointer
    Animal *a = new Animal(); // Output: Animal constructor
    a->speak(); // Output: Speaking (Animal's speak, as expected)

    // Creating a Dog object using derived class pointer
    Dog *b = new Dog(); // Output: Animal constructor, Dog constructor
    b->speak(); // Output: Barking (Dog's speak, as expected)

    // Creating a Dog object but storing in base class pointer
    Animal *c = new Dog(); // Output: Animal constructor, Dog constructor
    c->speak(); // Output: Speaking (Animal's speak, due to static binding)
    // If 'speak' was virtual, output would be Barking

    // Unsafe downcasting: casting Animal object to Dog pointer
    Dog *d = (Dog*) new Animal(); // Output: Animal constructor
    d->speak(); // Undefined behavior: calls Dog::speak() on Animal object (dangerous!)

    // Memory leak: No delete for new objects. In real code, delete pointers or use smart pointers.

    /*
    Better Alternative Approach (with virtual function):

    class Animal{
        public:
            Animal(){ cout<<"Animal constructor"<<endl; }
            virtual void speak(){ cout<<"Speaking"<<endl; }
            virtual ~Animal() {}
    };
    class Dog : public Animal{
        public:
            Dog(){ cout<<"Dog constructor"<<endl; }
            void speak() override { cout<<"Barking"<<endl; }
    };
    int main(){
        Animal *a = new Animal();
        a->speak(); // Speaking

        Dog *b = new Dog();
        b->speak(); // Barking

        Animal *c = new Dog();
        c->speak(); // Barking (dynamic binding due to virtual)

        // Avoid unsafe downcasting!
        // Dog *d = (Dog*) new Animal(); // Don't do this!
        // delete a; delete b; delete c;
        return 0;
    }
    */

    /*
    Dry Run:
    --------
    Animal *a = new Animal();
        - Animal constructor called
        - a->speak() => Speaking

    Dog *b = new Dog();
        - Animal constructor called
        - Dog constructor called
        - b->speak() => Barking

    Animal *c = new Dog();
        - Animal constructor called
        - Dog constructor called
        - c->speak() => Speaking (static binding, as 'speak' is not virtual)

    Dog *d = (Dog*) new Animal();
        - Animal constructor called
        - d->speak() => Barking (calls Dog::speak() on Animal object, undefined behavior!)
    */

    return 0;
}