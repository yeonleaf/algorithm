#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 100000;
int N, K, tv[MAX+4], pv[MAX+4];
queue<int> q;
vector<int> v;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	
	if (N == K) {
		cout << "0\n";
		cout << N << "\n";
		return 0;
	}
	
	tv[N] = 1;
	pv[N] = N;
	
	q.push(N);
	
	while (q.size()) {
		int cx = q.front(); q.pop();
		if (cx == K) continue;
		for (int nx : {cx + 1, cx - 1, cx * 2}) {
			if (0 <= nx && nx <= MAX) {
				if (!tv[nx]) {
					tv[nx] = tv[cx] + 1;
					pv[nx] = cx;
					q.push(nx);
				}
			}
		}
	}
	
	cout << tv[K] - 1 << "\n";
	for (int i=K; pv[i] != i; i = pv[i]) {
		v.push_back(i);
	}
	v.push_back(N);
	reverse(v.begin(), v.end());
	
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";
	
	return 0;
} 
