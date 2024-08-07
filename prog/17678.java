import java.util.*;
/*
ArrayList tt = timetable에 있는 요소를 모두 분으로 바꾼 후 오름차순 정렬한다.
buss = 09:00부터 시작해서 마지막 버스 출발 시간까지 시간을 계산해서 저장

for bus : buss
    승객을 태운다

마지막 버스에 콘이 그냥 탈 수 있으면 마지막 버스의 출발시간을 리턴
마지막 버스에 콘이 그냥 탈 수 없으면 (꽉 찬 상태)
    fastest 마지막 셔틀버스 출발 시간에 탑승한 승객의 대기열 도착 시간 중 가장 빠른 대기 시간을 구한다.
    fpeople fastest와 같은 대기시간을 가진 사람 수를 구한다.
    fpeople < m 이면 return fatest
    아니면 return fatest-1
    
마지막 셔틀버스 출발 시간에 탑승한 승객의 대기 시간 중 가장 늦은 대기 시간 - 1
ArrayList<ArrayList<Integer>> rcust
n = timetable.size();
for bus : buss
    ArrayList<Integer> cust
    while idx < n && cust.size() < m && tt[idx] <= bus
        cust.add(tt[idx]);
        idx++;
    if (cust.size() < m) {
        콘이 이 버스에 탈 수 있음을 의미
        return parse2(bus - 1);
    }
    rcust.add(cust);
rcust의 마지막 시간대의 첫 번째 대기시간 - 1

!!!! 콘이 무사히 셔틀을 타고 사무실로 갈 수 있는 제일 늦은 도착 시각을 출력한다 !!!!
!!!! 따라서 마지막 버스에 이미 m명이 탄 상태라면 맨 마지막 사람만 제끼면 됨    !!!!
    
*/

class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        
        ArrayList<Integer> buss = new ArrayList<>();
        int bt = 540;
        while (n > 0) {
            buss.add(bt);
            bt += t;
            n--;
        }
        
        ArrayList<Integer> tt = new ArrayList<>();
        for (String time : timetable) {
            tt.add(parse1(time));
        }
        
        Collections.sort(tt);
        
        HashMap<Integer, ArrayList<Integer>> rcust = new HashMap<>();
        int cs = tt.size();
        int idx = 0;
        for (Integer bus : buss) {
            ArrayList<Integer> cust = new ArrayList<>();
            while (idx < cs && cust.size() < m && tt.get(idx) <= bus) {
                cust.add(tt.get(idx));
                idx++;
            }
            rcust.put(bus, cust);
        }
        
        Integer lastKey = buss.get(buss.size()-1);
        ArrayList<Integer> last = rcust.get(lastKey);
        if (last.size() < m) {
            return parse2(lastKey);
        } else {
            int lastTime = last.get(last.size()-1);
            return parse2(lastTime-1);
        }        
    }
    
    int parse1(String target) {
        String[] splited = target.split(":");
        return Integer.parseInt(splited[0]) * 60 + Integer.parseInt(splited[1]);
    }
    
    String parse2(int target) {
        return String.format("%02d", target / 60) + ":" + String.format("%02d", target % 60);
    }
}
