#include<iostream>
using namespace std;

int digitcount(int n) {
    if (n==0) return 1;
    int cnt=0;
    while(n) {
        n/=10;
        cnt++;
    }
    return cnt;
}
int digitc(int n) {
    if (n<10) return 1;
    return 1+digitc(n/10);
}
int main() {
    int n;
    cin>>n;
    cout<<digitcount(n)<<" "<<digitc(n)<<endl;
}