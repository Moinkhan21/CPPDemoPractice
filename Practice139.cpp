#include <iostream>
#include <vector>
using namespace std;

/*
    Function: isSafe
    ----------------
    Checks if placing a given value (digit '1'..'9') in board[row][col] is valid
    according to Sudoku rules.

    Sudoku rules:
    1. Each row must contain digits 1..9 without repetition.
    2. Each column must contain digits 1..9 without repetition.
    3. Each 3x3 sub-grid must contain digits 1..9 without repetition.

    Parameters:
    - row, col: Current cell position
    - board: Current Sudoku board
    - value: The digit we want to place

    Returns:
    - true if the digit can be placed safely, false otherwise
*/
bool isSafe(int row, int col, const vector<vector<char>>& board, char value) {
    const int n = board.size(); // should be 9 for standard Sudoku

    for (int i = 0; i < n; ++i) {
        // ✅ Row check: value should not exist in the same row
        if (board[row][i] == value) return false;

        // ✅ Column check: value should not exist in the same column
        if (board[i][col] == value) return false;

        // ✅ 3x3 grid check: calculate the starting index of the sub-grid
        int boxRow = 3 * (row / 3) + i / 3; // Row inside subgrid
        int boxCol = 3 * (col / 3) + i % 3; // Column inside subgrid
        if (board[boxRow][boxCol] == value) return false;
    }
    return true; // Safe to place the value
}

/*
    Function: solve
    ---------------
    Recursive function that applies backtracking to fill the Sudoku board.

    Steps:
    1. Traverse the grid cell by cell.
    2. If an empty cell ('.') is found:
       - Try placing digits '1' to '9' one by one.
       - For each digit, check if it's safe using isSafe().
       - If safe, place the digit and recursively solve the rest of the board.
       - If recursion returns true, board is solved → propagate true.
       - If recursion fails, backtrack (reset cell to '.') and try next digit.
    3. If no empty cell is left, Sudoku is solved.

    Returns:
    - true if Sudoku is solved
    - false if no solution exists (should not happen for valid puzzles)
*/
bool solve(vector<vector<char>>& board) {
    int n = board.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // ✅ Find an empty cell
            if (board[i][j] == '.') {
                // Try placing digits '1' to '9'
                for (char val = '1'; val <= '9'; ++val) {
                    if (isSafe(i, j, board, val)) {
                        board[i][j] = val;                 // Place digit
                        if (solve(board)) return true;     // Recursive call
                        board[i][j] = '.';                // Backtrack (undo choice)
                    }
                }
                // If no valid digit found, backtrack
                return false;
            }
        }
    }

    // ✅ If loop finishes without finding '.', Sudoku is solved
    return true;
}

/*
    Function: solveSudoku
    ---------------------
    Wrapper function to call the recursive solver.
*/
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

int main() {
    // ✅ Initial Sudoku board ('.' means empty cell)
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // ✅ Solve the Sudoku
    solveSudoku(board);

    // ✅ Print the solved board
    cout << "Solved Sudoku Board:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << '\n';
    }

    return 0;
}
