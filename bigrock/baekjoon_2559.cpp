#include <bits/stdc++.h>
using namespace std;

int n, k, temp[100004], s, bag;
vector<int> ret;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	s = 0;
	for (int i=0; i<n; i++) {
		cin >> temp[i];
		if (i <= (k-1)) {
			bag += temp[i];
		} else {
			ret.push_back(bag);
			bag += temp[i];
			bag -= temp[s];
			s++;
		}
	}
		
	ret.push_back(bag);
	sort(ret.begin(), ret.end(), greater<>());
	cout << ret[0] << "\n";
	return 0;
} 
