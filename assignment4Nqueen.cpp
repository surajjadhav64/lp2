#include <iostream>
using namespace std;

const int MAX = 10; // Maximum board size
int board[MAX][MAX];

// Check if it's safe to place a queen at (row, col)
bool isSafe(int row, int col, int n) {
    // Check left side
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1) return false;

    // Check upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    // Check lower diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1) return false;

    return true;
}

// Solve N-Queens problem using backtracking
bool solve(int col, int n) {
    if (col >= n) return true;

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;

            if (solve(col + 1, n)) return true;

            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

// Print the board
void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter board size : ";
    cin >> n;

    if (solve(0, n)) {
        cout << "One solution:\n";
        printBoard(n);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
