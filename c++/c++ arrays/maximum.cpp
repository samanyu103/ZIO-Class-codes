#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 5;
    int a[n] = {1,4,3,2,3};
    int ans = INT_MIN;
    rep(i,n) {
        ans = max(ans, a[i]);
    }
    cout<<ans<<endl;
}