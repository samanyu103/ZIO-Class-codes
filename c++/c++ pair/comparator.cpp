#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    vector<pair<int,int>> v = {{1,3},{2,2},{4,2},{3,3}};

    sort(v.begin(), v.end(), cmp);


    // sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
    // if (a.second == b.second)
    //     return a.first < b.first;
    // return a.second < b.second;
    // });

    for (auto p : v)
        cout << p.first << " " << p.second << endl;
}