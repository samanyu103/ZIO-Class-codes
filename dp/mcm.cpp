#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int dp[MAXN][MAXN];

int matrixChainOrder(int dims[], int n) {
    // dp[i][j] = minimum cost to multiply Ai...Aj

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] 
                         + dims[i-1] * dims[k] * dims[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n];
}

int main() {
    int dims[] = {10, 20, 30, 40}; // 3 matrices
    int n = sizeof(dims)/sizeof(dims[0]) - 1;

    cout << matrixChainOrder(dims, n) << endl; // Output: 18000
    return 0;
}