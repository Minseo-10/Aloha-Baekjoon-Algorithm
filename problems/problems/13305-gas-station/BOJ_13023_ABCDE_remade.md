#baekjoon 130323 - ABCDE

-문제 설명
N명의 친구와 M개의 친구 관계가 주어질 때, 서로 연속된 5명이 친구관계(길이 4의 단순 경로)로 이어지는지 판단하여,
존재하면 1, 없으면 0을 출력하는 문제

-접근 아이디어 (DFS + 백트래킹)
그래프의 임의 정점 i에서 시작해 깊이 5에 도달하는 경로가 있는지 DFS로 탐색.
재방문을 방지하기 위해 visited 사용, 재귀 복기 시 백트래킹으로 방문 해제.
어느 지점에서든지 길이 5(=깊이 5)에 도달하면 즉시 종료(early exit).

-핵심 포인트
단순 경로여야 하므로 방문 배열 필수
매 시작 정점마다 DFS를 돌리되, 함수 내부에서 백트래킹으로 방문 상태를 원복하므로 별도의 초기화는 불필요
전역 플래그 arrive로 발견 즉시 전체 탐색 중단!

-코드(.cpp)

#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool arrive;

void DFS(int now, int depth) {
  if(depth == 5) {
    arrive = true;
    return;
  }
  visited[now] = true;
  for(int nxt : A[now]) {
    if(arrive) return;
    if(!visited[nxt]) DFS(nxt, depth + 1);
  }
  visited[now] = false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  arrive = false;
  A.resize(N);
  visited = vector<bool>(N, false);
  for(int i = 0; i < M; i++){
    int s, e;
    cin >> s >> e;
    A[s].push_back(e);
    A[e].push_back(s);
  }
  for(int i = 0; i < N; i++){
    DFS(i, 1);
    if(arrive) break;
  }
  if(arrive) cout << 1 << '\n';
  else cout <<0<<'\n';
}

