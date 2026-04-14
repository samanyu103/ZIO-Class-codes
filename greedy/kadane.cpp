#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 6;
    int a[n] = {-1,3,-4,5,2,-1};
    int m = 0, mx=INT_MIN;
    rep(i,n) {
        m = max(m+a[i], a[i]);
        mx = max(mx, m);
    }
    cout<<mx<<endl;
}