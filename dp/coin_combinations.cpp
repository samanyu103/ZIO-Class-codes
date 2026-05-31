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
    int n, X;
    cin>>n>>X;
    int a[n];
    rep(i,n) cin>>a[i];
    int dp[X+1] = {};

    dp[0]=1;

    // coin combinations 1
    for(int x = 1; x<=X; x++) {
        for(int i = 0; i < n; i++) {
            if (x-a[i]>=0)
                dp[x]+=dp[x-a[i]];
        }
    }
    // coin combinations 2 (ordered tuples)
    dp[0]=1;
    for(int i = 0; i < n; i++){
        for(int x = 1; x<=X; x++) {
            if (x-a[i]>=0)
                dp[x]+=dp[x-a[i]];
        }
    }
    cout<<dp[X];

}
in main() {
    int tt=1;
    cin>>tt;
    while(tt--) {
        solve();
    }
}