class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (char c : s) {
            if (65 <= c && c <= 90) {
                t += tolower(c);
            } else if ((97 <= c && c <= 122) || (48 <= c && c <= 57)) {
                t += c;
            }
        }
        string rt = t;
        reverse(rt.begin(), rt.end());        
        return (rt == t);
    }
};
