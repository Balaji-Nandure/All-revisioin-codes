/*
Approach:
-----------
- Demonstrate the concept of inheritance in C++ using a base class (Animal) and a derived class (Dog).
- Show how protected members are accessible in derived classes but not outside the class hierarchy.
- Illustrate encapsulation by providing setter and getter methods for the protected member.
- Provide comments for all important lines and logic.
- Suggest and show a better alternative approach using public getter/setter for better encapsulation.
- Dry run is provided at the end.

*/

#include<iostream>
using namespace std;

// Base class representing a generic Animal
class Animal{
    protected:
        int age; // Protected member: accessible in derived classes, not outside

        // Protected method: only accessible within Animal and its derived classes
        void eat(){
            cout<<"Eating"<<endl;
        }

        // Setter for age (protected): can be used by derived classes
        void setAge(int age){
            this->age = age;
        }

        // Getter for age (protected): can be used by derived classes
        void getAge(){
            cout<<"Age = "<<age<<endl;
        }
};

// Derived class representing a Dog, inherits from Animal
class Dog: public Animal{
    public:
        // Public method to print the age of the dog
        void print(){
            cout<<"Dog's Age (accessed via protected member): "<<this->age<<endl; // Accessing protected member
        }

        // Public method to set age using base class's protected setter
        void setDogAge(int a){
            setAge(a); // Using base class's protected setter
        }

        // Public method to show eating behavior using base class's protected method
        void showEat(){
            eat(); // Accessing protected method from base class
        }

        // Public method to get age using base class's protected getter
        void showAge(){
            getAge(); // Accessing protected getter
        }
};

int main(){
    Dog d1; // Create Dog object

    // d1.eat(); // ERROR: Cannot access protected method from outside the class

    // d1.age = 5; // ERROR: Cannot access protected member from outside

    d1.setDogAge(5); // Set age using public method (good practice)
    d1.print();      // Print age using public method

    d1.showEat();    // Show eating behavior using public method

    d1.showAge();    // Show age using public method

    return 0;
}

/*
-------------------------------
Better Alternative Approach:
-------------------------------
- For better encapsulation, make data members private and provide public getter/setter methods.
- This prevents accidental modification and enforces controlled access.

Example:
--------------------------------
class Animal{
    private:
        int age;
    public:
        void setAge(int age){
            this->age = age;
        }
        int getAge(){
            return age;
        }
        void eat(){
            cout<<"Eating"<<endl;
        }
};

class Dog: public Animal{
    public:
        void print(){
            cout<<"Dog's Age: "<<getAge()<<endl;
        }
};

int main(){
    Dog d1;
    d1.setAge(7);
    d1.print();
    d1.eat();
    return 0;
}
--------------------------------

Advantages:
- Data hiding is enforced.
- Only intended interfaces are exposed to the user.
- Reduces risk of accidental misuse.

-------------------------------
Dry Run:
-------------------------------
1. Dog d1; // Creates a Dog object.
2. d1.setDogAge(5); // Sets age to 5 using public method (calls base class's protected setter).
3. d1.print(); // Prints: Dog's Age (accessed via protected member): 5
4. d1.showEat(); // Prints: Eating
5. d1.showAge(); // Prints: Age = 5