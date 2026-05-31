#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 6;
    int a[n] = {9, 2, 6, 4, 7, 3};
    int ans=0;
    rep(i,n-1) {
        ans+=max(0, a[i+1]-a[i]);
    }
    cout<<ans<<endl;
}