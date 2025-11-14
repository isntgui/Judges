/*
	ID: agnelos1
	PROG: palsquare
	LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

/* 
    Requeriments:
		1. Operators with Base
		2. Palindromic
		3. Two Pointers
*/

#define int int64_t

const string numbers = "0123456789ABCDEFGHI";

string base(int x, int b) {
	int N = x;
	string ret = "";
	while(N) {
		ret+=numbers[N%b];
		N/=b;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool isPalindrome(string str) {
	int l=0, r = (int)str.size()-1;
	bool ok = true;
	while(l<r&&ok) {
		if(str[l]!=str[r]) {
			ok = false;
		}
		--r, ++l;
	}
	return ok;
}

int32_t main() {
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int n;
	fin >> n;
	for(int i=1; i<=300; i++) {
		string resp = base(i*i, n);
		if(isPalindrome(resp)) {
			fout << base(i, n) << " " << resp << "\n";
		}
	}
}