/*
Approach Used:
---------------
- Demonstrate private inheritance in C++.
- Show that members of the base class become private in the derived class when using private inheritance.
- Attempt to access base class members from main() using derived class object, which will fail (commented out).
- Provide comments for each important line.
- Suggest better alternatives and approaches in comments.
- Provide a dry run at the end.

Better Alternatives:
--------------------
1. Use public inheritance if you want to access base class public members from derived class objects.
2. Use protected inheritance if you want derived class to access base class members, but not outside code.
3. Encapsulate data members and provide public/protected getter/setter methods for better encapsulation.
4. Demonstrate access via a public method in the derived class.

Below is the improved code with detailed comments and alternatives.
*/

#include<iostream>
using namespace std;

// Base class: Animal
class Animal{
    public:
        int age; // Public data member to store age

        // Public method to print eating action
        void eat(){
            cout<<"Eating"<<endl;
        }

        // Setter for age
        void setAge(int age){
            this->age = age;
        }

        // Getter for age
        void getAge(){
            cout<<"Age = "<<age<<endl;
        }
};

// Derived class: Dog inherits Animal privately
class Dog : private Animal{ // All public/protected members of Animal become private in Dog

    public:
        // Public method in Dog to set age using base class's setAge
        void setDogAge(int age){
            setAge(age); // Allowed: setAge is now private in Dog, but accessible within Dog
        }

        // Public method in Dog to get age using base class's getAge
        void showDogAge(){
            getAge(); // Allowed: getAge is now private in Dog, but accessible within Dog
        }

        // Public method in Dog to call eat
        void dogEat(){
            eat(); // Allowed: eat is now private in Dog, but accessible within Dog
        }
};

/*
Alternative Approach 1: (Recommended for most use-cases)
---------------------------------------------------------
If you want to allow access to base class public members from outside via derived class object, use public inheritance:

class Dog : public Animal {
    // Now, d1.eat(), d1.setAge(), d1.getAge() will work directly
};

Alternative Approach 2: (Encapsulation)
---------------------------------------
Make data members private and provide public/protected getter/setter methods.
*/

// Main function to demonstrate usage
int main(){
    Dog d1; // Create Dog object

    // d1.eat(); // Error: eat() is private in Dog due to private inheritance
    // d1.age;   // Error: age is private in Dog due to private inheritance

    // Correct way: Use Dog's public methods to access base class functionality
    d1.setDogAge(5);    // Sets age using Dog's public method
    d1.showDogAge();    // Prints age using Dog's public method
    d1.dogEat();        // Calls eat() using Dog's public method

    /*
    // If using public inheritance, you could do:
    Dog d2;
    d2.setAge(10);
    d2.getAge();
    d2.eat();
    */

    return 0;
}

/*
Dry Run:
--------
1. Dog d1 is created.
2. d1.setDogAge(5) calls Dog::setDogAge, which calls Animal::setAge(5), setting age to 5.
3. d1.showDogAge() calls Dog::showDogAge, which calls Animal::getAge(), printing "Age = 5".
4. d1.dogEat() calls Dog::dogEat, which calls Animal::eat(), printing "Eating".

Output:
Age = 5
Eating

Key Takeaway:
-------------
- With private inheritance, base class public/protected members become private in derived class.
- They are not accessible from outside via derived class object, but can be accessed within derived class methods.
- Use public inheritance for "is-a" relationships where you want to expose base class interface.
*/