#include <bits/stdc++.h>
using namespace std;

/* 
    Requeriments:
		1. Operators with Base
		2. Palindromic (Strings)
*/

#define int int64_t

// ok
string to_base(int num, int b) {
	string ret = "";
	while(num) {
		ret+=to_string(num%b);
		num/=b;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

// ok
bool is_pal(string str) {
	string rev = str;
	reverse(rev.begin(), rev.end());
	return rev == str;
}

// ok
int count_pal_base(int n) {
	int cnt = 0;
	for(int i=2; i<=10; i++) {
		if(is_pal(to_base(n, i))) {
			cnt++;
		}
	}
	return cnt;
}

int32_t main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int k, s;
	fin >> k >> s;
	vector<int> ans;
	int u = s+1;
	while(ans.size()<k) {
		if(count_pal_base(u)>=2)
			ans.push_back(u);
		u++;
	}
	for(int resp : ans) {
		fout << resp << "\n";
	}
}
