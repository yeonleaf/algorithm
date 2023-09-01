#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string p, tmp;
int t, n;

deque<string> parse(string s) {
	s = s.substr(1);
	s.pop_back();
	
	deque<string> dq;
	string num = "";
	for (char c : s) {
		if ('0' <= c && c <= '9') {
			num.push_back(c);
		} else {
			if (num != "") {
				dq.push_back(num);
			}
			num = "";
		}
	}
	if (num != "") dq.push_back(num);
	return dq;
}

string pack(deque<string> dq, int reversed) {
	string ret = "[";
	while (dq.size()) {
		string cur = (reversed ? dq.back() : dq.front());
		if (reversed) {
			dq.pop_back();
		} else {
			dq.pop_front();	
		}
		ret += cur;
		if (!dq.empty()) {
			ret += ",";
		}
	}
	ret += "]";
	return ret;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	for (int _t=0; _t<t; _t++) {
		cin >> p;
		cin >> n;
		cin >> tmp;
		deque<string> target = parse(tmp);
		
		bool error = false;
		int rc = 0;
		for (char o : p) {
			if (o == 'R') rc++;
			else if (o == 'D') {
				if (target.empty()) {
					error = true;
					break;
				}
				if (rc % 2) {
					target.pop_back();
				} else {
					target.pop_front();
				}
			}
		}
				
		if (error) {
			cout << "error\n";
		} else {
			cout << pack(target, rc % 2) << "\n";
		}
		
	}
	return 0;
}
