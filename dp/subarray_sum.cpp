#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 5;
    int a[n] = {1, 2, 1, 2, 1};
    int k = 3;
    map<int,int> m;
    int p[n];
    rep(i,n) {
        p[i] = a[i]+ (i-1>=0?p[i-1]:0);
    }
    m[0]=1;
    int ans=0;
    rep(i,n) {
        ans+=m[p[i]-k];
        m[p[i]]++;
    }
    cout<<ans<<endl;
}