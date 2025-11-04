/*
Approach:
- The program converts a distance given in kilometers to miles.
- The conversion is done using the formula: miles = kilometers / 1.609.
- The result is then printed to the console.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){
    float dist_km = 31; // Initialize distance in kilometers

    // Convert kilometers to miles using the conversion factor (1 mile = 1.609 km)
    float dist_mile = dist_km / 1.609; // Calculate distance in miles

    cout << dist_mile << endl; // Output the distance in miles

    return 0; // Indicate successful program termination
}

/*
Dry Run:
----------
dist_km = 31

Step 1: Calculate dist_mile
        dist_mile = dist_km / 1.609
        dist_mile = 31 / 1.609 ≈ 19.26

Step 2: Print dist_mile
        Output: 19.26
*/