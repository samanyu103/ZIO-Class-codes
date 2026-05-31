#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

const int N  = 1e5+5;
int spf[N];
void init() {
    for(int i = 1; i<N; i++) spf[i]=i;
    for(int i = 2; i*i<N; i++) {
        if(spf[i]==i) {
            // i is prime
            for(int j = i*i; j <N; j+=i) {
                if (spf[j]==j) {
                    // j is not divisible by smaller primes
                    spf[j]=i;
                }
            }
        }
    }
}
vi f(int n) {
    vi v;
    while(n>1) {
        v.pb(spf[n]);
        n/=spf[n];
    }
    return v;
}
int main() {
    init();
    vi v = f(1048);
    for(int x:v) cout<<x<<" ";
}