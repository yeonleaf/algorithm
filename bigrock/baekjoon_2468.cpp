#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, mapp[104][104], mark[104][104], v[104][104], mh, mcnt;
int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

void dfs(int i, int j) {
	for (int d=0; d<4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];
		if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
		if (!mark[ni][nj] || v[ni][nj]) continue;
		v[ni][nj] = 1;
		dfs(ni, nj);
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> mapp[i][j];
			mh = max(mh, mapp[i][j]);
		}
	}

	for (int h=0; h<=mh; h++) {
		fill(&mark[0][0], &mark[0][0]+104*104, 1);
		memset(v, 0, sizeof(v));
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (mapp[i][j] <= h) {
					mark[i][j] = 0;
				}
			}
		}
		
		int cnt = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (mark[i][j] && !v[i][j]) {
					v[i][j] = 1;
					dfs(i, j);
					cnt++;
				}
			}
		}
	
		mcnt = max(mcnt, cnt);
	}
	
	cout << mcnt << "\n";
	return 0;
} 
