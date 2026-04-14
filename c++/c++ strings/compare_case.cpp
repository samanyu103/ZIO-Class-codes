#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    string a,b;
    cin>>a>>b;
    rep(i,a.size()) a[i] = tolower(a[i]);
    rep(i,b.size()) b[i] = tolower(b[i]);
    if (a<b) cout<<"first string is smaller\n";
    else if (a>b) cout<<"second string is smaller\n";
    else cout<<"equal\n";

    
}