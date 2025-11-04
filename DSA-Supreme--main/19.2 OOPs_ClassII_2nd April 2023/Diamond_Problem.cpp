#include<iostream>
using namespace std;

/*
Approach:
-----------
This code demonstrates the "Diamond Problem" in C++ multiple inheritance, where a derived class inherits from two base classes that both have a member with the same name.
To resolve ambiguity, scope resolution operator is used to specify which base class's member to access.

Key Points:
- Multiple inheritance can cause ambiguity if base classes have members with the same name.
- Scope resolution operator (::) is used to resolve ambiguity.
- This code does NOT use virtual inheritance, so both copies of 'chemistry' exist in class C.
*/

// Base class A
class A{
    public:
    int chemistry = 7; // Member variable 'chemistry' in class A
};

// Base class B
class B{
    public:
    int chemistry = 3; // Member variable 'chemistry' in class B
};

// Derived class C inherits from both A and B
class C : public A, public B{
    public:
    int maths = 4; // Member variable 'maths' in class C
};

int main(){
    C obj; // Create object of derived class C

    // Access 'chemistry' from class A using scope resolution to avoid ambiguity
    cout << obj.A::chemistry << endl; // Output: 7

    // Access 'chemistry' from class B using scope resolution to avoid ambiguity
    cout << obj.B::chemistry << endl; // Output: 3

    // Access 'maths' from class C directly
    cout << obj.maths << endl; // Output: 4

    return 0;
}

/*
-------------------------------
Better Alternative Approach:
-------------------------------
If the intention is to have only one copy of 'chemistry' in the derived class (i.e., to solve the diamond problem), use virtual inheritance:

class A{
    public:
    int chemistry = 7;
};
class B : virtual public A {};
class C : public B, virtual public A {
    public:
    int maths = 4;
};
int main(){
    C obj;
    cout << obj.chemistry << endl; // No ambiguity, only one 'chemistry'
    cout << obj.maths << endl;
    return 0;
}

-------------------------------
Dry Run:
-------------------------------
1. C obj; // Creates object 'obj' of class C. It contains:
   - A::chemistry = 7
   - B::chemistry = 3
   - maths = 4

2. cout << obj.A::chemistry << endl;
   // Accesses 'chemistry' from A, prints 7

3. cout << obj.B::chemistry << endl;
   // Accesses 'chemistry' from B, prints 3

4. cout << obj.maths << endl;
   // Accesses 'maths' from C, prints 4

Output:
7
3
4
*/