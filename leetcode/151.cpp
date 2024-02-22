/*for문만 사용한 풀이 (bits 100%)*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string token = "";
        vector<string> bag;
        for (char c : s) {
            if (c == ' ') {
                if (token != "") {
                    bag.push_back(token);
                    token = "";
                }
            } else {
                token += c;
            }
        }
        if (token != "") bag.push_back(token);
        
        string ret = "";
        for (int i=bag.size()-1; i>=0; i--) {
            ret += bag[i];
            if (i > 0) ret += " ";
        }

        return ret;
    }
};


/*stringstream을 사용한 풀이 (bits 43.53%)*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string token = "";
        vector<string> bag;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            bag.push_back(word);
        }
        
        string ret = "";
        for (int i=bag.size()-1; i>=0; i--) {
            ret += bag[i];
            if (i > 0) ret += " ";
        }

        return ret;
    }
};
