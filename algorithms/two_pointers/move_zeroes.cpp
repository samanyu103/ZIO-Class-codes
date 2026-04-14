#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 6;
    int a[n] = {7,0,4,0,9,1};
    int read = 0, write=0;
    while(read<n) {
        if (a[read]) {
            a[write]=a[read];
            write++;
        }
        read++;
    }
    for(int i = write; i <n; i++) a[i]=0;
    rep(i,n) cout<<a[i]<<" ";
    
}