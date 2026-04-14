#include <iostream>
#include <vector>
using namespace std;

void subsets(int i, vector<int>& a, vector<int>& curr) {
    if (i == a.size()) {
        // print current subset
        for (int x : curr) cout << x << " ";
        cout << endl;
        return;
    }

    // include a[i]
    curr.push_back(a[i]);
    subsets(i + 1, a, curr);

    // exclude a[i] (backtrack)
    curr.pop_back();
    subsets(i + 1, a, curr);
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> curr;

    subsets(0, a, curr);

    return 0;
}