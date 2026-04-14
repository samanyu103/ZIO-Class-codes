#include <iostream>
using namespace std;

int main() {
    int H = 3, W = 3;

    // Example grid:
    // . . .
    // . # .
    // . . .
    char grid[3][3] = {
        {'.', '.', '.'},
        {'.', '#', '.'},
        {'.', '.', '.'}
    };

    int dp[3][3] = {}; // initialized to 0

    if (grid[0][0] == '.')
        dp[0][0] = 1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
            } else {
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl; // Output: 2

    return 0;
}