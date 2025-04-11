```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, vector<string> &board, int n) {
    int duprow = row;
    int dupcol = col;

    // Check upper-left diagonal
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // Check left
    row = duprow;
    col = dupcol;
    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    // Check lower-left diagonal
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

// Recursively solve the problem
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';  // Backtrack
        }
    }
}

// Function to start solving N-Queens
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}

// Main function
int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total Solutions: " << solutions.size() << "\n\n";

    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string &row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}

```
Output:
```
Enter the value of N: 4
Total Solutions: 2

Solution 1:
..Q.
Q...
...Q
.Q..

Solution 2:
.Q..
...Q
Q...
..Q.

```
T(N) = O(N!)
