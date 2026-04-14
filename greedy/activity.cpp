#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 5;
    array<int, 2> a[n] = {{1, 3}, {2, 4}, {1, 2}, {4, 6}, {3, 7}}; //(1,2), (2,4), (4,6)
    // sort by ending times
    // if taking input then keep it as (end, start) and sort normally.
    // rep(i,n) cin>>a[i][1]>>a[i][0] 
    sort(a, a+n, [](auto &a, auto &b) {return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];});
    int s=0, ans=0;
    rep(i,n) {
        if (a[i][0]>=s) {
            ans++;
            s=a[i][1];
        }
    }
    cout<<ans<<endl;
}