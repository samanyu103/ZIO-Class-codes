#include<iostream>
#define rep(i,n) for(int i = 0; i<n; i++)
using namespace std;

int main() {
    string s,p;
    cin>>s>>p;
    // int n = s.size(), m = p.size();
    // rep(i, n) {
    //     bool ok = true;
    //     rep(j,m) {
    //         if (i+j>n or s[i+j]!=p[j]) ok = false;
    //     }
    //     if (ok) {
    //         cout<<"found at index: "<<i<<endl;
    //         break;
    //     }
    // }
    int i = s.find(p);
    if(i!=string::npos) cout<<i<<endl;
}