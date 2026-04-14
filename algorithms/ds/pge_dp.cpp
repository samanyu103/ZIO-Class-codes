#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 7;
    int a[n] = {1,4,2,3,2,1,4};
    // int pge[n] = {-1,-1,1, 1, 3, 4, -1};
    stack<int> s;
    int pge[n];
    rep(i,n) pge[i]=-1;
    rep(i,n) {
        int t = i-1;
        while(t>=0 and a[t]<=a[i]) t=pge[t];
        pge[i]=t;
    }
    rep(i,n) cout<<pge[i]<< " ";
}