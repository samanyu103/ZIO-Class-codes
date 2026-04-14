#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;


int sod (int n) {
    if (n==0) return 0;
    return (n%10) + sod(n/10);
}

int sodi(int n) {
    int ans=0;
    while(n) {
        ans+=n%10;
        n/=10;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<sod(n)<<" " <<sodi(n)<<endl;
}