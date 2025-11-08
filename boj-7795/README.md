# BOJ 7795 — 먹을 것인가 먹힐 것인가

> A 집단의 각 원소 `a`가 B 집단의 원소 `b`보다 클 때 `(a, b)` 쌍의 개수를 모두 구하는 문제.  
> 여러 테스트 케이스에 대해 각 케이스마다 가능한 쌍의 수를 출력한다.

---

문제 요약
- 입력  
  1. 테스트 케이스 개수 `T`  
  2. 각 테스트 케이스마다  
     - 정수 `N`, `M`  
     - N개의 A집단 원소  
     - M개의 B집단 원소  
- 출력  
  각 테스트 케이스별로 `a > b`를 만족하는 쌍의 개수



접근 방식
1. **정렬 & upper_bound 사용**
   - A를 정렬한 뒤, B의 각 원소 `b`마다 `A`에서 `b`보다 큰 원소의 개수를 계산  
   - `upper_bound(A, b)`가 가리키는 인덱스부터 끝까지의 원소가 모두 `b`보다 큼  
   - 따라서 `A.end() - upper_bound(A.begin(), A.end(), b)`가 곧 **b보다 큰 원소 개수**  
2. 이 값을 모든 `b`에 대해 누적 → `(a, b)` 쌍의 총 개수  


코드

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        sort(A.begin(), A.end());

        long long cnt = 0;
        for (int i = 0; i < m; ++i) {
            int b; 
            cin >> b;
            cnt += (A.end() - upper_bound(A.begin(), A.end(), b));
        }
        cout << cnt << '\n';
    }
    return 0;
}
