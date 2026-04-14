#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 5;
    int c[n] = {4,2,5,2,3};
    int dp[n+1]={};
    for(int i = 2; i<=n; i++) dp[i] = min(dp[i-1]+c[i-1], dp[i-2]+c[i-2]);
    cout<<dp[n]<<endl;
}