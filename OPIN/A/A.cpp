#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#endif

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, pair<int, int>> mp;
    for (int i = 0; i < 8; i++) {
        string str;
        cin >> str;
        mp[str] = {0, 0};
    }
    string mat[3][9];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> mat[i][j];
            if (mp.find(mat[i][j]) != mp.end()) {
                mp[mat[i][j]] = {i, j};
            }
        }
    }
    string target;
    cin >> target;
    pair<int, int> cord;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (mat[i][j] == target) {
                cord = {i, j};
                break;
            }
        }
    }
    int ans = 1e9;
    for (auto it : mp) {
        int dist = abs(cord.first - it.second.first) + abs(cord.second - it.second.second);
        ans = min(ans, dist);
    }
    cout << ans << "\n";
}
