#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i< n; i++)
#define pb push_back

vector<int> cur;
vector<vector<int>> result;
void b(int i, int p, int n) {
    if (i==n) {
        result.pb(cur);
        return;
    }
    rep(j,p) {
        cur.pb(j);
        b(i+1, p, n);
        cur.pop_back();
    }
}


int main() {
    int n=2, p=3;
    b(0,p,n);
    rep(i,result.size()) {
        rep(j,result[i].size()) {
            cout<<result[i][j];
        }
        cout<<endl;
    }
}