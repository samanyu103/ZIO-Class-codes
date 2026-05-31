#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    int W = 7;

    int wt[4] = {1, 3, 4, 5};
    int val[4] = {1, 4, 5, 7};

    int dp[5][8]={}; // dp[n+1][W+1]

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            // take previous value by default
            dp[i][w] = dp[i-1][w];
            // try taking item i if possible
            if (wt[i-1] <= w) {
                dp[i][w] = max(dp[i][w], val[i-1] + dp[i-1][w - wt[i-1]]);
            }
        }
    }

    cout << "Maximum value = " << dp[n][W] << endl;
    return 0;
}