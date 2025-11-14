#include <bits/stdc++.h>
using namespace std;


/*
    Requeriments:
        1. Simulation
*/

#define sz(a) (int)a.size()


// ------- Modificações -------
vector<string> rot90(vector<string> M) {
    vector<string> aux(sz(M));
    int m = sz(M);
    for(int i=0; i<m; ++i)
      for(int j=0; j<m; ++j)
        aux[i][j] = M[j][i];
    for(int i=0; i<m; ++i) {
      string str;
      for(int j=0; j<m; ++j)
          str+=aux[i][j];
      reverse(str.begin(), str.end());
      aux[i] = str;
    }
    return aux;
}

vector<string> rot180(vector<string> M) {
    vector<string> aux = M;
    for(int i=0; i<2; ++i)
        aux = rot90(aux);
    return aux;
}

vector<string> rot270(vector<string> M) {
    vector<string> aux = M;
    aux = rot180(aux);
    aux = rot90(aux);
    return aux;
}

vector<string> mirror(vector<string> M) {
    vector<string> aux;
    int n = sz(M);
    for(int i=0; i<n; ++i) {
        string seila = M[i];
        reverse(seila.begin(), seila.end());
        aux.push_back(seila);
    }
    return aux;
}

// ----------------------------

void debug(vector<string> M) {
    int n = sz(M);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            cout << M[i][j];
        cout << "\n";
    }
}

int32_t main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    int n;
    fin >> n;
    vector<string> M(n), CM(n);
    for(int i=0; i<n; ++i)
        fin >> M[i];
    for(int i=0; i<n; ++i)
        fin >> CM[i];
    vector<string> Maux = M;
    if(rot90(Maux)==CM) 
        fout << "1\n";
    else if (rot180(Maux)==CM)
        fout << "2\n";
    else if(rot270(Maux)==CM)
        fout << "3\n";
    else if(mirror(Maux)==CM)
        fout << "4\n";
    else if(mirror(rot90(Maux))==CM || mirror(rot180(Maux))==CM || mirror(rot270(Maux))==CM || rot270(rot90(Maux))==CM) 
        fout << "5\n";
    else if(M==CM)
        fout << "6\n";
    else
        fout << "7\n";

}
