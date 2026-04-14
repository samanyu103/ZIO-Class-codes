#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];
    int b[n];
    rep(i,n) b[i] = a[n-i-1];
    rep(i,n) cout<<b[i]<<" ";
}