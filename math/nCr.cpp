#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int c(int n, int r) {
    int res=1;
    rep(i,r) {
        res=res*(n-i)/(i+1);
    }
    return res;
}
int main() {
    cout<<c(4,2)<<endl;
}