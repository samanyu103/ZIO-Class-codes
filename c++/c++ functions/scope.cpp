#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int i = 1;
void f() {
    int i = 3;
    cout<<"i in f is:" <<i<<endl;

}

int main() {
    int i=2;
    f();
    cout<<"i in main is:" <<i<<endl;
}