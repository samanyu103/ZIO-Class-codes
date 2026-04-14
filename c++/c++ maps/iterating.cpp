#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int,string> m = {{0,"hi"}, {1,"apple"}};
    // for(auto x:m) {
    //     cout<<"key is :"<<x.first<<endl;
    //     cout<<"value is: "<<x.second<<endl;
    // }    
    for(auto it = m.begin(); it!=m.end();it++) {
        cout<<"key is :"<<(*it).first<<endl;
        cout<<"value is: "<<it->second<<endl;
    }
}