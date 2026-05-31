#include <bits/stdc++.h>
using namespace std;

// O(n log n) LIS with reconstruction using lower_bound

int main() {
    int n = 9;
    int a[n] = {10,9,2,5,2, 3,7,101,8};

    vector<int> tail;          // tail values
    vector<int> tail_idx;      // indices of tails
    vector<int> prev(n, -1);   // to reconstruct LIS

    for (int i = 0; i < n; i++) {
        int x = a[i];

        // find position using lower_bound
        int pos = lower_bound(tail.begin(), tail.end(), x) - tail.begin();

        if (pos == tail.size()) {
            tail.push_back(x);
            tail_idx.push_back(i);
        } else {
            tail[pos] = x;
            tail_idx[pos] = i;
        }

        // set prev pointer
        if (pos > 0) {
            prev[i] = tail_idx[pos - 1];
        }
    }

    // reconstruct LIS
    int len = tail.size();
    vector<int> lis;
    int idx = tail_idx[len - 1];

    while (idx != -1) {
        lis.push_back(a[idx]);
        idx = prev[idx];
    }

    reverse(lis.begin(), lis.end());

    // output
    cout << "Length: " << len << endl;
    cout << "LIS: ";
    for (int x : lis) cout << x << " ";
    cout << endl;

    return 0;
}