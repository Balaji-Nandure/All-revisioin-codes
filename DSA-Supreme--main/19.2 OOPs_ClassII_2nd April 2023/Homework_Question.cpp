/*
Approach:
----------
- The code demonstrates operator overloading for input (>>) and output (<<) operators for a user-defined class `Car`.
- This allows us to use `cin >> c1;` and `cout << c1;` directly for objects of Car, making the code more readable and idiomatic.
- Friend functions are used to access private members of the class for input/output.
- The code prompts the user for car details and then displays them.

Better Alternatives:
--------------------
1. Use constructor for initialization instead of only input operator.
2. Use setter/getter methods for better encapsulation.
3. Use std::getline for string input to handle spaces in car name/color.
4. Avoid using `cout` inside overloaded << operator; instead, only use the output stream.
5. Use const reference for output operator to avoid accidental modification.
6. Use initialization list in constructor for better performance.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include<iostream>
#include<string> // For using std::getline
using namespace std;

// Car class definition
class Car {
    // Private data members
    string name;
    int id;
    string color;
public:
    // Default constructor
    Car() : name(""), id(0), color("") {}

    // Parameterized constructor (Alternative approach)
    /*
    Car(const string& n, int i, const string& c) : name(n), id(i), color(c) {}
    */

    // Setter methods (Alternative approach)
    /*
    void setName(const string& n) { name = n; }
    void setId(int i) { id = i; }
    void setColor(const string& c) { color = c; }
    */

    // Getter methods (Alternative approach)
    /*
    string getName() const { return name; }
    int getId() const { return id; }
    string getColor() const { return color; }
    */

    // Friend function to overload >> operator for input
    friend istream& operator>>(istream& input, Car& c1);

    // Friend function to overload << operator for output
    friend ostream& operator<<(ostream& output, const Car& c1);
};

// Overloading >> operator for Car input
istream& operator>>(istream& input, Car& c1) {
    // Prompt user for car name
    cout << "Enter the name of the car: ";
    input.ignore(); // To clear the input buffer before getline
    getline(input, c1.name); // Allows spaces in name

    // Prompt user for car id
    cout << "Enter the id of the car: ";
    input >> c1.id;
    input.ignore(); // To clear the input buffer before getline

    // Prompt user for car color
    cout << "Enter the color of the car: ";
    getline(input, c1.color); // Allows spaces in color

    return input; // Return input stream for chaining
}

// Overloading << operator for Car output
ostream& operator<<(ostream& output, const Car& c1) {
    // Output car details in a formatted way
    output << "Name of car: " << c1.name << endl;
    output << "Id of car: " << c1.id << endl;
    output << "Color of car: " << c1.color << endl;
    return output; // Return output stream for chaining
}

int main() {
    Car c1; // Create Car object

    // Input car details using overloaded >> operator
    cin >> c1;

    // Output car details using overloaded << operator
    cout << c1;

    return 0;
}

/*
Alternative Approach Example (Using Setter/Getter):

int main() {
    Car c1;
    string name, color;
    int id;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter id: ";
    cin >> id;
    cin.ignore();
    cout << "Enter color: ";
    getline(cin, color);

    c1.setName(name);
    c1.setId(id);
    c1.setColor(color);

    cout << "Name: " << c1.getName() << endl;
    cout << "Id: " << c1.getId() << endl;
    cout << "Color: " << c1.getColor() << endl;
}

Dry Run:
---------
Suppose user enters:
    Name: Ford Mustang
    Id: 101
    Color: Red Metallic

Step-by-step:
1. Program prompts "Enter the name of the car: "
2. User enters "Ford Mustang"
3. Program prompts "Enter the id of the car: "
4. User enters "101"
5. Program prompts "Enter the color of the car: "
6. User enters "Red Metallic"
7. Program outputs:
    Name of car: Ford Mustang
    Id of car: 101
    Color of car: Red Metallic

Key Improvements:
-----------------
- Handles spaces in name and color.
- Uses only output stream in << operator (no extra cout).
- Uses const reference in << operator for safety.
- Comments explain logic and alternatives.
- Dry run provided for clarity.
*/