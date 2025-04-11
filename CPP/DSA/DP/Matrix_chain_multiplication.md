# Memoization
Code:
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;

    for (int k = i; k < j; k++) {
        int steps = arr[i - 1] * arr[k] * arr[j]
                    + f(i, k, arr, dp)
                    + f(k + 1, j, arr, dp);
        if (steps < mini) mini = steps;
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N - 1, arr, dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    int N = arr.size();
    cout << matrixMultiplication(arr, N) << endl;
    return 0;
}

```
Tabulation
```cpp
#include <iostream>
#include <vector>
using namespace std;

int matrixMultiplication(vector<int> &arr, int N) {
    int dp[N][N];

    // Initializing diagonal values to 0 (cost of multiplying one matrix is 0)
    for (int i = 1; i < N; i++) 
        dp[i][i] = 0;

    // Bottom-up approach
    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 1; j < N; j++) {
            int mini = 1e9;
            for (int k = i; k < j; k++) {
                int steps = arr[i - 1] * arr[k] * arr[j]
                            + dp[i][k]
                            + dp[k + 1][j];
                if (steps < mini)
                    mini = steps;
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    int N = arr.size();

    cout << matrixMultiplication(arr, N) << endl;  // Output: 30
    return 0;
}

```
Brutch Force 
```
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(int i, int j, vector<int>& arr) {
    if (i == j) return 0;

    int mini = INT_MAX;

    for (int k = i; k < j; k++) {
        int steps = arr[i - 1] * arr[k] * arr[j]
                    + matrixChainOrder(i, k, arr)
                    + matrixChainOrder(k + 1, j, arr);
        if (steps < mini) mini = steps;
    }

    return mini;
}

int matrixMultiplication(vector<int>& arr, int N) {
    return matrixChainOrder(1, N - 1, arr);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    int N = arr.size();
    cout << matrixMultiplication(arr, N) << endl;
    return 0;
}

```
![image](https://github.com/user-attachments/assets/32199042-2e85-4441-825d-51b9eb851c2c)
