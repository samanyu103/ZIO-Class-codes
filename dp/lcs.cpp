#include <bits/stdc++.h>
using namespace std;

// LCS (Longest Common Subsequence) with reconstruction

int main() {
    string A = "aggtab";
    string B = "gxtxayb";

    int n = A.size(), m = B.size();

    // DP table
    int dp[n+1][m+1] = {};

    // Build DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct LCS
    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs.push_back(A[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    // Output
    cout << "Length: " << dp[n][m] << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}