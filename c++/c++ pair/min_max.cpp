#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

pair<int, int> min_max(int a[], int n) {
    sort(a,a+n);
    return make_pair(a[0], a[n-1]);
}

int main() {
    
}