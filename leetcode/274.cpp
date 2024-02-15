#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int lo = 1, hi, res = 0;
        for (int c : citations) {
            hi = max(hi, c);
        }

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int cnt = 0;
            for (int c : citations) {
                if (c >= mid) cnt++;
            }
            if (cnt >= mid) {
                res = max(mid, res);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }
};
