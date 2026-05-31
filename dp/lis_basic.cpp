#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 6;
    int a[n] = {4, 1, 6, 2, 3, 7};
    int dp[n] = {};
    int prev[n];
    rep(i,n) {
        dp[i]=1;
        prev[i]=-1;
        rep(j,i) {
            if(a[j]<a[i]) {
                // dp[i] = max(dp[i], dp[j]+1);
                if (dp[j]+1>dp[i]) {
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }
        }
    }
    cout<<*max_element(dp, dp+n)<<endl;

    // backtracking
    vi lis;
    int ind = max_element(dp, dp+n)-dp;
    while(~ind) {
        lis.pb(ind);
        ind = prev[ind];
    }
    reverse(lis.begin(), lis.end());
    for(int i: lis) cout<<a[i]<<" ";
    cout<<endl;
}