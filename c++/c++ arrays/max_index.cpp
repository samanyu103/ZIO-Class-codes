#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i<n;i++)


int main() {
    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];
    int mx = INT_MIN, max_index = -1;
    rep(i,n) {
        if (a[i]>mx){
            mx = a[i];
            max_index = i;
        }
    }
    if (n==0) cout<<"empty array";
    else cout<<max_index;
    
}