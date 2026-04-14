#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    rep(i,n) rep(j,m) cin>>a[i][j]; // without {} only one line is considered as part of the loop.
    int sum = 0;
    rep(i,n) sum+=a[i][0];
    rep(i,n) sum+=a[i][m-1];
    rep(j,m) sum+=a[0][j];
    rep(j,m) sum+=a[n-1][j];
    sum = sum - a[0][0] - a[0][m-1] - a[n-1][0] - a[n-1][m-1];
    cout<<sum<<endl;
}