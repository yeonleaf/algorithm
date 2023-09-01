/*
테스트케이스
3 26
antarctica
antahellotica
antacartica
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string tmp;
int n, k, vis[25], ret;
map<char, int> dic;
vector<char> v;
vector<string> wv;

bool canRead(string s) {
	for (char c : s) {
		if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') continue;
		if (!vis[dic[c]]) return false;
	}
	return true;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	
	for (int i=0; i<n; i++) {
		cin >> tmp;
		tmp = tmp.substr(4);
		tmp = tmp.substr(0, tmp.length()-4);
		wv.push_back(tmp);
	}	
	
	for (char c='a'; c<='z'; c++) {
		if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') continue;
		v.push_back(c);
		dic[c] = v.size()-1;
	}
		
	if (k == 0 || k < 5) {
		cout << "0\n";
		return 0;
	}
	
	int m = v.size();
	
	for (int comb=0; comb<=(1 << m)-1; comb++) {
		memset(vis, 0, sizeof(vis));
		
		int ccnt = 0;
		for (int i=0; i<m; i++) {
			if (comb & (1 << i)) {
				ccnt++;
				vis[i] = 1;
			}
		}
				
		if (ccnt == (k-5)) {
			int wcnt = 0;
			for (string w : wv) {
				if (canRead(w)) {
					wcnt++;
				}
			}
			ret = max(ret, wcnt);
		}

	}
	
	cout << ret << "\n";
	
	return 0;
}
