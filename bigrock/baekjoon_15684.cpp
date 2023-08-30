#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, h, mapp[34][34], a, b, ret = 1e9;

bool emptyLeft(int i, int j) {
	if (j == 1) return true;
	return mapp[i][j-1] == 0;
}

bool emptyRight(int i, int j) {
	return mapp[i][j+1] == 0;
}

bool play() {
	for (int _j=1; _j<=n; _j++) {
		int i = 1;
		int j = _j;
		for (int _i=0; _i<=h; _i++) {
			if (mapp[i][j]) {
				i++;
				j++;
			} else if (j > 1 && mapp[i][j-1]) {
				i++;
				j--;
			} else {
				i++;
			}
		}
		if (j != _j) return false;
	}
	return true;
}

void go(int idx, int cnt) {
	if (cnt > 3 || cnt >= ret) {
		return;
	}

	bool canPlay = play();
	if (canPlay) {
		ret = min(ret, cnt);
	}
	
	for (int i=idx; i<=h; i++) {
		for (int j=1; j<n; j++) {
			if (!mapp[i][j] && emptyLeft(i, j) && emptyRight(i, j)) {
				mapp[i][j] = 1;
				go(i, cnt+1);
				mapp[i][j] = 0;
			}
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> h;
	for (int _m=0; _m<m; _m++) {
		cin >> a >> b;
		mapp[a][b] = 1;
	}

	go(1, 0);
	
	if (ret == 1e9) {
		cout << "-1\n";
	} else {
		cout << ret << "\n";
	}
	
	return 0;
}
