#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 9;
    int a[n] = {10,9,2,5,2, 3,7,101,8};
    vector<int>towers;
    rep(i,n) {
        // strictly increasing --> first element larger or equal
        int ind = lower_bound(towers.begin(), towers.end(), a[i])-towers.begin();
        if (ind==towers.size()) {
            towers.pb(a[i]);
        }else{
            towers[ind] = a[i];
        }
    }
    cout<<towers.size();
}