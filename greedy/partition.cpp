#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    string s = "abcssdcbj";
    int n= s.size(); 
    map<char, int> l;
    rep(i,n) {
        l[s[i]] = i;
    }
    int end = 0, start =0;
    vector<string> result;
    rep(i,n) {
        end = max(end, l[s[i]]);
        if (i==end) {
            // [start..end] is one cut
            result.pb(s.substr(start, end-start+1));
            start=i+1;

        }
    }
    for(string x: result) cout<<x<<endl;
}