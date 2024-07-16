#include <bits/stdc++.h>
using namespace std;

/*
 * 폴리오미노
 * 두 번째 줄에 가용 가능한 정사각형의 개수 i, 첫 줄에 오는 정사각형의 개수 j
 * 가용 가능한 정사각형의 개수가 없다면 폴리오미노를 다 만들었다는 의미 > return 1
 *
 * 다음 폴리오미노 후보는
 * 두 번째 줄에 올 수 있는 정사각형의 개수 k
 * for (int k=1; k<=i; k++)
 *      ret += k개의 정사각형을 첫째 줄에 가진 폴리오미노의 개수 go(i-k, k) * (j - k - 1)
 * j+k-1
 * 4
 * 1: 4 4+1-1
 * 2: 5 4+2-1
 * 3: 6
 * 4+3-1
 *
 * 6, 1
 * k = 1~6
 *
 * ㅁㅁㅁ
 *    ㅁ
 * ㅁㅁㅁ
 *   ㅁㅁ
 * return ret
 */

/*
디버깅 포인트
[1] 모듈러 연산이 다 잘 들어갔는지 확인 필요
[2] 
1
1
> 답은 0이 아니라 1이 나와야 함
(for (int i=1; i<n; i++) 코드가 실행되지 않음)
*/

int c, n, dp[104][104];

int go(int can, int first) {
    if (can == 0) return 1;
    int &ret = dp[can][first];
    if (ret != -1) return ret;
    ret = 0;
    for (int second=1; second<=can; second++) {
        ret += ((go(can - second, second) % 10000000) * (first + second - 1)) % 10000000;
    }
    return ret;
}

int main() {

    cin >> c;
    for (int _c=0; _c<c; _c++) {
        cin >> n;
        memset(dp, -1, sizeof(dp));

        int cnt = 0;
        for (int i=1; i<=n; i++) {
            cnt += go(n-i, i);
            cnt %= 10000000;
        }
        cout << cnt << "\n";
    }
    return 0;
}
