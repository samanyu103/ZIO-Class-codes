#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    string s,r;
    cin>>s;
    int n= s.size();
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    rep(i,n) {
        bool vowel = false;
        rep(j,5) {
            if (s[i] == vowels[j]) vowel = true;
        }
        if (vowel) continue;
        r+=s[i];
    }
    cout<<r<<endl;
}