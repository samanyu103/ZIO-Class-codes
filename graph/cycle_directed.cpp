#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>> adj;
vector<char> color;
vector<int> parent;

int cycle_start, cycle_end;


bool dfs(int u) {

    color[u] = 1;   // gray

    for (int v : adj[u]) {

        if (color[v] == 0) {

            parent[v] = u;

            if (dfs(v))
                return true;
        }

        else if (color[v] == 1) {

            cycle_start = v;
            cycle_end = u;

            return true;
        }
    }

    color[u] = 2;   // black

    return false;
}


void find_cycle() {

    color.assign(n, 0);
    parent.assign(n, -1);

    cycle_start = -1;

    for (int u = 0; u < n; u++) {

        if (color[u] == 0 && dfs(u))
            break;
    }


    if (cycle_start == -1) {

        cout << "Acyclic\n";
    }

    else {

        vector<int> cycle;

        cycle.push_back(cycle_start);

        for (int u = cycle_end; u != cycle_start; u = parent[u]) {
            cycle.push_back(u);
        }

        cycle.push_back(cycle_start);

        reverse(cycle.begin(), cycle.end());


        cout << "Cycle found: ";

        for (int u : cycle) {
            cout << u + 1 << " ";
        }

        cout << "\n";
    }
}


int main() {

    cin >> n >> m;

    adj.resize(n);

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        u--;
        v--;

        adj[u].push_back(v);
    }

    find_cycle();

    return 0;
}