#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, h_atk, t, a, h, tarr[123459], aarr[123459], harr[123459], s = 1, e = 9e18, ret = 9e18;

bool win(ll hp, ll atk) {
	ll mhp = hp;
	for (int i=0; i<n; i++) {
		t = tarr[i], a = aarr[i], h = harr[i];
		if (t == 1) {
			ll base = h / atk;
			if (!(h % atk)) base--;
			if (base * a >= hp) return false;
			hp -= (base * a);
		} else {
			atk += a;
			hp = min(mhp, hp + h);
		}
	}
	return true;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> h_atk;
	for (int i=0; i<n; i++) {
		cin >> tarr[i] >> aarr[i] >> harr[i];
	}
		
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (win(mid, h_atk)) {
			ret = min(ret, mid);
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	
	cout << ret << "\n";
	
	return 0;
} 
