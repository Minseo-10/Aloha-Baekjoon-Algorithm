# BOJ 4949 — 균형잡힌 세상

> 여러 문장에서 괄호의 짝이 올바르게 맞춰져 있는지 판별하는 문제.  
> 한 줄에 입력된 문자열마다 균형이 맞으면 `"yes"`, 아니면 `"no"`를 출력한다.

---

 문제 요약
- 입력  
  여러 줄의 문자열이 주어짐 (`.`, 괄호, 문자, 공백 등 포함)  
  `.`만 포함된 한 줄이 입력되면 종료.  

- 출력  
  각 줄마다 괄호의 균형이 맞으면 `"yes"`, 틀리면 `"no"`



 접근 방식
1. 스택(stack)을 사용해서 여는 괄호를 저장  
2. 닫는 괄호가 들어올 때마다 짝이 맞는지 검사  
3. 검사 규칙  
   - `'('`와 `')'` 짝  
   - `'['`와 `']'` 짝  
   - 순서가 맞지 않거나, 닫는 괄호가 남거나, 여는 괄호가 남으면 → 불균형(`no`)  
4. 마지막에 스택이 비어 있으면 균형(`yes`)



 코드


#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_valid(string);

int main() {
    string s;
    while (true) {
        getline(cin, s);
        if (s == ".") break;
        if (is_valid(s)) cout << "yes\n";
        else cout << "no\n";
    }
}

bool is_valid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[') st.push(c);
        else if (c == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}
