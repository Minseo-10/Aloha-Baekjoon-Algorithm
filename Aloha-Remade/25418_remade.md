-문제설명
정수 a에서 시작하여 +1 혹은 *2 연산만을 사용해 목표 정수 k를 만드는 최소 연산 횟수를 구하는 문제입니다.
연산 횟수가 최소가 되어야 하므로, 너비 우선 탐색 (BFS)로 접근합니다.
-접근 아이디어
상태를 정수 값 cur로 두고, 가능한 연산은 cur+1 또는 cur*2로 둡니다
BFS를 이용하면 가장 먼저 k에 도달한 시점이 최소 연산 횟수입니다.
이미 방문한 숫자는 다시 방문하지 않도록 visited 배열을 사용합니다.
-핵심 포인트
그래프 탐색 관점에서 각 정수를 노드, 연산을 간선으로 보면 BFS로 최단거리 탐색 가능.
큐에 push할 때 방문 체크를 해야 중복 방문 방지.
visited[cur+1]; 식의 잘못된 코드를 visited[cur+1] = true; 로 수정해야 함.

코드 .cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited(10000001, false);

int main(){
  int a, k;
  cin >> a >> k;
  queue<int> q;
  q.push(a);
  visited[a] = true;
  int answer = 0;
  while(!q.empty()){
  int size = q.size();
  for(int i = 0; i < size; i++){
    int cur = q.front();
    if(cur == k){
      cout << answer << "\n';
      return 0;
    }
    q.pop();
    visited[cur] = true;
    if(cur+1<=k&&!visited[cur+1]){
      visited[cur+1];
      q.push(cur+1);
    }
    if(cur*2<k&&!visited[cur*2]){
      visited[cur*2];
      q.push(cur*2);
    }
  }
  answer++;
  }
  cout << answer << "\n";
}

