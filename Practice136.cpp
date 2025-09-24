#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<vector<char>> &board, int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n){

    int i = row;
    int j = col;

    // Check row (left side)
    while(j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
    }

    // Check upper left diagonal
    i = row;
    j = col;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    } 

    // Check bottom left diagonal
    i = row;
    j = col;
    while(i < n && j >= 0){
        if(board[i][j] == 'Q') {
            return false;   // ✅ FIXED: should be false if queen found
        }
        i++;
        j--;
    }

    return true; // Safe to place queen
}

void solve(vector<vector<char>> &board, int col, int n) {
    // Base case: placed queens in all columns
    if(col >= n) {
        printSolution(board, n);
        return;
    }

    // Try placing queen in each row of this column
    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            // Place queen
            board[row][col] = 'Q';

            // Recurse for next column
            solve(board, col + 1, n);

            // Backtrack
            board[row][col] = '-';
        }
    }
}

int main() {
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));

    //' - ' -> empty cell
    //' Q ' -> Queen at the cell
    solve(board, 0, n);

    return 0;
}
