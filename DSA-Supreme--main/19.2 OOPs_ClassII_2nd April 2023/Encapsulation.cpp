/*
Approach Used:
---------------
- Demonstrate the concept of Encapsulation in C++ using a class `Animal`.
- Data member `age` is kept private to restrict direct access from outside the class.
- Public member functions (`setAge`, `getAge`, `eat`) are provided to interact with private data.
- This ensures data hiding and controlled access/modification.

Better Alternatives & Improvements:
-----------------------------------
1. Use getter function to return value instead of printing (for flexibility).
2. Add input validation in setter to prevent invalid age.
3. Use constructor for initialization.
4. Use `const` correctness for getter.
5. Demonstrate usage in `main()`.

Alternative Approach Example (in comments):

// class Animal {
//     private:
//         int age;
//     public:
//         Animal(int age = 0) { // Constructor with default value
//             setAge(age);
//         }
//         void eat() const {
//             cout << "Eating" << endl;
//         }
//         void setAge(int age) {
//             if(age >= 0) this->age = age; // Input validation
//             else cout << "Invalid age!" << endl;
//         }
//         int getAge() const { // Getter returns value
//             return age;
//         }
// };

*/

#include<iostream>
using namespace std;

// Class representing an Animal with encapsulated data
class Animal{
    // Data member is private to ensure encapsulation
    private:
        int age; // Age of the animal

    public:
        // Default constructor initializes age to 0
        Animal() : age(0) {}

        // Parameterized constructor for direct initialization
        Animal(int age) {
            setAge(age); // Use setter for validation
        }

        // Member function to simulate eating behavior
        void eat() const {
            cout << "Eating" << endl;
        }

        // Setter function to set the age with validation
        void setAge(int age){
            if(age >= 0) // Only allow non-negative ages
                this->age = age;
            else
                cout << "Invalid age! Age cannot be negative." << endl;
        }

        // Getter function to return the age (const correctness)
        int getAge() const {
            return age;
        }
};

int main(){
    // Create Animal object using default constructor
    Animal dog;
    // Set age using setter
    dog.setAge(5);
    // Get and print age using getter
    cout << "Age = " << dog.getAge() << endl;
    // Call eat function
    dog.eat();

    // Create Animal object using parameterized constructor
    Animal cat(-2); // Invalid age, will show error
    cat.setAge(3);
    cout << "Age = " << cat.getAge() << endl;
    cat.eat();

    return 0;
}

/*
Dry Run:
--------
1. dog is created with default constructor, age = 0.
2. dog.setAge(5) sets age to 5.
3. dog.getAge() returns 5, prints "Age = 5".
4. dog.eat() prints "Eating".
5. cat is created with parameterized constructor, age = -2 (invalid), prints error.
6. cat.setAge(3) sets age to 3.
7. cat.getAge() returns 3, prints "Age = 3".
8. cat.eat() prints "Eating".

Output:
Age = 5
Eating
Invalid age! Age cannot be negative.
Age = 3
Eating
*/

/*
Summary:
- Encapsulation is achieved by making data members private and providing public methods for access.
- Input validation and const correctness improve code safety and maintainability.
- Using getter to return value is more flexible than printing inside the class.
*/