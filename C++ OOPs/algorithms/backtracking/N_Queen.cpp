#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check upper rows, upper left diagonal, and upper right diagonal
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q' || (col - row + i >= 0 && board[i][col - row + i] == 'Q') ||
            (col + row - i < n && board[i][col + row - i] == 'Q')) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, vector<vector<string>>& solutions, vector<string>& board, int row) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(n, solutions, board, row + 1);
            board[row][col] = '.';  // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solveNQueens(n, solutions, board, 0);
    return solutions;
}

int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);
    cout << "Solutions for " << n << "-Queens problem:" << endl;
    for (const auto& solution : solutions) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
