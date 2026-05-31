#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> color;   // -1 = uncolored, 0/1 = two colors

bool dfs(int u, int c) {

    color[u] = c;

    for (int v : adj[u]) {

        // not colored yet
        if (color[v] == -1) {

            if (!dfs(v, 1 - c))
                return false;
        }

        // same color on both ends
        else if (color[v] == c) {
            return false;
        }
    }

    return true;
}

bool isBipartite() {

    for (int u = 0; u < n; u++) {

        // disconnected component
        if (color[u] == -1) {

            if (!dfs(u, 0))
                return false;
        }
    }

    return true;
}

int solve() {

    cin >> n >> m;
    adj.clear();
    color.clear();
    adj.resize(n);
    color.assign(n, -1);

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        u--, v--;   // 1-indexed input

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (isBipartite() ? "YES\n" : "NO\n");

    return 0;
}

int main() {
    int tt;
    cin>>tt;
    while(tt--) {
        solve();
    }
}