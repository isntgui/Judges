/*
ID: agnelos1
TASK: ride
LANG: C++
*/

#include<bits/stdc++.h>
using namespace std;

/*
	Requeriments:
		1. ASCII
*/

#define ll long long

int main() {
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string a, b;
	fin >> a >> b;
	int aux1=1, aux2=1;
	for(int i : a)
		aux1*=(i-'A'+1);
	for(int i : b)
		aux2*=(i-'A'+1);
	if(aux1%47==aux2%47)
		fout << "GO\n";
	else
		fout << "STAY\n";
	return 0;
}