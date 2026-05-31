#include<bits/stdc++.h>
using namespace std;
typedef int in;
#define int long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,n) for(int i = 0; i < n; i++)




void solve() {
    int n;
    cin>>n;
    int a[n][n];
    rep(i,n) rep(j,n) cin>>a[i][j];
    int level[n][n];
    rep(i,n) rep(j,n) level[i][j] = -1;
    level[0][0] = 0;
    queue<array<int, 2>> q;
    q.push({0,0});
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};
    while(!q.empty()) {
        array<int, 2> u = q.front();
        q.pop();
        rep(i,4) {
            array<int, 2> v = {u[0]+di[i], u[1]+dj[i]};
            if (v[0]>=0 and v[0]<n and v[1]>=0 and v[1]<n and a[v[0]][v[1]] and level[v[0]][v[1]] == -1) {
                level[v[0]][v[1]] = level[u[0]][u[1]]+1;
                q.push(v);
            }
        }
    }
    cout<<level[n-1][n-1]<<endl;
}
in main() {
    int tt=1;
    // cin>>tt;
    while(tt--) {
        solve();
    }
}