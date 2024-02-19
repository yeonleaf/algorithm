#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

map<ll, int> mp; 

class RandomizedSet {
public:
    RandomizedSet() {
        mp.clear();
    }
    
    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            mp[val] = 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, mp.size()-1);
        int tgt = dis(gen);

        int idx = 0;
        int ans = 0;
        for (auto element : mp) {
            if (tgt == idx) {
                ans = element.first;
                break;
            }
            idx++;
        }
        return ans;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
