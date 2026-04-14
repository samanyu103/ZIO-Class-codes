#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n=4;
    int a[n] = {2,1,1,2};
    int dp[n]={};
    dp[0]=a[0];
    for(int i = 1; i<n;i++) {
        dp[i] = max(dp[i-1], a[i] + (i-2>=0?dp[i-2]:0));
    }
    cout<<dp[n-1]<<endl;
}