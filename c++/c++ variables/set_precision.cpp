#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << fixed << setprecision(2);   // set once
    cout << 3.14159 << endl;//3.14
    cout << 10.5 << endl;//10.50
    cout << 2.0/3 << endl;//0.67
    cout<<1<<endl;//1
    cout<<2/3<<endl;//0

    return 0;
}