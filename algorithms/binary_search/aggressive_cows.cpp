#include <bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();

    sort(stalls.begin(), stalls.end());

    int l = 1;
    int r = stalls[n - 1] - stalls[0] + 1;

    while (l < r) {
        int m = (l + r) / 2;

        int cnt = 1;
        int last = stalls[0];

        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= m) {
                cnt++;
                last = stalls[i];
            }
        }

        if (cnt >= k)
            l = m + 1;
        else
            r = m;
    }

    return l - 1;
}

int main() {
    int n = 5, k = 3;

    vector<int> stalls = {1, 2, 8, 4, 9};

    cout << aggressiveCows(stalls, k) << '\n';

    return 0;
}