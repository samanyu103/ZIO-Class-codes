#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int n = 4;

    array<int,2> a[n] = {
        {1,5},
        {2,4},
        {5,6},
        {3,7}
    };

    array<int,2> v[2*n];

    rep(i,n) {
        v[2*i]   = {a[i][0], 1};
        v[2*i+1] = {a[i][1] + 1, -1};
    }

    sort(v, v + 2*n);

    int cur = 0, mx = 0;

    rep(i,2*n) {
        cur += v[i][1];
        mx = max(mx, cur);
    }

    cout << mx << '\n';
}