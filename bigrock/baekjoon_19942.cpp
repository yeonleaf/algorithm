/*
테스트 케이스
4
10 10 10 10
10 0 0 0 0
0 10 0 0 0
0 0 10 0 0
0 0 0 10 0

expected::
0
1 2 3 4

result::
-1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Ingredient {
	int p, f, s, v, c;
} a[20];

int n, mp, mf, ms, mv, cp, cf, cs, cv, cc, rcost = 1e9;
vector<string> rset;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i=0; i<n; i++) {
		cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
	}
	
	for (int i=0; i<=(1 << n)-1; i++) {
		cp = 0, cf = 0, cs = 0, cv = 0, cc = 0;
		string tmp = "";
		for (int j=0; j<n; j++) {
			if (i & (1 << j)) {
				tmp += (to_string(j+1) + " ");
				cp += a[j].p; cf += a[j].f;
				cs += a[j].s; cv += a[j].v;
				cc += a[j].c;
			}
		}
		
		if (cp >= mp && cf >= mf && cs >= ms && cv >= mv) {
			if (cc < rcost) {
				rset.clear();
				rset.push_back(tmp);
				rcost = cc;
			} else if (cc == rcost) {
				rset.push_back(tmp);
			}
		}
	}
	
	sort(rset.begin(), rset.end());
	
	if (rcost == 1e9) {
		cout << "-1\n";
		return 0;
	}
	
	cout << rcost << "\n";
	cout << rset[0] << "\n";
	
	return 0;
}
