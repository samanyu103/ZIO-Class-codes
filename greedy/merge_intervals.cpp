#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 4;
    array<int, 2> a[n] = {{2,5},{4,9},{11,13},{12,16}};
    sort(a, a+n);
    vector<array<int, 2>> ans;
    int e = INT_MIN;
    rep(i,n) {
        if (a[i][0]<=e) {
            e=max(e, a[i][1]);
            ans.back()[1]=e;
        }else{
            ans.pb(a[i]);
            e=a[i][1];
        }
    }
    rep(i, ans.size()) {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }


}