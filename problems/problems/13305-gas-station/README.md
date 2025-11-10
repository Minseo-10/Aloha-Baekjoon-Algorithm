# 13305 주유소 (Gas Station)

- 난이도: Silver III  
- 주제: 그리디 알고리즘, 최소비용  


##  문제 요약
N개의 도시가 일직선 상에 있다.  
각 도시 사이의 도로 길이와 각 도시의 기름 가격이 주어진다.  
1번 도시에서 N번 도시까지 이동할 때,  
최소 비용으로 이동하는 방법을 구하는 문제다.

기름은 각 도시에서 원하는 만큼 구매할 수 있으며,  
다음 도시로 이동할 수 있을 만큼의 기름이 필요하다.



## 핵심 아이디어
- 그리디 알고리즘(Greedy):  
  이전 도시들 중 가장 저렴한 기름값으로 계속 이동한다.  
  즉, 이동하면서 “지금까지 본 가장 싼 가격”을 기준으로 비용을 누적한다.
  
- 매 단계에서 다음을 반복:

  #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> cities;
vector<int> roads;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cities.resize(N);
    roads.resize(N - 1);

    for (int i = 0; i < N - 1; i++) cin >> roads[i];
    for (int i = 0; i < N; i++) cin >> cities[i];
    long long min_price = cities[0];
    long long sum = 0;
    for (int i = 0; i < N - 1; i++) {
        min_price = min(min_price, cities[i]);
        sum += min_price * roads[i];
    }
    cout << sum << '\n';

}
