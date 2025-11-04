#include <iostream> // For input/output streams
#include <vector> // For using vectors (dynamic arrays)
#include <string> // For using the string class
#include <unordered_map> // For using hash maps (unordered_map)
using namespace std; // To avoid std:: prefix

// -----------------------------------------------------------
// Recursive function to solve N-Queens using unordered_map
// -----------------------------------------------------------
void solve(
    int col, // Current column to place queen
    int n, // Size of chessboard (n x n)
    vector<string> &board, // Current board configuration
    vector<vector<string>> &ans, // Stores all solutions
    unordered_map<int, bool> &rowCheck, // Checks if row is occupied
    unordered_map<int, bool> &upperLeftDiagCheck, // Checks ↖ diagonal attacks
    unordered_map<int, bool> &bottomLeftDiagCheck // Checks ↙ diagonal attacks
) {

    // ✅ Base case: all queens are placed
    if (col == n) { // If all columns done
        ans.push_back(board); // Store current configuration as one solution
        return; // Stop recursion for this branch
    }

    // Try placing queen in each row of this column
    for (int row = 0; row < n; row++) { // Iterate all rows for current column
        // Calculate unique diagonal indices
        int upperLeftIndex = n - 1 + col - row; // Index for upper left diagonal (↖)
        int bottomLeftIndex = row + col;        // Index for bottom left diagonal (↙)

        // Check if this position is safe in O(1)
        if (
            !rowCheck[row] // Check if row not attacked
            && !upperLeftDiagCheck[upperLeftIndex] // Check ↖ diagonal not attacked
            && !bottomLeftDiagCheck[bottomLeftIndex] // Check ↙ diagonal not attacked
        ) {

            // ✅ Place queen
            board[row][col] = 'Q'; // Place queen at (row, col)
            rowCheck[row] = true; // Mark row as attacked
            upperLeftDiagCheck[upperLeftIndex] = true; // Mark upper left diagonal as attacked
            bottomLeftDiagCheck[bottomLeftIndex] = true; // Mark bottom left diagonal as attacked

            // Move to next column
            solve(col + 1, n, board, ans, rowCheck, upperLeftDiagCheck, bottomLeftDiagCheck); // Recursive call

            // ♻️ Backtrack
            board[row][col] = '.'; // Remove the queen (reset spot)
            rowCheck[row] = false; // Unmark row
            upperLeftDiagCheck[upperLeftIndex] = false; // Unmark upper left diagonal
            bottomLeftDiagCheck[bottomLeftIndex] = false; // Unmark bottom left diagonal
        }
    }
}

// -----------------------------------------------------------
// Function to initialize board and helper maps
// -----------------------------------------------------------
vector<vector<string>> nQueens(int n) {
    vector<vector<string>> ans; // Stores all valid solutions
    vector<string> board(n, string(n, '.')); // Create n x n board (all empty)

    // Mappings to mark attacked rows/diagonals
    unordered_map<int, bool> rowCheck; // Keeps track of attacked rows
    unordered_map<int, bool> upperLeftDiagCheck; // Keeps track ↖ diagonals
    unordered_map<int, bool> bottomLeftDiagCheck; // Keeps track ↙ diagonals

    // Start recursion from first column
    solve(0, n, board, ans, rowCheck, upperLeftDiagCheck, bottomLeftDiagCheck); // Begin solving

    return ans; // Return solutions
}

// -----------------------------------------------------------
// Main function
// -----------------------------------------------------------
int main() {
    int n; // To hold value of N
    cout << "Enter N: "; // Ask user for N
    cin >> n; // Take user input

    auto solutions = nQueens(n); // Get all solutions for N

    cout << "Total solutions: " << solutions.size() << endl << endl; // Print number of solutions
    for (int i = 0; i < solutions.size(); i++) { // For each solution
        cout << "Solution " << i + 1 << ":\n"; // Print solution number
        for (auto &row : solutions[i]) // Print each row of the board
            cout << row << endl;
        cout << endl; // Blank line between solutions
    }

    return 0; // Program end
}
