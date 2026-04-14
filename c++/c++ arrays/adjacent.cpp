#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];
    int cnt = 0;
    //note that we start from 1.
    // i and i-1 are adjacent pairs
    for(int i = 1; i<n;i++) if(abs(a[i] - a[i-1])==1) cnt++;
    cout<<cnt<<endl;
}