#include<iostream>
using namespace std;

const int N = 1e6;
int inv[N];

int powmod(int x, int n, int m) {
    int res=1;
    while(n) {
        if (n&1) res=res*x%m;
        x=x*x%m;
        n>>=1;
    }
    return res;
}
int inv1(int x, int p) {
    return powmod(x, p-2, p);
}

// works for non prime number b as well.
int inv2(int a, int b) {
    int oldr=b, r=a, olds=0, s=1;
    while(r) {
        int q = oldr/r;
        oldr-=q*r;
        olds-=q*s;
        swap(r, oldr);
        swap(olds, s);
    }
    if (olds<0) olds+=b;
    return olds;
}


void init(int p) {
    inv[0]=inv[1]=1;
    for(int i = 2; i<p ; i++)
        inv[i] = p-((p/i)*inv[p%i]%p);
}

int main() {
    init(11);
    cout<<inv[2]<<endl;
    cout<<inv1(2, 11)<<endl;
    cout<<inv2(2,11)<<endl;
}