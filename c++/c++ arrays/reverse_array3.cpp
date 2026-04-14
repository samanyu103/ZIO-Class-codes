#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];
    reverse(a,a+n);
    rep(i,n) cout<<a[i]<<" ";
}