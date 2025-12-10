#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#endif

#define all(a) a.begin(), a.end()

const int mod = 1e3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), sw;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (sw.size() < k)
            sw.push_back(arr[i]);
    }
    long long int best_sum = accumulate(all(sw), 0ll);
    long long int worse_sum = accumulate(all(sw), 0ll);
    for (int i = k; i < n; i++) {
        sw.erase(sw.begin());
        sw.push_back(arr[i]);
        best_sum = max(best_sum, accumulate(all(sw), 0ll));
        worse_sum = min(worse_sum, accumulate(all(sw), 0ll));
    }
    long long int resp = best_sum * worse_sum;
    cout << ((resp % mod) + mod) % mod << "\n";
}