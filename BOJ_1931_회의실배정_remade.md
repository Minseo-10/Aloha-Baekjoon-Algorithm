# Baekjoon 1931 - 회의실 배정
-문제 설명
한 회의실에서 겹치지 않게 최대한 많은 회의를 진행하려면 몇 개까지 배정할 수 있는지 구하는 문제.
각 회의는 시작 시간과 끝나는 시간이 주어진다.
-조건
회의의 시작 시간 >= 이전 회의의 끝나는 시간이어야 함.
회의의 끝나는 시간이 빠른 순서대로 선택해야 최적해를 얻을 수 있다.
-접근 아이디어 (Greedy Algorithm)
1.회의들을 끝나는 시간을 기준으로 오름차순 정렬
 이유 : 가장 빨리 끝나는 회의를 먼저 선택해야, 이후 가능한 회의가 많아짐
2. 끝나는 시간이 같다면 시작 시간 기준으로 정렬 (자동으로 정렬됨)
3. 정렬 후, 하나씩 순회하면서 현재 회의 시작 시간이 마지막으로 선택된 회의의 정료시간 이상이면 선택

-핵심 포인트
그리디 선택 기준 : "가장 빨리 끝나는 회의부터 고른다"
이 기준이 항상 최적임은 교환법칙 증명(Greedy proof)으로 보장됨.
정렬시 (끝, 시작)순으로 저장 -> 코드가 간결해짐.

-코드(.cpp)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<pair<int,int>> meetings(N);
  for(int i = 0; i < N; i++) cin >> meetings[i].second >> meetings[i].first;
  sort(meetings.begin(), meetings.end());

  int count = 0;
  int end_time = 0;

  for(int i = 0; i < N; i++){
    if(meetings[i].first >= end_time){
    end_time = meetings[i].second;
    count++;
    }
  }
  cout << count << '\n';
  return 0;

}






