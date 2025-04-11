```cpp
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Function to compute optimal cost
int optimalBST(const vector<int>& keys, const vector<int>& freq) {
    int n = keys.size();
    // cost[i][j] stores the cost of optimal BST from keys[i] to keys[j]
    vector<vector<int>> cost(n, vector<int>(n, 0));

    // cost for a single key is the frequency of the key
    for (int i = 0; i < n; ++i)
        cost[i][i] = freq[i];

    // L is the chain length
    for (int L = 2; L <= n; ++L) {
        for (int i = 0; i <= n - L; ++i) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // sum of frequencies from i to j
            int sum = 0;
            for (int s = i; s <= j; ++s)
                sum += freq[s];

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; ++r) {
                int c = (r > i ? cost[i][r - 1] : 0) +
                        (r < j ? cost[r + 1][j] : 0) +
                        sum;
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};

    int minCost = optimalBST(keys, freq);
    cout << "Cost of Optimal BST is: " << minCost << endl;

    return 0;
}

```
Output:
```
142
```
Time complexity : O(n `sup` 3)
