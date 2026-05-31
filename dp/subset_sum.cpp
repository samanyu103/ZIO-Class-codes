#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n=4;
    int a[n] = {1,3,6,4};
    int S = 0;
    rep(i,n) S+=a[i];
    bool dp[S+1] = {};
    dp[0]=1;
    rep(i,n) {
        for(int s = S; s>=a[i];s--) {
            dp[s]|=dp[s-a[i]];
        }
    }
    rep(i,S) cout<<i<<" "<<dp[i]<<endl;
}