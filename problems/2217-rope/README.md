# 2217 로프 (Rope)

- **난이도:** Silver IV  
- **주제:** 정렬, 그리디 알고리즘  
- **풀이 언어:** C++  
- **문제 링크:** [Baekjoon 2217](https://www.acmicpc.net/problem/2217)

---

## 문제 요약
N개의 로프가 있다.  
각 로프는 일정한 중량까지만 버틸 수 있다.  
여러 개의 로프를 함께 사용할 경우,  
**가장 약한 로프가 버틸 수 있는 중량 × 로프 개수**가 전체 중량이 된다.  

즉, 모든 로프 중 일부를 선택했을 때 들 수 있는 **최대 중량**을 구하는 문제이다.

---

##  핵심 아이디어
- 가장 강한 로프부터 내림차순으로 정렬  
- `i`번째 로프를 포함한 경우,  
  사용할 로프의 수는 `(i + 1)`개  
- 각 경우에 대해 `A[i] * (i + 1)` 값을 계산하여 **최대값**을 찾는다.

이 방식은 **그리디(Greedy)** 알고리즘의 대표적인 예다.  
왜냐하면 “더 약한 로프를 포함할수록 전체 중량이 줄어든다”는 단순 규칙을 이용하기 때문.

---

## 코드 (C++)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.rbegin(), A.rend()); // 내림차순 정렬

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, A[i] * (i + 1));
    }

    cout << ans << "\n";
}
