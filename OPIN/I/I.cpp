#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#endif

#define int long long int

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, t;
    cin >> l >> t;
    set<pair<int, int>> tower;
    for (int i = 0; i < l; i++) {
        int x, y;
        cin >> x >> y;
        swap(x, y);
        tower.insert({x, y});
    }
    int ans = 0;
    for (int i = 0; i < t; i++) {
        int x, y, prop;
        cin >> x >> y >> prop;
        swap(x, y);
        for (auto it : tower) {
            int dx = abs(it.first - x);
            int dy = abs(it.second - y);
            int true_dist = dx + dy - min(dx, dy);
            if (true_dist <= prop) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}