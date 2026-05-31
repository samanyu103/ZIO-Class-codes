#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    int dp[n][n]={};  // VLA (works in GCC/Clang)

    // Base case: single characters
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Fill by increasing length
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s = "agbdba";
    cout << longestPalindromeSubseq(s) << endl; // Output: 5
    return 0;
}