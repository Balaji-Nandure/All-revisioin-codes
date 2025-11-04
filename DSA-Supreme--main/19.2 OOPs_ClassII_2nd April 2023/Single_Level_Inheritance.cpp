/*
Approach Used:
---------------
- Demonstrate Single Level Inheritance in C++.
- Create a base class 'Car' with some properties and methods.
- Create a derived class 'Rapid' that inherits from 'Car'.
- Show how to use inherited properties and methods in main().

Better Alternatives:
--------------------
1. Use constructor to initialize data members.
2. Use 'protected' access specifier for data members to allow derived class access but restrict outside access.
3. Use 'override' or 'virtual' functions if polymorphism is needed.
4. Use initialization lists for better performance.
5. Demonstrate usage of derived class object to access base class members.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include<iostream>
using namespace std;

// Base class representing a generic Car
class Car{
    protected: // Better than public for data members, allows derived class access but not outside
        string name;   // Name of the car
        int weight;    // Weight of the car
        int age;       // Age of the car

    public:
        // Constructor to initialize car properties
        Car(string n = "Unknown", int w = 0, int a = 0) : name(n), weight(w), age(a) {}

        // Method to simulate speeding up
        void speedup(){
            cout << name << " is speeding up." << endl;
        }

        // Method to simulate braking
        void brake(){
            cout << name << " is braking." << endl;
        }

        // Method to display car details
        void display(){
            cout << "Car Name: " << name << ", Weight: " << weight << "kg, Age: " << age << " years" << endl;
        }
};

// Derived class representing a specific car model 'Rapid'
class Rapid : public Car{
    public:
        // Constructor for Rapid, calls base class constructor
        Rapid(string n = "Rapid", int w = 1200, int a = 1) : Car(n, w, a) {}

        // You can add more features specific to Rapid here
        // For demonstration, let's override display (not necessary, but possible)
        void display(){
            cout << "[Rapid Model] ";
            Car::display(); // Call base class display
        }
};

int main(){
    // Create an object of Rapid
    Rapid myCar("Skoda Rapid", 1150, 2);

    // Display car details
    myCar.display(); // Shows details of the car

    // Call inherited methods
    myCar.speedup(); // Calls base class method
    myCar.brake();   // Calls base class method

    // Alternative: Create a generic Car object
    Car genericCar("Generic Car", 1000, 5);
    genericCar.display();
    genericCar.speedup();
    genericCar.brake();

    return 0;
}

/*
Dry Run:
--------
1. main() starts.
2. Rapid object 'myCar' is created with name="Skoda Rapid", weight=1150, age=2.
3. myCar.display() prints: [Rapid Model] Car Name: Skoda Rapid, Weight: 1150kg, Age: 2 years
4. myCar.speedup() prints: Skoda Rapid is speeding up.
5. myCar.brake() prints: Skoda Rapid is braking.
6. A generic Car object is created and its details and methods are shown similarly.
7. Program ends.

Alternative Approach Example (with virtual functions for polymorphism):
----------------------------------------------------------------------
class Car {
    // ... as above ...
    virtual void display() { ... }
};
class Rapid : public Car {
    void display() override { ... }
};
Car* c = new Rapid();
c->display(); // Calls Rapid's display due to virtual function
delete c;
*/