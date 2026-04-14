#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 8;
    int a[n] = {1,1,1,2,2,3,4,4};
    int target = 4;
    int l=0, r=n-1;
    int cnt=0;
    // we want different indices so l cannot be equal to r.
    while(l<r) {
        int s = a[l]+a[r];
        if (s==target) {
            cnt++;
            while(l<r and a[l+1] ==a[l])l++;
            while(l<r and a[r-1]==a[r])r--;
            l++;
            r--;
        }
        else if (s<target) l++;
        else r--;
    }
    cout<<cnt<<endl;
}