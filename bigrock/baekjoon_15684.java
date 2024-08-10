
import java.util.*;
import java.io.*;

/*
* n(세로), m(가로 - 실선), h(가로 - 점선), a, b, ret(MAX 초기화)

* int arr[a][b] : b번과 b+1번을 a번 점선 위치에서 연결함
* [34][14]
* boolean play()
*       flag = true;
*       for (int _j 1 ~ n)
*           j = _j 가로
*           i = 0 세로
*           for (int _i 1 ~ h)
*               arr[i][j] 가로선이 있으면
*                   j++;
*               i++;
*           j != _j flag = false;
*       return flag;
*
* go(cnt)
*   if (cnt > 3) return;
*   if (play()) {
*       ret = Math.min(ret, cnt);
*   }
*   for (int i 1 ~ h)
*       for (int j 1 ~ n-1)
*           가로선을 놓을 수 있는 자리인지 확인
*           해당 자리에 가로선이 있으면 안됨
*           양옆에 가로선이 있으면 안됨
*           가로선 놓기
*           go(cnt+1)
*           가로선 치우기
*
* * 두 가로선이 서로 연속하거나 접하면 안 됨
 * i번 세로선의 결과가 i번이어야 함
 * 게임
 * for (i in 1 ~ h)
 *   j = i;
 *
 * arr[i][j] arr[i][j-1]


!!! 자기 자신으로 돌아오기 위해서는 자기 자신에 가로선이 짝수 개 걸려있어야 함
이걸로 edge case 제거할 수 있음
* */

public class Main {

    static int n, m, h, ret = Integer.MAX_VALUE;
    static int[][] arr = new int[34][14];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        for (int _m=0; _m<m; _m++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[a][b] = 1;
        }
        br.close();
        go(0);
        if (ret == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ret);
        }
    }

    static boolean play() {
        for (int _j=1; _j<=n; _j++) {
            int j = _j;
            int i = 1;
            for (int _i=0; _i<h; _i++) {
                if (arr[i][j] == 1) {
                    j++;
                } else if (j-1 >= 1 && arr[i][j-1] == 1) {
                    j--;
                }
                i++;
            }
            if (j != _j) return false;
        }
        return true;
    }

    static void go(int cnt) {
        if (cnt > 3) return;
        if (play()) {
            ret = Math.min(ret, cnt);
            return;
        }
        for (int i=1; i<=h; i++) {
            for (int j=1; j<n; j++) {
                if (canPlace(i, j)) {
                    arr[i][j] = 1;
                    go(cnt+1);
                    arr[i][j] = 0;
                }
            }
        }

    }

    static boolean canPlace(int i, int j) {
        if (arr[i][j] == 1) return false;
        if (j-1 >= 1 && arr[i][j-1] == 1) return false;
        if (j+1 >= n-1 && arr[i][j + 1] == 1) return false;
        return true;
    }

}
