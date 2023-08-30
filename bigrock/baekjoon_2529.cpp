#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, a[14];
vector<int> v;
char ord[14];
string r1, r2;
set<string> sett;


bool check() {
	for (int i=0; i<k; i++) {
		if (ord[i] == '<') {
			if (v[i] >= v[i+1]) return false;
		} else {
			if (v[i] <= v[i+1]) return false;
		} 
	}
	return true;
}

string vconcat() {
	string tmp = "";
	for (int i=0; i<=k; i++) {
		tmp += to_string(v[i]);
	}
	return tmp;
}

string str_max(string prv, string nxt) {
	if (prv == "") return nxt;
	if (prv < nxt) return nxt;
	return prv;
}

string str_min(string prv, string nxt) {
	if (prv == "") return nxt;
	if (prv > nxt) return nxt;
	return prv;
}

void bt(int cnt) {
	
	if (cnt == k+1) {
		if (check()) {
			string tmp = vconcat();
			r1 = str_max(r1, tmp);
			r2 = str_min(r2, tmp);
		}
		return;
	}
	
	for (int i=0; i<=9; i++) {
		if (!a[i]) {
			a[i] = 1;
			v.push_back(i);
			bt(cnt+1);
			a[i] = 0;
			v.pop_back();
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> k;
	for (int i=0; i<k; i++) {
		cin >> ord[i];
	}

	bt(0);
	
	cout << r1 << "\n";
	cout << r2 << "\n";
	
	return 0;
} 
