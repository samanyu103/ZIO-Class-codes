#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
vector<int> result;

void generateSubsetSums(int a[], int n, int i, int currentSum) {
    // Base case: all elements considered
    if (i == n) {
        result.pb(currentSum);
        return;
    }

    // Include a[i]
    generateSubsetSums(a, n, i + 1, currentSum + a[i]);

    // Exclude a[i]
    generateSubsetSums(a, n, i + 1, currentSum);
}

int main() {
    int a[] = {1, 2, 3};
    int n = 3;

    generateSubsetSums(a, n, 0, 0);
    rep(i,result.size()) cout<<result[i]<<" ";
    

    return 0;
}