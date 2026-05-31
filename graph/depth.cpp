#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)


int ans=0;
const int N = 1e5+5;
vi adj[N];
int depth[N];

void init(int n) {
    rep(i,n) adj[i].clear();
    memset(depth, 0 , 4*n);

}

void dfs(int u=0, int p=-1) {
    depth[u]=1;
    for(int v: adj[u]) {
        if (v==p) continue;
        dfs(v, u);
        depth[u]=max(depth[v]+1, depth[u]);
    }
}

int main() {
    int n;
    cin>>n;
    init(n);
    rep(i,n-1) {
        int x;
        cin>>x;
        x--;
        adj[i+1].pb(x);
        adj[x].pb(i+1);
    }
    dfs();
    cout<<depth[0]<<endl;
}
