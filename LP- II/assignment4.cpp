#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int cnt = 0;

void printBoard(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[j] == i)
                cout << "Q ";
            else
                cout << ". ";
//              cout<<board[j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int>& board, int col, int row) {
    cnt++;
    // Check this row if any queen already exists...
    for (int i = 0; i < col; ++i) {
        if (board[i] == row)
            return false;
    }

    //check for upper left diagonal
    for (int i = col, j = row; i >= 0 && j >= 0; --i, --j) {
        if (board[i] == j)
            return false;
    }

    //check for lower left diagonal
    for (int i = col, j = row; i >= 0 && j < board.size(); --i, ++j) {
        if (board[i] == j)
            return false;
    }
    
    return true;
}

void solveNQueensUtil(int n, int col, vector<int>& board, int& count) {
    if (col == n) {
        ++count;
        cout << "Solution " << count << ":\n";
        printBoard(board);
        return;
    }

    for (int row = 0; row < n; ++row) {
        if (isSafe(board, col, row)) {
            board[col] = row;
            solveNQueensUtil(n, col + 1, board, count);
            board[col] = -1; // backtrack
        }
    }
}

int solveNQueens(int n) {
    vector<int> board(n, -1);
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
