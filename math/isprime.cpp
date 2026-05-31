#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

bool isprime(int n) {
    if (n<2) return false;
    for(int i = 2; i*i<=n; i++) {
        if (n%i==0)
        return false;
    }
    return true;
}

int main() {
    int n = 97;
    cout<<isprime(n)<<endl;

}