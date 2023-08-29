#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string line;
int N, M, sx, sy, ex, ey, cnt, v[304][304];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

char a[304][304];
queue<pair<int, int>> q;
queue<pair<int, int>> nq;


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	cin >> sx >> sy >> ex >> ey;
	
	for (int i=1; i<=N; i++) {
		cin >> line;
		for (int j=1; j<=M; j++) {
			a[i][j] = line[j-1];
		}
	}
	
	q.push({sx, sy});
	v[sx][sy] = 1;
	
	while (true) {
		cnt++;
		
		while (q.size()) {
			int ci, cj;
			tie(ci, cj) = q.front(); q.pop();
			for (int d=0; d<4; d++) {
				int ni = ci + di[d];
				int nj = cj + dj[d];
				if (ni < 1 || nj < 1 || ni > N || nj > M || v[ni][nj]) continue;
				v[ni][nj] = 1;
				if (a[ni][nj] == '1') {
					nq.push({ni, nj});
				} else if (a[ni][nj] == '0') {
					q.push({ni, nj});
				} else if (a[ni][nj] == '#') {
					cout << cnt << "\n";
					return 0;
				}
			}
		}

		while (nq.size()) {
			q.push(nq.front()); nq.pop();
		}
	}
	
	return 0;
} 
