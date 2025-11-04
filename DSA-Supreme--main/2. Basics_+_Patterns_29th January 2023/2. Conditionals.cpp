/*
Approach:
- Demonstrate different conditional constructs in C++: if, if-else, nested if-else, and if-else-if ladder.
- Read a `score` from the user and print messages based on threshold checks.
- Show that a standalone statement after an if-block runs regardless of the if condition.

Dry Run preview:
- Input: 280 -> prints messages where score < 300 conditions are true.
- Input: 360 -> falls into branches where score > 350 is true.
*/

#include<iostream> // Include I/O facilities (cout, cin, endl)
using namespace std; // Avoid std:: prefix for standard library names

int main(){ // Program entry point
    int score; // Declare the score variable
    cout << "Enter the score " << endl; // Prompt the user
    cin >> score; // Read score from standard input

    // If Statement (single if)
    if(score < 300){ // Check if score is less than 300
        cout << "India wins"; // Print when the condition is true
    } // End if(score < 300)
    cout << "Pak wins"; // This executes regardless of the previous if
    // Condition = True  -> prints: India winsPak wins
    // Condition = False -> prints: Pak wins

    // If-else (exactly one branch executes)
    if(score < 300){ // Condition check
        cout << "India wins"; // True branch
    } // End if
    else{ // False branch
        cout << "Pak wins"; // Executes only when score >= 300
    } // End else

    // Nested if-else (if inside else)
    if(score < 300){ // Outer condition
        cout << "India wins"; // True branch of outer if
    } // End outer if
    else{ // Outer else
        if(score > 350){ // Inner condition inside else
            cout << "Both may win"; // True branch of inner if
        } // End inner if
        else{ // Inner else
            cout << "Pak wins"; // Executes when 300 <= score <= 350
        } // End inner else
    } // End outer else

    // If - else if - else ladder (mutually exclusive checks)
    if(score < 300){ // First condition
        cout << "India wins"; // Executes when score < 300
    } // End first condition
    else if(score > 350){ // Second condition (evaluated only if first is false)
        cout << "Both may win"; // Executes when score > 350
    } // End else-if
    else{ // Final fallback branch
        cout << "Pak wins"; // Executes when 300 <= score <= 350
    } // End else

    return 0; // Indicate successful execution
}

/*
Dry Run:
Case 1: score = 280
- Single if: prints "India wins" (true), then always prints "Pak wins" -> India winsPak wins
- If-else: prints "India wins"
- Nested if-else: prints "India wins"
- Ladder: prints "India wins"

Case 2: score = 360
- Single if: condition false, prints only "Pak wins"
- If-else: prints "Pak wins"
- Nested if-else: outer if false; inner if true -> prints "Both may win"
- Ladder: first false, second true -> prints "Both may win"

Case 3: score = 320
- Single if: false -> prints only "Pak wins"
- If-else: prints "Pak wins"
- Nested if-else: outer if false; inner if (score > 350) false -> prints "Pak wins"
- Ladder: first false, second false -> prints "Pak wins"
*/