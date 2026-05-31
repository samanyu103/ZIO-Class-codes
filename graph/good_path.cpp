#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)


int ans=0;
const int N = 1e5+5;
vi adj[N];
int a[N];

void init(int n) {
    rep(i,n) adj[i].clear();
    memset(a, 0 , 4*n);
}



void dfs(int u=0, int p=-1, int mx=INT_MIN) {
    if(mx<=a[u]) ans++;
    mx=max(mx, a[u]);
    for(int v: adj[u]) {
        if (v==p) continue;
        dfs(v,u, mx);
    }
}



int main() {
    int n;
    cin>>n;
    init(n);
    rep(i,n) {
        cin>>a[i];
    }
    rep(i,n-1) {
        int x;
        cin>>x;
        x--;
        //x is the parent of i+1. //starts from 1, p[1], p[2].... since p[0] is -1.
        adj[i+1].pb(x);
        adj[x].pb(i+1);
    }
    dfs();
    cout<<ans<<endl;
}
