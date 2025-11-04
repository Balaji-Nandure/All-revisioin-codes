#include <iostream> // Include input-output stream
#include <vector>   // Include vector for 2D maze
#include <string>   // Include string for path recording
using namespace std; // Use standard namespace

// Recursive function to solve the maze
void solveMaze(int x, int y,
               vector<vector<int>> &maze,
               vector<vector<int>> &visited,
               string path,
               vector<string> &result) {

    int n = maze.size(); // Get maze size (assuming square)

    if (x < 0 || y < 0 || x >= n || y >= n) // Check if (x, y) is out of maze bounds
        return; // Return if out of bounds

    if (maze[x][y] == 0 || visited[x][y] == 1) // If cell is blocked or already visited
        return; // Don't proceed

    if (x == n - 1 && y == n - 1) { // If reach destination cell (bottom-right)
        result.push_back(path); // Add this path to result
        return; // Return as path is complete
    }

    visited[x][y] = 1; // Mark current cell as visited

    solveMaze(x + 1, y, maze, visited, path + 'D', result); // Move Down
    solveMaze(x, y - 1, maze, visited, path + 'L', result); // Move Left
    solveMaze(x, y + 1, maze, visited, path + 'R', result); // Move Right
    solveMaze(x - 1, y, maze, visited, path + 'U', result); // Move Up

    visited[x][y] = 0; // Backtrack: unmark current cell
}

// Function to find all possible paths in the maze
vector<string> findPaths(vector<vector<int>> &maze) {
    vector<string> result; // Stores all found paths
    int n = maze.size();   // Get maze size

    // If maze is empty or start/end is blocked, return empty result
    if (maze.empty() || maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
        return result;

    vector<vector<int>> visited(n, vector<int>(n, 0)); // Track visited cells

    solveMaze(0, 0, maze, visited, "", result); // Start search from (0,0) with empty path

    return result; // Return all found paths
}

int main() {
    // Hardcoded sample 7x7 maze (1=open cell, 0=blocked)
    vector<vector<int>> maze = {
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1}
    };

    vector<string> paths = findPaths(maze); // Find all paths from (0,0) to (n-1,n-1)

    if (paths.empty()) { // If no path is found
        cout << "No path found!" << endl; // Print no path message
    } else {
        cout << "All possible paths:" << endl; // Paths header
        for (const string& p : paths) { // Iterate through paths
            cout << p << endl; // Print each path
        }
    }

    return 0; // End of program
}
