#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, num, ret;
vector<int> v;

int main() {

	cin >> n >> m;
	
	for (int i=0; i<n; i++) {
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if ((v[i] + v[j]) == m) {
				ret++;
			}
		}
	}
	
	cout << ret << "\n";
	
	return 0;
}
