#include <bits/stdc++.h>
using namespace std;
int cnt=0;
void permute(vector<int>& a, vector<int>& curr, vector<bool>& used) {
    if (curr.size() == a.size()) {
        // print permutation
        for (int x : curr) cout << x << " ";
        cout << endl;
        cnt++;

        return;
    }

    for (int i = 0; i < a.size(); i++) {
        if (used[i]) continue;

        used[i] = true;           // choose
        curr.push_back(a[i]);

        permute(a, curr, used);  // explore

        curr.pop_back();         // backtrack
        used[i] = false;
        while(i+1<a.size() and a[i+1]==a[i]) i++;
    }
}

int main() {
    vector<int> a = {1, 1, 2, 2, 2, 3, 3, 4};
    sort(a.begin(), a.end());
    vector<int> curr;
    vector<bool> used(a.size(), false);

    permute(a, curr, used);
    cout<<cnt<<endl;
    return 0;
}