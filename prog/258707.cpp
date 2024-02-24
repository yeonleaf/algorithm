#include <bits/stdc++.h>

using namespace std;

int n, m, r;
vector<int> p, c;

/*
이미 뽑은 카드 p
뽑을 가능성이 있는 후보 카드 c

이미 뽑아 둔 카드 2
새로 뽑을 카드 1 + 이미 뽑아 둔 카드 1
새로 뽑을 카드 2
만약 세 경우 모두 안 되면 break

vector 하나에서 두 장을 뽑을 수 있는지 확인하는 pick1
vector 두 개에서 두 장을 뽑을 수 있는지 확인하는 pick2

이번 라운드 두 장을 c에 넣는다.
p에서 n+1을 찾을 수 있는지 확인하고 가능하면 라운드를 넘어간다.
p에서 한 장 c에서 한 장 가능한지 확인하고 가능하면 동전 지불 후 라운드를 넘긴다.
c에서 두 장 가능한지 확인하고 가능하면 라운드를 넘긴다.
세 경우 모두 불가능하면 break
*/

bool pick(vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[i] + v[j] == m) {
                v.erase(v.begin()+j, v.begin()+j+1);
                v.erase(v.begin()+i, v.begin()+i+1);
                return true;
            }
        }
    }
    return false;
}

bool pick2(vector<int> &v1, vector<int> &v2) {
    if (!v1.size() && !v2.size()) return false;
    for (int i=0; i<v1.size(); i++) {
        for (int j=0; j<v2.size(); j++) {
            if (v1[i] + v2[j] == m) {
                v1.erase(v1.begin()+i, v1.begin()+i+1);
                v2.erase(v2.begin()+j, v2.begin()+j+1);
                return true;
            }
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    
    n = cards.size();
    m = n + 1;
    
    for (int i=0; i<n/3; i++) {
        p.push_back(cards[i]);
    }
    
    int i = n/3;
    
    while (true) {
        r++;
        if (i >= n) break;
        c.push_back(cards[i]);
        c.push_back(cards[i+1]);
        i += 2;
        if (pick(p)) {
            continue;
        }
        if (coin && pick2(p, c)) {
            coin--;
            continue;
        }
        if (coin >= 2 && pick(c)) {
            coin -= 2;
            continue;
        }
        break;
    }
    
    return r;
}
