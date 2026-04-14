#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    vi v;
    int n;
    cin>>n;
    rep(i,n) {
        int x;
        cin>>x;
        v.pb(x);
    }
    for(int x:v) cout<<x<<" ";
}