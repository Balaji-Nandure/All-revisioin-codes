#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Check if it's safe to put a queen at (row, col)
bool isSafe(int row, int col, const vector<string> &board, int n) {
    for (int i = 0; i < row; i++) // check column
        if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i>=0 && j>=0; i--, j--) // upper-left diag
        if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i>=0 && j<n; i--, j++) // upper-right diag
        if (board[i][j] == 'Q') return false;
    return true;
}

void solve(int row, vector<string> &board, vector<vector<string>> &ans, int n) {
    if (row == n) { ans.push_back(board); return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col]='Q';
            solve(row+1, board, ans, n);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> nQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    auto sol = nQueens(n);
    cout << "Total solutions: " << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) {
        cout << "Solution " << i+1 << ":\n";
        for (auto &row : sol[i]) cout << row << '\n';
        cout << endl;
    }
    return 0;
}
