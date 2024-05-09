#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int cnt = 0;

void printBoard(const vector<vector<int>>board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
//              cout<<board[j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, const vector<vector<int>> &board) {
    cnt++;
    // Check this row if any queen already exists...
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1)
            return false;
    }

    //check for upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1)
            return false;
    }

    //check for lower left diagonal
    for (int i = row, j = col; j >= 0 && i < board.size(); i++, j--) {
        if (board[i][j] == 1)
            return false;
    }
    
    return true;
}

void solveNQueensUtil(int n, int col,vector<vector<int>>board, int& count) {
    if (col == n) {
        ++count;
        cout << "Solution " << count << ":\n";
        printBoard(board);
        return;
    }

    for (int row = 0; row < n; ++row) {
        if (isSafe(row,col,board)) {
            board[row][col] = 1;
            solveNQueensUtil(n, col + 1, board, count);
            board[row][col] = 0; // backtrack
        }
    }
}

int solveNQueens(int n) {
    vector<vector<int>>board(n,vector<int>(n,0));
    int count = 0;
    solveNQueensUtil(n, 0, board, count);
    return count;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    int solutions = solveNQueens(n);
    cout << "Number of solutions for " << n << " queens: " << solutions << endl;

//    cout << "Number of times isSafe() is called: " << cnt << endl;
    return 0;
}
