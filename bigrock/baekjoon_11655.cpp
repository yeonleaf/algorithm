#include <bits/stdc++.h>
using namespace std;

string s, ret;

bool isNotAlphabet(char c) {
	if (65 <= c && c <= 90) return false;
	if (97 <= c && c <= 122) return false;
	return true;
}

int main() {
	
	getline(cin, s);
		
	for (char c : s) {
		if (isNotAlphabet(c)) {
			ret += c;
			continue;
		}
		int ic = int(c);
		int inc = ic + 13;
		if (65 <= ic && ic <= 90 && inc > 90) {
			ret += char(inc - 90 + 64);
		} else if (97 <= ic && ic <= 122 && 122 < inc) {
			ret += char(inc - 122 + 96);
		} else {
			ret += char(inc);
		}
	}
	
	cout << ret << "\n";
	
	return 0;
} 
