baekjoon 2023번 - 신기한 소수/난이도 : 골드 5

-문제 설명
N자리의 수 중에서 모등 접두사가 소수인 수를 모두 출력하는 문제입니다.
예를 들어 7331은 7, 73, 733, 7331이 모두 소수이므로 "신기한 소수"입니다.

-접근 아이디어
숫자의 각 자리수를 DFS로 하나씩 붙여가며 생성합니다.
매 자리를 붙일 때마다 해당 수가 소수인지를 검사합니다.
->소수가 아니면 더 이상 탐색할 필요가 없습니다. (백트래킹)
가장 마지막 자리까지 도달하면 완성된 수를 출력합니다.

1. 첫 자리는 소수(2, 3, 5, 7)로 시작
2. 다음 자리에 1~9를 붙이며 "소수일 때만" 다음 단계로 재귀 호출
3. 길이가 N에 도달하면 출력

-핵심 포인트
완전탐색(DFS) + 가지치기(소수 검사)
매 단계마다 "소수성"을 유지해야 하므로 효율적인 가지치기가 중요
isprime함수에서 단순히 2부터 number/2까지 나눠보는 방식 사용 (입력 제한이 작으므로 충분히 통과)

코드(.cpp)
#include<iostream>
using namespace std;

static int N;

void DFS(int number, int jarisu);
bool isprime(int number);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  DFS(2,1);
  DFS(3,1);
  DFS(5,1);
  DFS(7,1);
  return 0;
  
  
}
void DfS(int number, int jarisu) {
  if(jarisu == N) {
    if(isprime(number)) cout << number << '\n';
    return;
  }
  for(int i = 1; i<=9; i++){
    int next = (number * 10) + i;
    if(isprime(next)) DFS(next, jarisu + 1);
  }

  }
 ool isprime(int number){
    for(int i=2; i<=number/2; i++){
        if(number%i==0) return false;

    }
    return true;
}








