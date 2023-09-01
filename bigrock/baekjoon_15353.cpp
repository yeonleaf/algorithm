/*
테스트 케이스
100 100000
expected 100100
result 0100100
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int up;
string a, b, ret;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;
	if (a.length() < b.length()) swap(a, b);
	
	while (a != "" && b != "") {
		int ca = a.back() - '0'; a.pop_back(); // char -> int
		int cb = b.back() - '0'; b.pop_back();
		
		int csum = (ca + cb + up);
		up = csum / 10;
		ret += to_string(csum % 10); // string을 더할 때는 + 연산
	}
	
	while (a != "") {
		int ca = a.back() - '0'; a.pop_back();
		int csum = (ca + up);
		up = csum / 10;
		ret += to_string(csum % 10); 
	}
	
	if (up) ret += to_string(up); // up이 0이면 더하면 안 됨
	
	reverse(ret.begin(), ret.end());
	
	cout << ret << "\n";
	
	return 0;
}
