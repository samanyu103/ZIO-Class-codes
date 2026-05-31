#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 6;
    int a[n]  = {10, 7, 5, 8, 11, 9};
    int mn[n]= {};
    int profit[n] = {};
    mn[0] = a[0];
    for(int i = 1; i<n; i++) {
        mn[i] = min(a[i], mn[i-1]);
        profit[i] = a[i] - mn[i-1];
    }
    cout<<*max_element(profit, profit+n);
}