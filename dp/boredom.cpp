#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 5;
    int a[n] = {2,3,2,1,5};
    int M = *max_element(a,a+n);
    // important to set it to 0.
    int cnt[M+1]={};
    rep(i,n) cnt[a[i]]++;

    int dp[M+1]={};
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2; i<=M; i++) {
        int take = dp[i-2] + i*cnt[i];
        int skip = dp[i-1];
        dp[i] = max(take, skip);
    }
    // rep(i,M+1) cout<<dp[i]<< " ";cout<<endl;
    cout<<dp[M]<<endl;
    
}