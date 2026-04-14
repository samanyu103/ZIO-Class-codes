#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0; i<n;i++)
bool good(int n) {
    int d[4] = {};
    int i = 0;
    while(n) {
        d[i] = n%10;
        n/=10;
        i++;
    }
    bool ok = true;
    // going through all pairs
    rep(i,4) {
        rep(j,i) {
            if (d[i]==d[j]) ok= false;
        }
    }
    return ok;
}

int main() {
    int n;
    cin>>n;
    for(int i = n+1; ;i++) {
        if (good(i)) {
            cout<<i<<endl;
            break;
        }
    }
}