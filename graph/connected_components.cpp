#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)


const int N = 1e5+5;
bool vis[N];
vi adj[N];
vvi components;


void init(int n) {
    rep(i,n) adj[i].clear();
    memset(vis, 0, 4*n);
}

void dfs(int u = 0) {
    components.back().pb(u);
    vis[u]=1;
    for(int v: adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    init(n);
    rep(i,m) {
        int u, v;
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    int cnt=0;
    rep(i,n) {
        if (!vis[i]) {
            cnt++;
            components.pb({});
            dfs(i);
        }
    }
    cout<<cnt<<endl;
    for(vi v: components) {
        for(int i:v) {
            cout<< i+1<<" ";
        }
        cout<<endl;
    }
}