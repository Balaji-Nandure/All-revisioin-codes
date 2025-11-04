/*
Approach:
-----------
This code demonstrates the three types of constructors in C++:
1. Default Constructor: Initializes object with default values.
2. Parameterized Constructor: Initializes object with user-provided values.
3. Copy Constructor: Initializes a new object as a copy of an existing object.

Improvements:
-------------
- Initialize member variable 'age' with a default value in the default constructor.
- Fix the copy constructor to correctly copy the 'age' from the source object.
- Add a getter function to access 'age' for demonstration.
- Add comments explaining each important line.
- Print the value of 'age' after each object creation for clarity.
- Suggest a better alternative using member initializer lists and 'const' correctness in the copy constructor.
- Add a dry run at the end as a comment.

*/

#include<iostream>
using namespace std;

// Class representing an Animal with an 'age' attribute
class Animal{
    int age; // Private data member to store age

    public:
    // Default constructor: initializes age to 0
    Animal(){
        age = 0; // Set default age
        cout << "Default constructor called. Age set to " << age << endl;
    }

    // Parameterized constructor: initializes age to the given value
    Animal(int age){
        this->age = age; // Assign parameter value to member variable
        cout << "Parameterized constructor called. Age set to " << this->age << endl;
    }

    // Copy constructor: creates a new object as a copy of an existing object
    Animal(const Animal& obj){ // Use 'const' for safety
        this->age = obj.age; // Correctly copy the age from the source object
        cout << "Copy constructor called. Age set to " << this->age << endl;
    }

    // Getter function to access age
    int getAge() const {
        return age;
    }
};

int main(){
    // Creating object 'suresh' using default constructor
    Animal suresh; 
    cout << "suresh.age = " << suresh.getAge() << endl;

    // Creating object 'ramesh' using parameterized constructor
    Animal ramesh(30); 
    cout << "ramesh.age = " << ramesh.getAge() << endl;

    // Creating object 'copy' using copy constructor (copying 'suresh')
    Animal copy(suresh); 
    cout << "copy.age = " << copy.getAge() << endl;

    return 0;
}

/*
-------------------------------
Better Alternative Approach:
-------------------------------
- Use member initializer lists for constructors for better performance and clarity.
- Always pass the source object as 'const Animal&' in the copy constructor to avoid accidental modification.

class Animal{
    int age;
    public:
    Animal() : age(0) {
        cout << "Default constructor called. Age set to " << age << endl;
    }
    Animal(int age) : age(age) {
        cout << "Parameterized constructor called. Age set to " << this->age << endl;
    }
    Animal(const Animal& obj) : age(obj.age) {
        cout << "Copy constructor called. Age set to " << this->age << endl;
    }
    int getAge() const { return age; }
};

-------------------------------
Dry Run:
-------------------------------
1. Animal suresh;
   - Calls default constructor.
   - age = 0
   - Output: "Default constructor called. Age set to 0"
   - Output: "suresh.age = 0"

2. Animal ramesh(30);
   - Calls parameterized constructor.
   - age = 30
   - Output: "Parameterized constructor called. Age set to 30"
   - Output: "ramesh.age = 30"

3. Animal copy(suresh);
   - Calls copy constructor, copies age from suresh (which is 0)
   - age = 0
   - Output: "Copy constructor called. Age set to 0"
   - Output: "copy.age = 0"
*/