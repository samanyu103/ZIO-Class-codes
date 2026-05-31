#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 6;
    int a[n] ={3, 2, 6, 5, 0, 3};
    int K = 2;
    int dp[n][K+1];
    rep(i,n) dp[i][0] = 0;
    for(int k=1; k<K+1; k++) {
        int m[n];
        for(int i = n-1; i>=0;i--) {
            m[i] = max(a[i] + dp[i][k-1], i+1<n?m[i+1]:INT_MIN);
            dp[i][k] = m[i]-a[i];
        }
        for(int i = n-2; i>=0; i--) dp[i][k] = max(dp[i][k], dp[i+1][k]);
        // rep(i,n) cout<<dp[i][k]<< " ";
        // cout<<endl;

    }
    cout<<dp[0][K]<<endl;
}