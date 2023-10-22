#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int INF = 987654321;
int n, lmt, w[17][17], dp[20][(1 << 17)];

int go(int here, int vis) {
	if (vis == lmt) {
		if (w[here][0]) {
			return w[here][0];
		} else return INF;
	}
	int &ret = dp[here][vis];
	if (ret != -1) return ret;
	ret = INF;
	for (int there=0; there<n; there++) {
		if (here == there || !w[here][there] || vis & (1 << there)) continue;
		ret = min(ret, go(there, (vis | (1 << there))) + w[here][there]);
	}
	return ret;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> w[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	lmt = (1 << n) - 1;
	cout << go(0, 1);
	
	return 0;
} 
