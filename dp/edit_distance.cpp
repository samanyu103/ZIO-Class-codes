#include <iostream>
#include <vector>
#include <string>
using namespace std;

int editDistance(string A, string B) {
    int n = A.size();
    int m = B.size();

    int dp[n + 1][m + 1];

    // base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    // fill dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int replace = dp[i - 1][j - 1] + 1;
                int del = dp[i - 1][j] + 1;
                int ins = dp[i][j - 1] + 1;

                dp[i][j] = min(replace, min(del, ins));
            }
        }
    }

    return dp[n][m];
}

int main() {
    string A = "love";
    string B = "movie";

    cout << editDistance(A, B) << endl; // Output: 2

    return 0;
}