/*
Approach:
-----------
- The goal is to determine the grade of a student based on their marks using a function in C++.
- We'll define a function 'grade' that takes marks as input and returns the corresponding grade as a character.
- The function uses if-else conditions to check the range of marks and returns the appropriate grade.
- In main, we'll initialize marks, call the function, and print the grade.
*/

#include<iostream> // Include input-output stream for cout
using namespace std; // Use standard namespace to avoid std:: prefix

// Function to determine grade based on marks
char grade(int marks){
    // If marks are 90 or above, return 'A'
    if(marks >= 90){
        return 'A';
    }
    // If marks are 80 or above (but less than 90), return 'B'
    else if(marks >= 80){
        return 'B';
    }
    // If marks are 70 or above (but less than 80), return 'C'
    else if(marks >= 70){
        return 'C';
    }
    // If marks are 60 or above (but less than 70), return 'D'
    else if(marks >= 60){
        return 'D';
    }
    // If marks are less than 60, return 'E'
    else{
        return 'E';
    }
}

int main(){
    int marks = 95; // Initialize marks with value 95
    cout << grade(marks); // Call grade function and print the returned grade
    return 0; // Indicate successful program termination
}

/*
Dry Run:
-----------
marks = 95

Step 1: main() starts.
Step 2: marks is set to 95.
Step 3: grade(95) is called.
    - 95 >= 90 is true, so return 'A'
Step 4: cout prints 'A'
Step 5: main returns 0, program ends.

Output:
A
*/