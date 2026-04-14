#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n, t;
    cin>>n>>t;
    int a[n];
    rep(i,n) cin>>a[i];
    map<int,int> m;
    bool found=0;
    rep(i,n) {
        if (m[t-a[i]]) found=1;
        m[a[i]]++;
    } 
    cout<<found?"YES\n":"NO\n";

}