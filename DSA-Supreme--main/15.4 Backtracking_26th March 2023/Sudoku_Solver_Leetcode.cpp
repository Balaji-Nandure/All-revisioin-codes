/*
Approach Used:
---------------
This code uses the classic **Backtracking** approach to solve the Sudoku puzzle. The idea is to fill empty cells ('.') one by one, trying all possible digits ('1' to '9') in each cell, and recursively checking if the board can be solved with that choice. If a choice leads to a dead end, we backtrack (undo the choice) and try the next possibility.

Key Steps:
1. For each empty cell, try all digits from '1' to '9'.
2. For each digit, check if it is safe to place (i.e., not present in the same row, column, or 3x3 subgrid).
3. If safe, place the digit and recursively attempt to solve the rest of the board.
4. If the board cannot be solved with the current placement, backtrack (remove the digit) and try the next one.
5. If all cells are filled correctly, the board is solved.

Better Alternatives:
--------------------
- **Bitmasking**: Use bitmasks to efficiently check and update the presence of digits in rows, columns, and boxes. This reduces the time for isSafe checks.
- **Constraint Propagation (Dancing Links / Algorithm X)**: Advanced techniques like Dancing Links can solve Sudoku much faster, but are more complex to implement.
- **Heuristic Ordering**: Always fill the cell with the fewest possibilities first (Minimum Remaining Value heuristic) to reduce the search space.

Below is the improved code with detailed comments and a dry run at the end.
*/

class Solution {
public:
    // Function to check if placing 'value' at (curr_row, curr_col) is valid
    bool isSafe(char value, vector<vector<char>>& board, int curr_row, int curr_col) {
        // Check if 'value' already exists in the current row
        for (int col = 0; col < 9; col++) {
            if (board[curr_row][col] == value) {
                return false; // Not safe to place
            }
        }
        // Check if 'value' already exists in the current column
        for (int row = 0; row < 9; row++) {
            if (board[row][curr_col] == value) {
                return false; // Not safe to place
            }
        }
        // Check if 'value' already exists in the current 3x3 subgrid
        int startRow = 3 * (curr_row / 3);
        int startCol = 3 * (curr_col / 3);
        for (int i = 0; i < 9; i++) {
            int row = startRow + i / 3;
            int col = startCol + i % 3;
            if (board[row][col] == value) {
                return false; // Not safe to place
            }
        }
        // If 'value' is not found in row, column, or subgrid, it's safe to place
        return true;
    }

    // Recursive function to solve the Sudoku board using backtracking
    bool solve(vector<vector<char>>& board) {
        int n = board.size(); // Number of rows (should be 9)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell is empty
                if (board[i][j] == '.') {
                    // Try all possible digits from '1' to '9'
                    for (char value = '1'; value <= '9'; value++) {
                        // Check if it's safe to place 'value' at (i, j)
                        if (isSafe(value, board, i, j)) {
                            board[i][j] = value; // Place the digit
                            // Recursively try to solve the rest of the board
                            if (solve(board)) {
                                return true; // If solved, propagate success
                            }
                            // If not solved, backtrack (undo the placement)
                            board[i][j] = '.';
                        }
                    }
                    // If no digit can be placed in this cell, return false (trigger backtracking)
                    return false;
                }
            }
        }
        // If all cells are filled, the board is solved
        return true;
    }

    // Main function to be called to solve the Sudoku puzzle
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

/*
Alternative Efficient Approach (using bitmasking):
--------------------------------------------------
Uncomment and use this for better performance on large boards.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), col(9, 0), box(9, 0);
        vector<pair<int, int>> empty;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.')
                    empty.emplace_back(i, j);
                else {
                    int mask = 1 << (board[i][j] - '1');
                    row[i] |= mask;
                    col[j] |= mask;
                    box[(i/3)*3 + j/3] |= mask;
                }
        function<bool(int)> dfs = [&](int idx) {
            if (idx == empty.size()) return true;
            int i = empty[idx].first, j = empty[idx].second, b = (i/3)*3 + j/3;
            for (int d = 0; d < 9; ++d) {
                int mask = 1 << d;
                if (!(row[i] & mask) && !(col[j] & mask) && !(box[b] & mask)) {
                    board[i][j] = '1' + d;
                    row[i] |= mask; col[j] |= mask; box[b] |= mask;
                    if (dfs(idx+1)) return true;
                    row[i] ^= mask; col[j] ^= mask; box[b] ^= mask;
                    board[i][j] = '.';
                }
            }
            return false;
        };
        dfs(0);
    }
};

Dry Run Example:
----------------
Suppose the board has an empty cell at (0,2).
- The function finds (0,2) is empty.
- It tries '1', '2', ..., '9' in (0,2).
- Suppose '4' is safe, it places '4' and recursively solves the rest.
- If a later cell cannot be filled, it backtracks, removes '4', and tries the next digit.
- This continues until the board is solved or all options are exhausted.

Time Complexity: O(9^(n*n)), but in practice, pruning (isSafe) makes it much faster.
Space Complexity: O(1) extra (in-place), O(n^2) for recursion stack.

*/