#include <bits/stdc++.h>
using namespace std;

int n;
string ptn, file;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> ptn;
	
	auto star = ptn.find("*");
	string fp = ptn.substr(0, star);
	string rp = ptn.substr(star+1);
	
	for (int _n=0; _n<n; _n++) {
		cin >> file;

    /*substr 하기 전에 미리 예외처리*/
		if (fp.length() + rp.length() > file.length()) {
			cout << "NE\n";
			continue;
		}
    
		if (file.substr(0, fp.length()) == fp && file.substr(file.length() - rp.length()) == rp) {
			cout << "DA\n";
		} else {
			cout << "NE\n";
		}
	}
	
	return 0;
} 
