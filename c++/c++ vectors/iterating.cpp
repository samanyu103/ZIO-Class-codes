#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    vi v = {1,2,3,4};
    rep(i,v.size()) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int& x:v) {
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto it = v.begin(); it!=v.end(); it++) {
        cout<<*it<< " ";
    }
    cout<<endl;


// difference between int x and int& x


    // for(int x:v) {
    //     x++;
    // }
    // rep(i,v.size()) {
    //     cout<<v[i]<<" ";
    // }

    // for(int& x:v) {
    //     x++;
    // }
    // rep(i,v.size()) {
    //     cout<<v[i]<<" ";
    // }

}