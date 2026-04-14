#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n;
    cin>>n;
    int ans =1;
    for(int i = 1; i<=n; i++) ans*=i;
    cout<<ans<<endl;
}