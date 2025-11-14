#include <bits/stdc++.h>
using namespace std;

const int mxn = 810;

/*
    Requeriments:
        1. Suffix and Prefix
        2. Strings
*/

int pref[mxn][2], suff[mxn][2], n; // dp[i][2] onde o indice i pode conter uma vermelha(0) ou azul(1)
string s;

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    fin >> n >> s;
    s = " " + s + s + " ";
    for (int i = 1; i <= n + n; ++i) {
        if (s[i] == 'r')
            pref[i][0] = pref[i - 1][0] + 1, pref[i][1] = 0;
        else if (s[i] == 'b')
            pref[i][1] = pref[i - 1][1] + 1, pref[i][0] = 0;
        else
            pref[i][0] = pref[i - 1][0] + 1, pref[i][1] = pref[i - 1][1] + 1;
    }
    for (int i = n + n; i >= 1; --i) {
        if (s[i] == 'r')
            suff[i][0] = suff[i + 1][0] + 1, suff[i][1] = 0;
        else if (s[i] == 'b')
            suff[i][1] = suff[i + 1][1] + 1, suff[i][0] = 0;
        else
            suff[i][0] = suff[i + 1][0] + 1, suff[i][1] = suff[i + 1][1] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n + n; ++i)
        ans = max(ans, max(pref[i][0], pref[i][1]) + max(suff[i + 1][0], suff[i + 1][1]));
    ans = min(ans, n);
    fout << ans << "\n";
    return 0;
}
