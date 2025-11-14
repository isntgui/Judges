/*
ID: agnelos1
PROG: friday
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

/*
	Requeriments:
		1. Simulation
		2. Math
*/

bool ehbis(int x) {
	return x%4==0&&(x%100!=0||x%400==0);
}

int diaMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int n, anoFinal=1900, soma_dia_mes=0;
	fin >> n, anoFinal+=n;
	vector<int> ans(7, 0);
	for(int ano=1900; ano<anoFinal; ++ano) {
		if(ehbis(ano))
			++diaMes[1];
		else
			diaMes[1] = 28;
		for(int mes=0; mes<12; ++mes) {
			int dia_13 = (soma_dia_mes+12)%7;
			++ans[(dia_13+2)%7];
			soma_dia_mes+=diaMes[mes];
		}
	}
	for(int i=0; i<7; ++i)
		fout << (i==0?"":" ") << ans[i];
	fout << "\n";
}
