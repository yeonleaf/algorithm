#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, m, x;
string op;
ll MAX;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i=1; i<=20; i++) {
		MAX |= (1 << i);	
	}

	cin >> m;
	for (int _m=0; _m<m; _m++) {
		cin >> op;
		if (op == "all") {
			s = MAX;
			continue;
		} else if (op == "empty") {
			s = 0;
			continue;
		}
		
		cin >> x;
		if (op == "add") {
			if ((s & (1 << x)) == 0) {
				s |= (1 << x);
			}
		}
		else if (op == "check") {
			if (s & (1 << x)) cout << "1\n";
			else cout << "0\n";
		}
		else if (op == "remove") {
			if (s & (1 << x)) {
				s &= ~(1 << x);
			}
		}
		else if (op == "toggle") s ^= (1 << x);
	}
	
	return 0;
}
