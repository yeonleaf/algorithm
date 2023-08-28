#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

ll go(int n) {
	if (n == 1) return a % c;
	ll ret = go(n / 2) % c;
	ret = (ret * ret) % c;
	if (n % 2) return (ret * a) % c;
	else return ret;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	cin >> a >> b >> c;
	cout << go(b) << "\n";

	return 0;
} 
