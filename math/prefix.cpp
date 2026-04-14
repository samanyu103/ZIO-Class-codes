#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n  = 6;
    int a[n] = {-2, 0, 3, -5, 2, -1};
    int p[n];
    p[0] = a[0];
    for(int i = 1 ; i< n; i++) p[i] = a[i] + p[i-1];
    // int l,r;
    // cin>>l>>r;
    // l--,r--;
    // int ans = p[r] - (l-1>=0?p[l-1]:0);
}