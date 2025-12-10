#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#endif

#define x first
#define y second

const double pi = acos(-1);

double dist(pair<int, int> p1, pair<int, int> p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return (dx * dx) + (dy * dy);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> point(n, pair<int, int>());
    for (int i = 0; i < n; i++)
        cin >> point[i].x >> point[i].y;
    double max_dist = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_dist = max(max_dist, dist(point[i], point[j]));
        }
    }
    double ans = max_dist * pi;
    cout << fixed << setprecision(2) << ans << "\n";
}