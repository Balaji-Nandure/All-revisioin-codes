#include<iostream>
using namespace std;

/*
Approach:
-----------
- Demonstrate multilevel inheritance in C++.
- Show how properties of a base class are accessible in a derived class through multiple levels.
- Use a real-world example: Fruit -> Mango -> Alphanso.
- Each class adds its own property.
- Access base class property from the most derived class object.

Better Alternatives:
--------------------
1. Use constructors to initialize member variables for better encapsulation.
2. Use private/protected access specifiers for data hiding and provide getter/setter methods.
3. Use initialization lists in constructors.
4. Demonstrate polymorphism or virtual functions for more advanced OOP concepts.

Alternative Example (with constructors and encapsulation):
----------------------------------------------------------
class Fruit {
    protected:
        string name;
    public:
        Fruit(string n = "Mango") : name(n) {}
        string getName() const { return name; }
};

class Mango : public Fruit {
    protected:
        int weight;
    public:
        Mango(string n = "Mango", int w = 0) : Fruit(n), weight(w) {}
        int getWeight() const { return weight; }
};

class Alphanso : public Mango {
    private:
        int sugarLevel;
    public:
        Alphanso(string n = "Mango", int w = 0, int s = 0) : Mango(n, w), sugarLevel(s) {}
        int getSugarLevel() const { return sugarLevel; }
};

int main() {
    Alphanso a("Alphanso", 200, 15);
    cout << a.getName() << " " << a.getWeight() << " " << a.getSugarLevel() << endl;
    return 0;
}
----------------------------------------------------------

Now, improved code with comments and dry run:
*/

class Fruit {
    public:
        string name = "Mango"; // Base class property: name of the fruit, default "Mango"
};

class Mango : public Fruit {
    public:
        int weight = 150; // Derived class property: weight of the mango, default 150g
};

class Alphanso : public Mango {
    public:
        int sugarLevel = 12; // Most derived class property: sugar level, default 12%
};

int main() {
    Alphanso a; // Create object 'a' of most derived class Alphanso

    // Accessing base class property 'name' using Alphanso object due to multilevel inheritance
    cout << "Fruit Name: " << a.name << endl;

    // Accessing Mango class property 'weight'
    cout << "Weight: " << a.weight << "g" << endl;

    // Accessing Alphanso class property 'sugarLevel'
    cout << "Sugar Level: " << a.sugarLevel << "%" << endl;

    return 0;
}

/*
Dry Run:
--------
1. Alphanso a; 
   - a.name = "Mango" (inherited from Fruit)
   - a.weight = 150 (inherited from Mango)
   - a.sugarLevel = 12 (from Alphanso)
2. cout << "Fruit Name: " << a.name << endl;
   - Output: Fruit Name: Mango
3. cout << "Weight: " << a.weight << "g" << endl;
   - Output: Weight: 150g
4. cout << "Sugar Level: " << a.sugarLevel << "%" << endl;
   - Output: Sugar Level: 12%

Output:
Fruit Name: Mango
Weight: 150g
Sugar Level: 12%
*/