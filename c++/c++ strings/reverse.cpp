#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    string s;
    cin>>s;
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    
}
// part 2
// int n = s.size();
// rep(i,n/2) swap(s[i], s[n-i-1])

// part 1
// int n = s.size();
// string r;
// for(int i = n-1; i>=0; i--) r+=s[i];
// cout<<r

