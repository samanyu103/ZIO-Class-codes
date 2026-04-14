#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& a) {
    int maxProd = a[0];
    int minProd = a[0];
    int ans = a[0];

    for (int i = 1; i < a.size(); i++) {
        int x = a[i];

        int tempMax = max({x, x * maxProd, x * minProd});
        int tempMin = min({x, x * maxProd, x * minProd});

        maxProd = tempMax;
        minProd = tempMin;

        ans = max(ans, maxProd);
    }

    return ans;
}

int main() {
    vector<int> a = {2, -3, -2, 4, -1};

    int result = maxProduct(a);

    cout << "Maximum Product Subarray: " << result << endl;

    return 0;
}