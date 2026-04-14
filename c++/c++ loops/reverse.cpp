#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int reverse = 0;
    while(n) {
        int digit = n%10;
        n/=10;
        // cout<<digit<<endl;
        reverse = reverse*10+digit;
    }
    cout<<reverse<<endl;
}