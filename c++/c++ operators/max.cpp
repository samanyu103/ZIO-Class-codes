#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    int m = max(a, max(b, c));
    cout<<m<<endl;
    // if (a>b) {
    //     m=a;
    // }else m=b;
    // if (c>m) m=c;
}