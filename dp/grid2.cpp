#include <iostream>
using namespace std;

int main() {
    int m = 3, n = 3;

    // Example grid:
    // 1 3 1
    // 1 5 1
    // 4 2 1
    int grid[3][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int dp[3][3];

    // base case
    dp[0][0] = grid[0][0];

    // first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // rest of grid
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << endl; // Output: 7

    return 0;
}