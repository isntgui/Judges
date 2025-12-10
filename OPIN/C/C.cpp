#include <bits/stdc++.h>
using namespace std;

double acion[19][7];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int days;
    cin >> days;
    int n = ceil(days / 7.0);
    for (int i = 0; i < n; i++) {
        int m;
        if(i)
            m = (i+1)* 7;
        else
            m = 7;
    }
    cout << n << "\n";
}