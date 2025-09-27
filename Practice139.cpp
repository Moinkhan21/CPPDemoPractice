#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, const vector<vector<char>>& board, char value) {
    const int n = board.size(); // should be 9 for standard Sudoku

    for (int i = 0; i < n; ++i) {
        // Row check
        if (board[row][i] == value) return false;

        // Column check
        if (board[i][col] == value) return false;

        // 3x3 grid check
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if (board[boxRow][boxCol] == value) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Find an empty cell
            if (board[i][j] == '.') {
                // Try digits 1..9
                for (char val = '1'; val <= '9'; ++val) {
                    if (isSafe(i, j, board, val)) {
                        board[i][j] = val;                 // Place
                        if (solve(board)) return true;     // If leads to solution, propagate true
                        board[i][j] = '.';                // Backtrack
                    }
                }
                // If no digit 1..9 works for this cell, backtrack to previous cell
                return false;
            }
        }
    }
    // No empty cells left => solved
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

int main() {
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

    solveSudoku(board);

    cout << "Solved Sudoku Board:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << '\n';
    }

    return 0;
}
