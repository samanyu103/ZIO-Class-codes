#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    // int n = 5;
    // int a[n]= {1,2,3,0,2};
    int n = 6;
    int a[n] = {3,2,6,5,0,3};
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
    int dp[n] = {};
    int m[n] = {};
    dp[n-1] = 0;
    m[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--) {
        dp[i] = -a[i] + m[i+1];
        dp[i] = max(dp[i], dp[i+1]);
        m[i] = max(m[i+1], a[i] + (i+2<n?dp[i+2]:0));
    }
    cout<<dp[0]<<endl;
}