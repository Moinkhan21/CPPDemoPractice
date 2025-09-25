#include <iostream>
#include <vector>
using namespace std;

// Utility function to print one solution of the chessboard
// 'Q' means a queen is placed, '-' means empty cell
void printSolution(vector<vector<char>> &board, int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;  // Separate solutions with a blank line
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col, vector<vector<char>> &board, int n){

    int i = row;
    int j = col;

    // ✅ Check row on the left side
    // (since queens are placed column by column from left to right,
    // we only need to check the left side, not the right)
    while(j >= 0){
        if(board[i][j] == 'Q'){   // Another queen already in same row
            return false;
        }
        j--;
    }

    // ✅ Check upper-left diagonal
    i = row;
    j = col;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q'){   // Another queen on upper-left diagonal
            return false;
        }
        i--;
        j--;
    } 

    // ✅ Check bottom-left diagonal
    i = row;
    j = col;
    while(i < n && j >= 0){
        if(board[i][j] == 'Q') {  // Another queen on bottom-left diagonal
            return false;
        }
        i++;
        j--;
    }

    // If no conflict found, position is safe
    return true; 
}

// Recursive function to solve N-Queens problem
// col -> current column to place the queen
void solve(vector<vector<char>> &board, int col, int n) {
    // ✅ Base case:
    // If we placed queens in all columns, print the solution
    if(col >= n) {
        printSolution(board, n);
        return;
    }

    // ✅ Recursive case:
    // Try placing queen in every row of this column
    for(int row = 0; row < n; row++){
        // If it's safe to place queen at (row, col)
        if(isSafe(row, col, board, n)){
            // Place queen
            board[row][col] = 'Q';

            // Recurse to place queen in the next column
            solve(board, col + 1, n);

            // Backtrack: remove queen and try another row
            board[row][col] = '-';
        }
    }
}

int main() {
    int n = 4;  // Board size (N x N) and number of queens
    vector<vector<char>> board(n, vector<char>(n, '-'));

    // ' - ' -> empty cell
    // ' Q ' -> queen at the cell

    cout << "All possible solutions for " << n << "-Queens problem:" << endl << endl;
    solve(board, 0, n);

    return 0;
}
