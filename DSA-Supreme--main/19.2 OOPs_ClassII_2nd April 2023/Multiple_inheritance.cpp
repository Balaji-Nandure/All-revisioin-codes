/*
Approach:
-----------
This code demonstrates the concept of Multiple Inheritance in C++. 
- We have three classes: A, B, and C.
- Class C inherits publicly from both A and B, thus acquiring their members.
- The main function creates an object of class C and accesses the inherited and its own members.

Better Alternatives:
---------------------
1. Use constructor initialization for better encapsulation and flexibility.
2. Use getter/setter methods to access private/protected members instead of public data members.
3. Use virtual inheritance if there is a possibility of diamond problem (not in this simple case).
4. Use struct if all members are public and no methods are needed (for simple data aggregation).

Alternative Example (with constructors and encapsulation):
----------------------------------------------------------
class A {
    int physics;
public:
    A(int p) : physics(p) {}
    int getPhysics() const { return physics; }
};
class B {
    int chemistry;
public:
    B(int c) : chemistry(c) {}
    int getChemistry() const { return chemistry; }
};
class C : public A, public B {
    int maths;
public:
    C(int p, int c, int m) : A(p), B(c), maths(m) {}
    int getMaths() const { return maths; }
};
int main() {
    C obj(2, 3, 4);
    cout << obj.getPhysics() << endl;
    cout << obj.getChemistry() << endl;
    cout << obj.getMaths() << endl;
    return 0;
}
----------------------------------------------------------

*/

// Including the iostream header for input/output operations
#include<iostream>
using namespace std;

// Class A represents a subject with a physics score
class A{
    public:
    int physics = 2; // public data member, initialized to 2
};

// Class B represents a subject with a chemistry score
class B{
    public:
    int chemistry = 3; // public data member, initialized to 3
};

// Class C inherits from both A and B, representing a student with all three subjects
class C : public A, public B{
    public:
    int maths = 4; // public data member, initialized to 4
};

int main(){
    C obj; // Creating object of class C, which has access to members of A, B, and C

    // Accessing and printing the physics score from class A
    cout << obj.physics << endl;

    // Accessing and printing the chemistry score from class B
    cout << obj.chemistry << endl;

    // Accessing and printing the maths score from class C
    cout << obj.maths << endl;

    return 0; // Indicating successful program termination
}

/*
Dry Run:
---------
1. obj.physics = 2 (from class A)
2. obj.chemistry = 3 (from class B)
3. obj.maths = 4 (from class C)
Output:
2
3
4

Key Points:
-----------
- Multiple inheritance allows class C to inherit members from both A and B.
- All data members are public, so they are directly accessible.
- For better design, use encapsulation (private/protected members with getters/setters).
- If both A and B had a member with the same name, ambiguity would arise (diamond problem), which can be solved using virtual inheritance.
*/