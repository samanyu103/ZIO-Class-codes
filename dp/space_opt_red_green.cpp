#include <iostream>
using namespace std;

int main() {
    int r, g;
    cin >> r >> g;

    int total = r + g;

    // compute maximum h
    int h = 0;
    while (h * (h + 1) / 2 <= total) h++;
    h--;

    int S = h * (h + 1) / 2;

    // dp[j] = number of ways using j red blocks
    int dp[r + 1] = {}; 
    dp[0] = 1;

    for (int i = 1; i <= h; i++) {
        // iterate backwards to avoid overwriting needed values
        for (int j = r; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }

    int ans = 0;

    for (int j = 0; j <= r; j++) {
        if (S - j <= g) {
            ans += dp[j];
        }
    }

    cout << ans << endl;

    return 0;
}