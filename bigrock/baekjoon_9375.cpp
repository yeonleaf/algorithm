#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string name, kind;
int t, n, ret;
map<string, int> mp;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int _t=0; _t<t; _t++) {
		mp.clear();
		ret = 1;
		
		cin >> n;
		
		for (int _n=0; _n<n; _n++) {
			cin >> name >> kind;
			mp[kind]++;
		}
		
		for (auto c : mp) {
			ret *= (c.second + 1);
		}
	
		ret--;

		cout << ret << "\n";
	}
	

	return 0;
} 
