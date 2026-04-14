#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n;
    cin>>n;
    int l = 0, r= n+1; // handles n=1 there should be atleast one 1 in the seq 000000111 where you need to find the last 0/first 1.
    while(l<r) {
        int m = l+(r-l)/2;
        if (m*m<=n) l=m+1;
        else r=m;
    } 
    l--;
    cout<<l<<endl;
}