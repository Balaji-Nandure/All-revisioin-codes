#include<iostream>
using namespace std;

/*
Approach:
-----------
- Demonstrate the use of destructor in C++.
- Show both static and dynamic allocation of objects.
- Explain when destructors are called automatically and when they must be called manually (using delete).
- Add comments for clarity and provide a better alternative using smart pointers.
- Dry run at the end for better understanding.
*/

class Animal {
    int age; // Data member to store age of animal (not used here, but for demonstration)
public:
    // Destructor: called when object goes out of scope or is deleted
    ~Animal() { 
        cout << "Destructor called" << endl;
    }
};

int main() {
    // Static allocation: object 'suresh' is created on stack
    Animal suresh; // Destructor will be called automatically when 'suresh' goes out of scope (i.e., at end of main)

    // Dynamic allocation: object 'ramesh' is created on heap
    Animal *ramesh = new Animal; // Destructor will NOT be called automatically

    // Manually delete the dynamically allocated object to avoid memory leak
    delete ramesh; // Destructor is called for 'ramesh' here

    /*
    // BETTER ALTERNATIVE: Use smart pointers to manage memory automatically (C++11 and above)
    #include <memory>
    int main() {
        Animal suresh; // Static allocation as before

        // Using unique_ptr for dynamic allocation (no need to call delete)
        std::unique_ptr<Animal> ramesh = std::make_unique<Animal>();
        // Destructor will be called automatically when 'ramesh' goes out of scope

        return 0;
    }
    // This approach prevents memory leaks and is exception-safe.
    */

    return 0;
}

/*
Dry Run:
---------
1. main() starts.
2. 'suresh' (static) is created. Constructor (if defined) would be called.
3. 'ramesh' (dynamic) is created using new. Constructor (if defined) would be called.
4. delete ramesh; is called. Destructor for 'ramesh' is called, prints "Destructor called".
5. main() ends, 'suresh' goes out of scope. Destructor for 'suresh' is called, prints "Destructor called".
6. Program ends.

Output:
Destructor called   // for 'ramesh'
Destructor called   // for 'suresh'
*/