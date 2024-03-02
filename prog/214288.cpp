#include <bits/stdc++.h>

using namespace std;

int k, n, ret = 987654321;
vector<int> picked;
vector<pair<int, int>> reqs[10];

int get_wt_sum() {
    int wt_sum = 0;
    for (int _k=0; _k<k; _k++) {
        int mentor = picked[_k];
        priority_queue<int, vector<int>, greater<int>> wq;
        int wt = 0;
        for (pair<int, int> p : reqs[_k]) {
            if (mentor) {
                wq.push(p.first + p.second);
                mentor--;
                continue;
            }
            // 주의해야 할 부분
            int st = wq.top(); wq.pop(); 
            if (p.first <= st) {
                wt += (st - p.first);
                wq.push(st + p.second);
            } else {
                wq.push(p.first + p.second);
            }

        }
        wt_sum += wt;
    }
    return wt_sum;
}

void pick(int cnt, int left) {
    if (cnt == k) {
        if (left == 0) {
            ret = min(ret, get_wt_sum());
        }
        return;
    }
    if (left == 0) return;
    for (int i=1; i<=left; i++) {
        picked.push_back(i);
        pick(cnt+1, left-i);
        picked.pop_back();
    }
}

int solution(int _k, int _n, vector<vector<int>> _reqs) {
    k = _k, n = _n;
    for (vector<int> req : _reqs) {
        reqs[req[2]-1].push_back({req[0], req[1]});
    }
    pick(0, n);
    return ret;
}
