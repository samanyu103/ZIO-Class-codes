#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int dp[MAXN][MAXN];

int maxCoins(int a[], int n) {
    // Create padded array
    int arr[n + 2];
    arr[0] = 1;
    arr[n + 1] = 1;
    for (int i = 1; i <= n; i++)
        arr[i] = a[i - 1];

    int N = n + 2;

    memset(dp, 0, sizeof(dp));

    // len = length of interval [i, j]
    for (int len = 3; len <= N; len++) {
        for (int i = 0; i + len - 1 < N; i++) {
            int j = i + len - 1;

            for (int k = i + 1; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k][j]
                         + arr[i] * arr[k] * arr[j];

                dp[i][j] = max(dp[i][j], cost);
            }
        }
    }

    return dp[0][N - 1];
}

int main() {
    int a[] = {3, 1, 5, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << maxCoins(a, n) << endl; // Output: 167
    return 0;
}

