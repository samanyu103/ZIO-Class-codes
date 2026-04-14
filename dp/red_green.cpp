#include <iostream>
using namespace std;

int main() {
    int r, g;
    cin >> r >> g;

    int total = r + g;

    // compute max h such that h(h+1)/2 <= total
    int h = 0;
    while (h * (h + 1) / 2 <= total) h++;
    h--; // valid height

    int S = h * (h + 1) / 2;

    // dp[i][j] = ways to build i levels using j red blocks
    int dp[h + 1][r + 1] = {}; // initialized to 0

    // base case
    dp[0][0] = 1;

    for (int i = 1; i <= h; i++) {
        for (int j = 0; j <= r; j++) {

            // green
            dp[i][j] = dp[i - 1][j];

            // red
            if (j >= i) {
                dp[i][j] += dp[i - 1][j - i];
            }
        }
    }

    int ans = 0;

    for (int j = 0; j <= r; j++) {
        if (S - j <= g) {
            ans += dp[h][j];
        }
    }

    cout << ans << endl;

    return 0;
}