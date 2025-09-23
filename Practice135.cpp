#include <iostream>
#include <vector>
using namespace std;

// ---------------- FUNCTION: isSafe ----------------
// Purpose: Check if the next cell (i, j) is safe to move into.
//
// Parameters:
//   i, j     -> current cell indices
//   row, col -> maze dimensions
//   arr[][3] -> maze matrix (1 = path, 0 = blocked)
//   visited  -> keeps track of already visited cells to avoid cycles
//
// Returns: true if (i, j) is inside the maze, not blocked, and not visited yet.
bool isSafe(int i, int j, int row, int col, int arr[][3], vector<vector<bool>> &visited){
    if(((i >= 0 && i < row) && (j >= 0 && j < col)) // inside maze boundaries
        && (arr[i][j] == 1)                         // cell is open (path = 1)
        && (visited[i][j] == false))                // not visited yet
    {
        return true;
    }
    else{
        return false;
    }
}

// ---------------- FUNCTION: solveMaze ----------------
// Purpose: Recursively explore all possible paths in the maze
// using backtracking and store valid paths from start (0,0)
// to destination (row-1, col-1).
//
// Parameters:
//   arr[3][3] -> maze grid
//   row, col  -> maze dimensions
//   i, j      -> current cell position
//   visited   -> 2D matrix tracking visited cells
//   path      -> vector to store all valid paths
//   output    -> current path string being built
//
// Approach:
//   - Base case: If destination is reached, save the path.
//   - Recursive exploration in 4 directions: Down, Left, Right, Up.
//   - Mark cell as visited before exploring, unmark (backtrack) after.
void solveMaze(int arr[3][3], int row, int col, int i, int j,
     vector<vector<bool>> &visited, vector<string>& path, string output){

        // ---------- BASE CASE ----------
        if(i == row - 1 && j == col - 1){
            // Destination reached → add path to results
            path.push_back(output);
            return;
        }

        // ---------- MOVE DOWN (i+1, j) ----------
        if(isSafe(i + 1, j , row, col, arr, visited)) {
            visited[i + 1][j] = true; // mark as visited
            solveMaze(arr, row, col, i + 1, j, visited, path, output + 'D');
            visited[i + 1][j] = false; // backtrack
        }

        // ---------- MOVE LEFT (i, j-1) ----------
        if(isSafe(i, j - 1 , row, col, arr, visited)) {
            visited[i][j - 1] = true;
            solveMaze(arr, row, col, i, j - 1, visited, path, output + 'L');
            visited[i][j - 1] = false; // backtrack
        }

        // ---------- MOVE RIGHT (i, j+1) ----------
        if(isSafe(i, j + 1 , row, col, arr, visited)) {
            visited[i][j + 1] = true;
            solveMaze(arr, row, col, i, j + 1, visited, path, output + 'R');
            visited[i][j + 1] = false; // backtrack
        }

        // ---------- MOVE UP (i-1, j) ----------
        if(isSafe(i - 1, j, row, col, arr, visited)) {
            visited[i - 1][j] = true;
            solveMaze(arr, row, col, i - 1, j, visited, path, output + 'U');
            visited[i - 1][j] = false; // backtrack
        }
}

int main(){
    // ---------- MAZE INPUT ----------
    // 1 = open path, 0 = blocked
    int maze[3][3] = {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1}
    };

    // If starting point is blocked, no path exists
    if(maze[0][0] == 0){
        cout << "No Path Exists" << endl;
        return 0;
    }

    int row = 3;
    int col = 3;

    // ---------- VISITED MATRIX ----------
    // Keeps track of visited cells to avoid revisiting same cell
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    visited[0][0] = true; // mark source cell (0,0) as visited

    // ---------- PATH STORAGE ----------
    vector<string> path; // stores all valid paths
    string output = "";  // current path string

    // ---------- FUNCTION CALL ----------
    solveMaze(maze, row, col, 0, 0, visited, path, output);

    // ---------- OUTPUT ----------
    cout << "Printing the results: " << endl;
    for(auto i: path) {
        cout << i << " ";
    }
    cout << endl;

    // If no path found
    if(path.size() == 0){
        cout << "No Path Exists" << endl;
    }

    return 0;
}
