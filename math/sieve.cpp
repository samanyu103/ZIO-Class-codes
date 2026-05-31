#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

vi primes;
void init(int n) {
    int isprime[n]={};
    for(int i = 2; i<n; i++) isprime[i]=1;
    for(int i = 2; i*i<n; i++) {
        if(isprime[i]) {
            for(int j = i*i; j <n; j+=i) {
                isprime[j]=0;
            }
        }
    }
    rep(i,n) {
        if(isprime[i]) primes.pb(i);
    }
}
int main() {
    init(10);
    for(int p:primes) cout<<p<<" ";    

}