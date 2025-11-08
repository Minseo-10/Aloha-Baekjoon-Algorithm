# BOJ 10816 — 숫자 카드 2

정수 N개의 카드가 주어졌을 때, M개의 정수 각각이 카드에 몇 개씩 포함되어 있는지를 출력하는 프로그램.



문제 요약
- 입력:  
  1. 정수 N (카드 개수)  
  2. N개의 카드 숫자  
  3. 정수 M (찾을 숫자 개수)  
  4. M개의 숫자 (찾고 싶은 값들)
- 출력:  
  각 숫자가 카드에 몇 번 등장하는지 한 줄로 출력



접근 방식
1. N개의 숫자를 `vector<int>`에 저장  
2. `sort()`로 정렬  
3. `lower_bound()`와 `upper_bound()`를 사용해  
   - 찾는 숫자의 시작 인덱스(lower)  
   - 찾는 숫자의 끝 인덱스(upper)를 구해, 두 차이(`upper - lower`)를 출력



코드

cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        int lower = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int upper = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        cout << upper - lower << " ";
    }
}
