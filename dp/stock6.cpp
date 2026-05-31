#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {

    // int n=5, a[n] = {1, 3, 4, 0, 2}, fee = 1; // 3
    int n = 6, a[n] = {1, 3, 2, 8, 4, 9}, fee = 2;
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
    int dp[n] = {};
    int m[n] = {};
    dp[n-1] = 0;
    m[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--) {
        dp[i] = -a[i]-fee + m[i+1];
        dp[i] = max(dp[i], dp[i+1]);
        m[i] = max(m[i+1], a[i] + dp[i]);
    }
    cout<<dp[0]<<endl;
}