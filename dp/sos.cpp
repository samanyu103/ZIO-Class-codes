#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        maxVal = max(maxVal, nums[i]);
    }

    // number of bits needed
    int B = 0;
    while ((1 << B) <= maxVal) B++;
    if (B == 0) B = 1;

    int N = 1 << B;

    // frequency array
    vector<int> f(N, 0);
    for (int x : nums) {
        f[x]++;
    }

    // -------- Subset SOS DP --------
    // sub[mask] = sum of f[s] for all s ⊆ mask
    vector<int> sub = f;
    for (int i = 0; i < B; i++) {
        for (int mask = 0; mask < N; mask++) {
            if (mask & (1 << i)) {
                sub[mask] += sub[mask ^ (1 << i)];
            }
        }
    }

    // -------- Superset SOS DP --------
    // sup[mask] = sum of f[s] for all s ⊇ mask
    vector<int> sup = f;
    for (int i = 0; i < B; i++) {
        for (int mask = 0; mask < N; mask++) {
            if (!(mask & (1 << i))) {
                sup[mask] += sup[mask | (1 << i)];
            }
        }
    }

    int ALL = N - 1;

    // -------- Answer queries --------
    for (int x : nums) {
        int count_or  = sub[x];                    // y ⊆ x  → x | y = x
        int count_and = sup[x];                    // y ⊇ x  → x & y = x
        int count_nonzero_and = n - sub[ALL ^ x];  // complement trick

        cout << count_or << " "
             << count_and << " "
             << count_nonzero_and << "\n";
    }

    return 0;
}