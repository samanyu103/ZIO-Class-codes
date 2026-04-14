#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int>& a, vector<int>& curr, vector<bool>& used) {
    if (curr.size() == a.size()) {
        // print permutation
        for (int x : curr) cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < a.size(); i++) {
        if (used[i]) continue;

        used[i] = true;           // choose
        curr.push_back(a[i]);

        permute(a, curr, used);  // explore

        curr.pop_back();         // backtrack
        used[i] = false;
    }
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> curr;
    vector<bool> used(a.size(), false);

    permute(a, curr, used);

    return 0;
}