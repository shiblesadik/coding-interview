#include <bits/stdc++.h>
using namespace std;

int n;
stack<char> st;
string s;

int main (void) {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      st.push(s[i]);
    } else {
      if (!st.empty() && st.top() == '(') {
        st.pop();
      } else {
        st.push(')');
      }
    }
  }
  if (st.size() == 0) {
    printf("Yes");
  } else if (st.size() == 2) {
    char last = st.top();
    st.pop();
    char first = st.top();
    st.pop();
    if (last == '(' && first == ')') {
      printf("Yes");
    } else {
      printf("No");
    }
  } else {
    printf("No");
  }
  return 0;
}
