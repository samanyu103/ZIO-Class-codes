#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n) {
        int digit = n%10;
        n/=10;
        cout<<digit<<endl;
    }
}