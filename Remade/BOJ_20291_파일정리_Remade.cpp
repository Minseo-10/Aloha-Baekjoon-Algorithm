/*
─────────────────────────────────────
🎯 Project : ALOHA Algorithm Remade
👩‍💻 Author : Minseo (Aloha Member)
💾 File    : BOJ_20291_파일정리_Remade.cpp
📚 Topic   : STL(Map, String)
🏷️ Level   : Silver 4
─────────────────────────────────────
📌 Problem
BOJ 20291 - 파일 정리

N개의 파일 이름이 주어질 때,
각 파일의 확장자별로 몇 개씩 있는지 세어서
확장자 이름 기준으로 사전순으로 출력하라.

─────────────────────────────────────
📖 Example
입력
8
sbrus.txt
spc.spc
acm.icpc
korea.icpc
sample.txt
hello.world
sogang.spc
example.txt

출력
icpc 2
spc 2
txt 3
world 1
─────────────────────────────────────
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // [자료구조 선택 이유]
    // map<string, int> : 
    //  - 확장자 이름(string)을 key로, 등장 횟수를 value로 저장
    //  - key 기준 자동 정렬 → 별도 sort 불필요
    map<string, int> cnt;

    for (int i = 0; i < N; i++) {
        string file;
        cin >> file;

        // 1️⃣ 확장자 추출
        //   - 파일명 중 마지막 '.' 뒤의 문자열이 확장자임.
        //   - rfind('.') : 문자열 뒤에서부터 '.' 위치 탐색
        size_t dot = file.rfind('.');

        //   - substr(dot + 1) : dot 이후부터 끝까지 추출
        string ext = file.substr(dot + 1);

        // 2️⃣ 해당 확장자 카운트 증가
        cnt[ext]++;
    }

    // 3️⃣ 사전순 출력 (map의 기본 순회 순서가 오름차순)
    for (auto &p : cnt)
        cout << p.first << ' ' << p.second << '\n';

    return 0;
}

/*
─────────────────────────────────────
🧠 Algorithm & CS Concept
─────────────────────────────────────
1. 문제 해결 로직
   - 확장자는 '.' 이후의 문자열이므로, 문자열 파싱 필요
   - 확장자별 등장 횟수를 카운트
   - map을 사용해 자동 정렬 및 중복 관리

2. STL 사용 이유
   - map<string,int> : 정렬 + 카운트 동시 처리
   - string::rfind() : 효율적인 문자열 탐색 (뒤에서부터)
   - string::substr() : 특정 구간 잘라내기

3. 시간복잡도
   - rfind : O(L)  (파일명 길이)
   - map 삽입 : O(log M) (M = 확장자 종류 수)
   → 전체 : O(N * log M)

4. 공간복잡도
   - map : 확장자 종류만큼 key-value 저장 → O(M)

─────────────────────────────────────
📘 학습 포인트 (전과 프로젝트 연결)
─────────────────────────────────────
💡 “문자열 처리 + STL 자료구조 활용 능력”
   - 문자열을 직접 파싱하고 필요한 부분만 추출하는 로직 설계 연습.
   - map을 이용해 정렬과 카운트를 동시에 수행함으로써
     자료구조 선택의 이유를 명확히 함.

💡 “백엔드 개발의 데이터 구조 감각”
   - map 구조는 실제 서버 측에서 key-value DB(예: Redis, HashMap)와 유사.
   - key 기준 정렬(map), 해시 기반 검색(unordered_map)의 차이를 
     실제로 코드로 체득하는 과정.

💡 “코드 품질 향상과 리팩토링 훈련”
   - 불필요한 set 삭제 → 코드 단순화 및 명확한 역할 분리
   - 함수화나 예외처리 확장 여지 남겨둠
   - ‘Remade’ 파일은 단순 정답이 아닌 구조적 사고 과정을 기록

─────────────────────────────────────
🔍 Review Note
─────────────────────────────────────
- 처음엔 set 두 개를 사용했지만, 목적이 "확장자별 카운트"였으므로
  map 하나로 충분함을 깨달음.
- string.find() 대신 string.rfind() 사용으로 
  다중 점(‘archive.tar.gz’) 파일명도 처리 가능하게 개선.
- map 순회 시 자동 정렬이 적용되므로 sort 불필요.
─────────────────────────────────────
✅ Key Takeaway
→ “map 하나로 정렬 + 빈도 관리까지 해결 가능”
─────────────────────────────────────
*/
