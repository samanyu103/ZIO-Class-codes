#include <bits/stdc++.h>
using namespace std;

using pii = array<int, 2>;

double dist(const pii &a, const pii &b) {
    long long dx = a[0] - b[0];
    long long dy = a[1] - b[1];
    return sqrt(dx * dx + dy * dy);
}

// Brute force for small n
double brute(vector<pii> &pts, int l, int r) {
    double d = 1e18;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            d = min(d, dist(pts[i], pts[j]));
        }
    }
    return d;
}
// we sort pts by y coordinate before we exit the function.

double solve(vector<pii> &pts, vector<pii> &temp, int l, int r) {
    if (r - l <= 3) {
        double d = brute(pts, l, r);
        sort(pts.begin() + l, pts.begin() + r + 1,
             [](const pii &a, const pii &b) {
                 return a[1] < b[1];
             });
        return d;
    }

    int mid = (l + r) / 2;
    int midx = pts[mid][0];

    double dl = solve(pts, temp, l, mid);
    double dr = solve(pts, temp, mid + 1, r);
    double d = min(dl, dr);

    // Merge by y-coordinate
    // recursivley the left and right halves of pts are now sorted b y coordinate
    // we merge all the points by y coordinate put them in temp and then copy back from temp into pts
    merge(pts.begin() + l, pts.begin() + mid + 1,
          pts.begin() + mid + 1, pts.begin() + r + 1,
          temp.begin(),
          [](const pii &a, const pii &b) {
              return a[1] < b[1];
          });

    copy(temp.begin(), temp.begin() + (r - l + 1), pts.begin() + l);

    // Build strip
    vector<pii> strip;
    for (int i = l; i <= r; i++) {
        if (abs(pts[i][0] - midx) < d) {
            strip.push_back(pts[i]);
        }
    }

    // Check at most next 7 points
    int sz = strip.size();
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz && (strip[j][1] - strip[i][1]) < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

double closest_pair(vector<pii> &points) {
    int n = points.size();
    sort(points.begin(), points.end(), [](const pii &a, const pii &b) {
        return a[0] < b[0];
    });

    vector<pii> temp(n);
    return solve(points, temp, 0, n - 1);
}

// Example usage
int main() {
    vector<pii> points = {
        {2, 3}, {12, 30}, {40, 50},
        {5, 1}, {12, 10}, {3, 4}
    };

    cout << closest_pair(points) << endl;//{2,3}, {3,4}
    return 0;
}