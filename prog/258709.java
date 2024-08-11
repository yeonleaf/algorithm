import java.util.*;

/*
n개의 주사위
조합으로 n/2개의 주사위를 선택
int ret
int dv[14];
int cv[14];
combi1(int start, int cnt) {
    전부 골랐다면
    if (cnt == n/2) {
        List<Integer> ac = new ArrayList<>();
        List<Integer> bc = new ArrayList<>();
        combi2(0, 1, 0, ac);
        combi2(0, 0, 0, bc);
        sort ac
        sort bc
        int wc = 0;
        for (int a : ac) {
            wc += bc에서 a보다 작은 원소의 개수를 구하기
        }
        if (ret < wc) {
            ret = wc;
            dv를 cv에 복사
        }
    }
    for (int i=start; i<n; i++) {
        if (dv[i] == 1) continue;
        dv[i] = 1;
        combi1(i+1);
        dv[i] = 0;
    }
}
combi2(int idx, int mark, int sum, List<Integer> collected) {
    v값이 mark인 주사위를 대상으로
    주사위마다 하나씩 굴려 더한 값을 구한다.
    if (idx >= n) {
        collected.add(sum);
        return;
    }
    if (dv[idx] != mark) combi2(idx+1, mark, sum);
    for (int pip=0; pip<6; pip++) {
        ci번 주사위의 j번 눈을 고름
        combi2(ci+1, pip, sum + dice[idx][pip]);
    }

    
    
}

이분탐색으로 a보다 작은 수 중에서 가장 큰 수 찾기

조합으로 주사위A 세트에서 나올 수 있는 sum 목록 구하기
조합으로 주사위B 세트에서 나올 수 있는 sum 목록 구하기
이분 탐색을 사용해서 A가 B를 이기는 경우의 수 구하기
경우의 수가 기존 경우의 수보다 크다면 A가 고른 주사위를 교체

!!!! lower_bound, upper_bound 자바로 짜는 법 익혀야 함
*/
class Solution {
    static int n, nh, ret;
    static int[] dv = new int[14], rv = new int[14], ans;
    static int[][] dice;
    public int[] solution(int[][] _dice) {
        n = _dice.length;
        dice = _dice;
        nh = n/2;
        combi1(0, 0);
        int count = 0;
        for (int i=0; i<n; i++) {
            if (rv[i] == 1) count++;
        }
        ans = new int[count];
        int idx = 0;
        for (int i=0; i<n; i++) {
            if (rv[i] == 1) ans[idx++] = i+1;
        }
        return ans;
    }
    
    static void combi1(int start, int cnt) {
        if (cnt == nh) {
            List<Integer> ac = new ArrayList<>();
            List<Integer> bc = new ArrayList<>();
            combi2(0, 1, 0, ac);
            combi2(0, 0, 0, bc);
            Collections.sort(ac);
            Collections.sort(bc);
            int wc = 0;
            for (Integer a : ac) {
                int bs = bsearch(a, bc);
                wc += bs;
            }
            if (wc > ret) {
                ret = wc;
                rv = dv.clone();
            }
            return;
        }
        for (int i=start; i<n; i++) {
            if (dv[i] == 1) continue;
            dv[i] = 1;
            combi1(i+1, cnt+1);
            dv[i] = 0;
        }
    }
    
    static void combi2(int idx, int mark, int sum, List<Integer> collected) {

        if (idx >= n) {
            collected.add(sum);
            return;
        }
        
        if (dv[idx] != mark) combi2(idx+1, mark, sum, collected);
        else {
            for (int pip=0; pip<6; pip++) {
                combi2(idx+1, mark, sum + dice[idx][pip], collected);
            }
        }

    
    }
    
    static int bsearch(int target, List<Integer> c) {
        int cs = c.size();
        int lo = 0, hi = cs-1;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (c.get(mi) >= target) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }

}
