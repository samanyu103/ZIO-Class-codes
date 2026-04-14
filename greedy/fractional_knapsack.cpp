#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<array<int, 2>>& items, int W) {
    // Sort by value/weight ratio (descending)
    sort(items.begin(), items.end(), [](auto &a, auto &b) {
        double r1 = (double)a[0] / a[1];
        double r2 = (double)b[0] / b[1];
        return r1 > r2;
    });

    double totalValue = 0.0;

    for (auto &item : items) {
        int value = item[0];
        int weight = item[1];

        if (W >= weight) {
            // Take full item
            totalValue += value;
            W -= weight;
        } else {
            // Take fraction
            totalValue += (double)value * W / weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<array<int, 2>> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int W = 50;

    cout << fixed << setprecision(2);
    cout << fractionalKnapsack(items, W) << endl;

    return 0;
}