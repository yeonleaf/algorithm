#include <bits/stdc++.h>

using namespace std;

struct State {
    int ri, rj, bi, bj, count;
    int rv[8][8], bv[8][8];
    State() {
        ri = 0, rj = 0, bi = 0, bj = 0, count = 0;
        memset(rv, 0, sizeof(rv));
        memset(bv, 0, sizeof(bv));
    }
    void print(int n, int m) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == ri && j == rj) cout << "r ";
                else if (i == bi && j == bj) cout << "b ";
                else cout << "0 ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void printR(int n, int m) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << rv[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void printB(int n, int m) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << bv[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int n, m;
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
queue<State> q;
vector<vector<int>> maze;

int solution(vector<vector<int>> _maze) {
    maze = _maze;
    n = maze.size();
    m = maze[0].size();
    
    State ss;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == 1) {
                ss.ri = i;
                ss.rj = j;
                ss.rv[i][j] = 1;
            } else if (maze[i][j] == 2) {
                ss.bi = i;
                ss.bj = j;
                ss.bv[i][j] = 1;
            }
        }
    }
        
    q.push(ss);
    
    while (q.size()) {
        State s = q.front(); q.pop();
        int cri, crj, cbi, cbj, ccount;
        cri = s.ri, crj = s.rj, cbi = s.bi, cbj = s.bj, ccount = s.count;

        // 둘 다 목적지에 도착했다면 턴 수를 리턴
        if (maze[cri][crj] == 3 && maze[cbi][cbj] == 4) {
            return ccount;
        }
        
        for (int rd=0; rd<4; rd++) {
            for (int bd=0; bd<4; bd++) {
                // 목적지에 도착한 경우 움직이지 않고 아닌 경우 이동
                int nri = (maze[cri][crj] == 3 ? cri : cri + di[rd]);
                int nrj = (maze[cri][crj] == 3 ? crj : crj + dj[rd]);
                int nbi = (maze[cbi][cbj] == 4 ? cbi : cbi + di[bd]);
                int nbj = (maze[cbi][cbj] == 4 ? cbj : cbj + dj[bd]);
                
                // 격자 밖으로 넘어가는 경우나 벽인 경우
                if (nri < 0 || nrj < 0 || nbi < 0 || nbj < 0 || nri >= n || nrj >= m || nbi >= n || nbj >= m || maze[nri][nrj] == 5 || maze[nbi][nbj] == 5) {
                    continue;
                }
                // 자신의 목적지가 아니면서 방문 처리가 되어있는 경우
                if ((maze[nri][nrj] != 3 && s.rv[nri][nrj]) || (maze[nbi][nbj] != 4 && s.bv[nbi][nbj])) {
                    continue;
                }
                
                // 수레끼리 자리 바뀌는지 확인
                if ((nri == cbi && nrj == cbj) && (nbi == cri && nbj == crj)) {
                    continue;
                }
                // 동시에 같은 칸으로 움직이는지 확인
                if (nri == nbi && nrj == nbj) {
                    continue;
                }
                
                // 방문 체크 하고 다음 턴으로 넘어가기
                State ns = s;
                ns.rv[nri][nrj] = 1;
                ns.bv[nbi][nbj] = 1;
                ns.ri = nri, ns.rj = nrj, ns.bi = nbi, ns.bj = nbj;
                ns.count = ns.count + 1;
                q.push(ns);
            }
        }
    }
    
    return 0;
}

/*
struct carrier
    ri, rj, bi, bj, count
    rv[][]
    bv[][]

queue<carrier> q;
int ri, rj, bi, bj;
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

while(q.size())
    carrier c
    cri, crj, cbi, cbj, count 값 할당
    crv, cbv 할당
    만약 maze[cri][crj] == 3 && maze[cbi][cbj] == 4 {
        return count
    }
    for rd in 4
        for bd in 4
            목적지에 도착한 경우 움직이지 않고 아닌 경우 이동
            벽이나 격자 칸
            자신의 목적지가 아니면서 방문 처리가 되어있는 경우
            수레끼리 자리 바뀌는지 확인
            동시에 같은 칸으로 움직이는지 확인
            
            방문 체크한 후 이동
            
return 0
*/
