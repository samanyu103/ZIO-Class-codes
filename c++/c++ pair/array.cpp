#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n;
    cin>>n;
    array<int,2> a[n];
    rep(i,n) cin>>a[i][1]>>a[i][0];
    sort(a,a+n);
    rep(i,n) cout<<a[i][1]<<" "<<a[i][0]<<endl;
}