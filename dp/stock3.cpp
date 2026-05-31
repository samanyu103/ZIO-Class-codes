#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 6;
    int a[n] = {4, 2, 7, 1, 11, 5};
    int sm[n] = {};
    // suffix maximum
    sm[n-1] = a[n-1];
    for(int i = n-2; i>=0;i--) sm[i] = max(a[i], sm[i+1]);
    // buy on day i and sell later
    int dp1[n]= {};
    rep(i,n) dp1[i] = -a[i]+sm[i];
    
    // buy on/after day i
    int dpm[n] = {};
    dpm[n-1]=dp1[n-1];
    for(int i = n-2; i>=0;i--) dpm[i] = max(dp1[i], dpm[i+1]);

    // sell first stock on/after day i
    int x[n] = {};
    x[n-1] = a[n-1]+dpm[n-1];
    for(int i = n-2; i>=0;i--) x[i] = max(a[i] + dpm[i], x[i+1]);

    // buy first stock on day i.
    int ans[n] = {};
    rep(i,n) {
        ans[i] = -a[i]+x[i];
    }

    cout<<*max_element(ans, ans+n);




}