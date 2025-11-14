#include<bits/stdc++.h>
using namespace std;

/*
    Requeriments:
        1. Line Sweep
*/

#define F first
#define S second

int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int n;
    fin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; ++i)
        fin >> a[i].F >> a[i].S;
    sort(a.begin(), a.end());
    // inicio atual, inicio final, resposta que guarda
    // o maior momento que uma vaca eh ordenhada e o maior tempo de descanso sem nenhum trabalho
    int curI=a[0].F, curF=a[0].S, ans1 = curF-curI, ans2 = 0;
    for(int i=1; i<n; ++i) {
        if(a[i].F <= curF) {
            curF = max(curF, a[i].S);
            ans1 = max(ans1, curF-curI);
        } else {
            ans2 = max(ans2, a[i].F-curF);
            curI = a[i].F;
            curF = a[i].S;
            ans1 = max(ans1, curF-curI);
        }
    }
    fout << ans1 << " " << ans2 << "\n";
    return 0;
}

