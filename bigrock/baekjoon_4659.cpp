#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

bool isConsonant(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	} else {
		return false;
	}
}

int main() {
	
	while (cin >> s) {
		if (s == "end") break;
		
		int conso = 0;
		int vowel = 0;
		bool firstCond = false;
		bool secondCond = true;
		bool thirdCond = true;
		
		char pc = ' ';
		for (char c : s) {
			if (isConsonant(c)) {
				firstCond = true;
				conso++;
				vowel = 0;
				if (conso == 3) {
					secondCond = false;
				}
			} else {
				vowel++;
				conso = 0;
				if (vowel == 3) {
					secondCond = false;
				}
			}
			
			string tmp = "";
			tmp.push_back(pc);
			tmp.push_back(c);
			
			if (pc == c && tmp != "ee" && tmp != "oo") {
				thirdCond = false;
			}
			pc = c;
		}
		
		if (firstCond && secondCond && thirdCond) {
			printf("<%s> is acceptable.\n", s.c_str());
		} else {
			printf("<%s> is not acceptable.\n", s.c_str());
		}
		
	}

	return 0;
} 
