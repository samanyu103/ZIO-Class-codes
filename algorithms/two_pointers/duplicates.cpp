#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n=6;
    int a[n] = {1,1,3,4,4,5};
    int read=1,write=1;
    while(read<n) {
        if (a[read]!=a[read-1]) {
            a[write]=a[read];
            write++;
        }
        read++;
    }
    int new_size=write;
    rep(i,new_size) cout<<a[i]<<" ";
}