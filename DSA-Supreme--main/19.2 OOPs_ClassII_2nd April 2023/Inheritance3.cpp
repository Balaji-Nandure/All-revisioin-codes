/*
Approach Used:
---------------
- Demonstrate the concept of inheritance in C++ using a base class (Animal) and a derived class (Dog).
- Show how protected members are accessible in derived classes but not outside the class hierarchy.
- Illustrate encapsulation by using protected data members and member functions.
- Provide a function in the derived class to access protected data.
- Add comments for clarity and suggest better alternatives for encapsulation and access.

Better Alternative Approach:
---------------------------
- Use public getter and setter methods in the base class to access and modify protected/private members.
- This follows the best practice of encapsulation and data hiding.
- Demonstrate the use of constructors for initialization.
- Use 'override' keyword for virtual functions if polymorphism is needed (not shown here as not required).

Code with detailed comments and improvements:
*/

#include<iostream>
using namespace std;

// Base class representing a generic Animal
class Animal{
    protected:
        int age; // Protected member: accessible in derived classes

        // Protected method: only accessible within Animal and its derived classes
        void eat(){
            cout << "Eating" << endl;
        }

    public:
        // Public setter for age (encapsulation)
        void setAge(int age){
            this->age = age;
        }

        // Public getter for age (encapsulation)
        int getAge() const {
            return age;
        }

        // Public method to display age
        void displayAge() const {
            cout << "Age = " << age << endl;
        }
};

// Derived class representing a Dog, inheriting from Animal
class Dog : public Animal {
    public:
        // Public method to print the dog's age
        void print(){
            // Accessing protected member 'age' from base class
            cout << "Dog's Age (from print): " << this->age << endl;
        }

        // Public method to demonstrate calling a protected base class method
        void dogEat(){
            // Accessing protected method 'eat' from base class
            eat();
        }
};

int main(){
    Dog d1; // Create a Dog object

    // d1.eat(); // Error: 'eat' is protected in Animal, not accessible here

    // Set age using public setter (best practice)
    d1.setAge(5);

    // Print age using derived class method
    d1.print(); // Output: Dog's Age (from print): 5

    // Print age using base class public method
    d1.displayAge(); // Output: Age = 5

    // Demonstrate calling a protected method via a public method in derived class
    d1.dogEat(); // Output: Eating

    // Direct access to protected member is not allowed:
    // d1.age = 10; // Error

    return 0;
}

/*
Dry Run:
--------
1. Dog object d1 is created.
2. d1.setAge(5) sets the age of d1 to 5.
3. d1.print() prints "Dog's Age (from print): 5" by accessing protected member 'age'.
4. d1.displayAge() prints "Age = 5" using base class public method.
5. d1.dogEat() prints "Eating" by calling the protected method 'eat' via a public method in Dog.
6. Any direct access to 'age' or 'eat' from main() will result in a compilation error due to protection level.

Alternative Approach (in comments):
-----------------------------------
/*
class Animal {
    private:
        int age;
    public:
        void setAge(int age) { this->age = age; }
        int getAge() const { return age; }
};

class Dog : public Animal {
    public:
        void print() { cout << "Dog's Age: " << getAge() << endl; }
};
*/
// This approach uses private data members and public getter/setter for stricter encapsulation.