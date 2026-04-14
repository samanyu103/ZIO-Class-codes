#include <bits/stdc++.h>
using namespace std;

int connectStraws(vector<int>& straws) {
    // Min-heap
    // by default priority_queue<int> is a max heap
    priority_queue<int, vector<int>, greater<int>> heap(straws.begin(), straws.end());

    int cost = 0;

    while (heap.size() > 1) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();

        int merged = a + b;
        cost += merged;

        heap.push(merged);
    }

    return cost;
}

int main() {
    vector<int> straws = {1, 3, 2};
    cout << connectStraws(straws) << endl; // Output: 14
    return 0;
}