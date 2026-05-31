#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    int W = 7;

    int wt[4] = {1, 3, 4, 5};
    int val[4] = {1, 4, 5, 7};

    int dp[5][8]={};

    // base case
    for (int w = 0; w <= W; w++) dp[0][w] = 0;

    // fill DP
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w) {
                dp[i][w] = max(dp[i][w],
                               val[i-1] + dp[i-1][w - wt[i-1]]);
            }
        }
    }

    cout << "Maximum value = " << dp[n][W] << endl;

    // 🔍 backtracking
    int w = W;
    cout << "Items taken (0-based indices): ";

    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i-1 << " ";
            w -= wt[i-1];
        }
    }

    cout << endl;
    return 0;
}