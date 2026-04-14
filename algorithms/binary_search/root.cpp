#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    double x;
    cin>>x;
    double l = 0, r = max(1.0,x); // because sqrt(x) for x<1 could be > x, so if you cannot let r=x
    while(r-l>1e-8) {
        double m = (l+r)/2;
        if (m*m<x)l=m;
        else r=m;
    }
    cout<<fixed<<setprecision(8)<<l<<endl;
}