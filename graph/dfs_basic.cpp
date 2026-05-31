#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

const int N = 1e5+5;
vi adj[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    cout << u+1 << " ";   // process node
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
void init(int n) {
    rep(i,n) adj[i].clear();
    memset(vis, 0, 4*n);
}

int main(){
    int n, m;
    cin >> n >> m;

    init(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);   // remove for directed graph
    }

    rep(u,n) {
        if(!vis[u]){
            dfs(u);   // handles disconnected graph
        }
    }

    cout << "\n";
}