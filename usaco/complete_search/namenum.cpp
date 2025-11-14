#include<bits/stdc++.h>
using namespace std;

/* 
    Requeriments:
        1. Backtracking
        2. strings
        3. STL (map, set and vector)
*/

#define sz(a) (int)a.size()

// pair (first, second) first -> key, second -> value
map<int, string> mp = {{2, "ABC"}, {3, "DEF"},
{4, "GHI"}, {5, "JKL"}, {6, "MNO"}, {7, "PRS"},
{8, "TUV"}, {9, "WXY"}};
vector<string> ans;
string str, name;
unordered_set<string> conjunto;

// void back() {
//     stack<pair<string, int>> st;
//     st.push({"", 0});
//     while (!st.empty()) {
//         string pal = st.top().first;
//         int i = st.top().second;
//         st.pop();
//         if (i == sz(str)) {
//             if (conjunto.find(pal) != conjunto.end()) {
//                 ans.push_back(pal);
//             }
//         } else {
//             for (char c : mp[str[i] - '0']) {
//                 st.push({pal + c, i + 1});
//             }
//         }
//     }
// }

void back(string pal="", int i=0) {
    if(i==sz(str)) {
        if(conjunto.find(pal)!=conjunto.end())
            ans.push_back(pal);
        return ;
    }
    for(char ch : mp[str[i]-'0'])
        back(pal+ch, i+1);
}

int main() {
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream dic("dict.txt");

    fin >> str;
    for(int i=0; i<4617; ++i) {
    	dic >> name;
    	if(sz(name)==sz(str))
    		conjunto.insert(name);
    }
    back();
    sort(ans.begin(), ans.end());
    if(!ans.empty()) {
	    for(auto e : ans) {
	    	fout << e << "\n";
	    }
	}
    else
    	fout << "NONE\n";

}
