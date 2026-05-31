#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n; i++)

const int N = 1e5+5;

vi adj[N];
bool vis[N];

void init(int n) {
    rep(i,n) adj[i].clear();
    memset(vis, 0, sizeof(bool)*n);
}

int main() {

    int n,m;
    cin >> n >> m;

    init(n);

    rep(i,m) {
        int u,v;
        cin >> u >> v;

        u--, v--;

        adj[u].pb(v);
        adj[v].pb(u);     // remove for directed graph
    }

    queue<int> q;

    q.push(0);            // start from node 0
    vis[0] = true;

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        cout << u+1 << " ";   // process node

        for(int v : adj[u]) {

            if(!vis[v]) {

                vis[v] = true;
                q.push(v);
            }
        }
    }

    cout << "\n";
}