#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define pb push_back
#define rep(i,n) for(int i=0; i<n; i++)

const int N = 1e5+5;

vi adj[N];
bool vis[N];

int level[N];
int p[N];

void init(int n) {

    rep(i,n) adj[i].clear();

    memset(vis, 0, sizeof(bool)*n);

    rep(i,n) {
        level[i] = -1;
        p[i] = -1;
    }
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
        adj[v].pb(u);
    }

    int s,t;
    cin >> s >> t;

    s--, t--;

    queue<int> q;

    q.push(s);

    vis[s] = true;
    level[s] = 0;

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        for(int v : adj[u]) {

            if(!vis[v]) {

                vis[v] = true;

                level[v] = level[u] + 1;

                p[v] = u;

                q.push(v);
            }
        }
    }

    if(!vis[t]) {

        cout << "No path\n";
        return 0;
    }

    cout << "Distance = " << level[t] << "\n";

    vi path;

    for(int u = t; u != -1; u = p[u]) {
        path.pb(u);
    }

    reverse(path.begin(), path.end());

    cout << "Path: ";

    for(int u : path) {
        cout << u+1 << " ";
    }

    cout << "\n";
}