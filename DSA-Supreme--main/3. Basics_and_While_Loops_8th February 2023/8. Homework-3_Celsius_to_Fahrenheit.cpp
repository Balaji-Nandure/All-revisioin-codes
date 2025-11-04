/*
Approach:
- The program converts a temperature given in Celsius to Fahrenheit.
- The conversion uses the formula: F = (9 * C) / 5 + 32, where C is the temperature in Celsius and F is the temperature in Fahrenheit.
- The result is printed to the console.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

// Function to convert Celsius to Fahrenheit
void convertToF(float temp){
    float F = (9 * temp) / 5 + 32; // Convert Celsius to Fahrenheit using the formula
    cout << "Temperature in fahrenheit is " << F << endl; // Output the result
}

int main(){
    float temp = 37.3; // Initialize temperature in Celsius
    convertToF(temp);  // Call the function to convert and print Fahrenheit
    return 0; // Indicate successful program termination
}

/*
Dry Run:
----------
temp = 37.3

Step 1: Call convertToF(37.3)
Step 2: F = (9 * 37.3) / 5 + 32
            = 335.7 / 5 + 32
            = 67.14 + 32
            = 99.14
Step 3: Print "Temperature in fahrenheit is 99.14"

Output:
Temperature in fahrenheit is 99.14
*/