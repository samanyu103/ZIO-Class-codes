#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i<n; i++)
int main() {
    int n = 6;
    int a[n] = {9,32,53,2,4,6};
    // int pge[n] = {1, 2, -1, 4, 5, -1}
    stack<int>s;
    int nge[n];
    rep(i,n) nge[i] = -1;
    for(int i = n-1; i>=0; i--) {
        while(!s.empty() and a[s.top()]<= a[i]) s.pop();
        if(!s.empty()) nge[i] = s.top();
        s.push(i);
    }
    rep(i,n) cout<<nge[i]<<" ";
}