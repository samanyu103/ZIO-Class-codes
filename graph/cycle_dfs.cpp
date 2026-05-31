#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;

int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;

    for (int u : adj[v]) {

        if (color[u] == 0) {
            parent[u] = v;

            if (dfs(u))
                return true;
        }

        else if (color[u] == 1) {
            cycle_start = u;
            cycle_end = v;
            return true;
        }
    }

    color[v] = 2;
    return false;
}

void find_cycle() {

    color.assign(n, 0);
    parent.assign(n, -1);

    cycle_start = -1;
    cycle_end = -1;

    for (int v = 0; v < n; v++) {

        if (color[v] == 0) {

            if (dfs(v))
                break;
        }
    }

    if (cycle_start == -1) {
        cout << "Acyclic\n";
        return;
    }

    vector<int> cycle;

    cycle.push_back(cycle_start);

    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }

    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << "Cycle found:\n";

    for (int v : cycle) {
        cout << v + 1 << " ";
    }

    cout << "\n";
}

int main() {

    cin >> n >> m;

    adj.resize(n);

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        u--, v--;              // input is 1-indexed

        adj[u].push_back(v);   // directed edge
    }

    find_cycle();

    return 0;
}