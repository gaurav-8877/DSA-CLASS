#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char num) {

    // Check row
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == num)
            return false;
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num)
            return false;
    }

    // Check 3 x 3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<char>>& board) {

    // Find an empty cell
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') {

                // Try numbers 1 to 9
                for (char num = '1'; num <= '9'; num++) {

                    if (isValid(board, i, j, num)) {

                        // Put number
                        board[i][j] = num;

                        // Recursively solve
                        if (solveSudoku(board))
                            return true;

                        // Backtrack
                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},

        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    // Print solved Sudoku
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}