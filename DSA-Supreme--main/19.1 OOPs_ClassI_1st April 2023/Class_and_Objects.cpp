/*
Approach Used:
--------------
This code demonstrates the basics of Object-Oriented Programming (OOP) in C++ using classes and objects.
- It defines a class `Animal` with private and public members, encapsulating data and behavior.
- It shows how to use access modifiers, member functions (methods), getter/setter, and dynamic memory allocation for objects.
- The code also demonstrates the use of the `this` pointer to distinguish between member variables and parameters.

Better Alternatives & Detailed Approaches:
------------------------------------------
1. **Use of Constructors:**
   Instead of setting properties after object creation, use constructors to initialize objects.
   Example:
   ```
   class Animal {
       private:
           int weight;
       public:
           int age;
           string name;
           Animal(int age, string name, int weight) {
               this->age = age;
               this->name = name;
               this->weight = weight;
           }
           // ... (other methods)
   };
   Animal ramesh(12, "lion", 101);
   ```

2. **Use of Getter with Return Value:**
   Instead of printing inside getter, return the value for flexibility.
   ```
   int getWeight() const {
       return weight;
   }
   ```

3. **Use of Destructor:**
   If dynamic memory is used, define a destructor to release resources.

4. **Use of Const-Correctness:**
   Mark methods as `const` if they do not modify the object.

5. **Encapsulation:**
   Keep all data members private and use getter/setter for access.

6. **Use of Smart Pointers:**
   For dynamic allocation, prefer `std::unique_ptr` or `std::shared_ptr` to avoid memory leaks.

----------------------------------------------------------
*/

// Include input-output stream library
#include<iostream>
using namespace std;

// Class definition for Animal
class Animal {
    // Private data member: only accessible within class
    private:
        int weight; // Weight is encapsulated (hidden from outside)

    // Public members: accessible from outside the class
    public:
        int age;        // Age of the animal (public for demonstration)
        string name;    // Name of the animal (public for demonstration)

        // Default constructor (optional, but good practice)
        Animal() {
            age = 0;
            name = "";
            weight = 0;
        }

        // Parameterized constructor (better alternative)
        Animal(int age, string name, int weight) {
            this->age = age;
            this->name = name;
            this->weight = weight;
        }

        // Member function: Animal eats
        void eat() {
            cout << "I am eating";
        }

        // Member function: Animal sleeps
        void sleep() {
            cout << "I am sleeping";
        }

        // Setter for weight using 'this' pointer to distinguish member variable
        void setWeight(int weight) {
            this->weight = weight; // 'this->weight' refers to class member, 'weight' is parameter
        }

        // Getter for weight (returns value instead of printing, better practice)
        int getWeight() const {
            return weight;
        }

        // Print all details of the animal (utility function)
        void printDetails() const {
            cout << "Name: " << name << ", Age: " << age << ", Weight: " << weight << endl;
        }
};

// Main function: program execution starts here
int main() {
    // Object creation using default constructor
    Animal ramesh; // 'ramesh' is an object of class Animal

    // Setting properties of object using direct access (not recommended for real encapsulation)
    ramesh.age = 12;
    ramesh.name = "lion";
    ramesh.setWeight(101); // Set weight using setter

    // Output the properties
    cout << ramesh.age << " " << ramesh.name << endl; // Prints: 12 lion

    // Call member function 'eat'
    ramesh.eat(); // Prints: I am eating
    cout << endl;

    // Get and print weight using getter
    cout << "Weight: " << ramesh.getWeight() << endl; // Prints: Weight: 101

    // Print all details using utility function
    ramesh.printDetails(); // Prints: Name: lion, Age: 12, Weight: 101

    // Dynamic memory allocation for object (on heap)
    Animal *suresh = new Animal; // Allocates memory for Animal object and returns pointer

    // Setting properties using pointer (dot operator with dereference)
    (*suresh).age = 15;
    (*suresh).name = "billi";
    suresh->setWeight(55); // Set weight using arrow operator

    // Alternative: using arrow operator (preferred for pointers)
    suresh->name = "sher";
    suresh->age = 16;
    suresh->setWeight(77);

    // Call member function using pointer
    suresh->eat(); // Prints: I am eating
    cout << endl;

    // Print all details of suresh
    suresh->printDetails(); // Prints: Name: sher, Age: 16, Weight: 77

    // Free dynamically allocated memory (good practice)
    delete suresh;

    return 0;
}
