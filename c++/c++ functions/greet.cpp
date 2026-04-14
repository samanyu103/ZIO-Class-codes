#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)


void greet(string s) {
    cout<<"hello "<<s<<endl;
}
int main() {
    string s;
    cin>>s;
    greet(s);
}