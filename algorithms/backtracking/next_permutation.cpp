#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 1, 2};

    sort(a.begin(), a.end()); // important!

    do {
        for (int x : a) cout << x << " ";
        cout << endl;
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}