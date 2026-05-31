#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

const int N = 1e5+5;
vi adj[N];


void init(int n) {
    rep(i,n) adj[i].clear();
}

int main() {
    int n;
    cin>>n;
    init(n);
    int m;
    cin>>m;
    rep(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
    }
    int ind[n]={}, outd[n]={};
    rep(u,n) {
        for(int v:adj[u]) {
            outd[u]++;
            ind[v]++;
        }
    }
    rep(i,n) cout<<"i: "<<i+1<<" indegree: "<<ind[i]<<" outdegree: "<<outd[i]<<endl;
}