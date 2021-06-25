#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
stack<char> st;

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  bool first_player = false;
  for (int i = 0; i < s.length(); ++i) {
    if (st.size() > 0 && s[i] == st.top()) {
      st.pop();
      first_player = !first_player;
    } else {
      st.push(s[i]);
    }
  }
  if (first_player) printf("Yes");
  else printf("No");
  return 0;
}


