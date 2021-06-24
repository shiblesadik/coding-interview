#include <bits/stdc++.h>
using namespace std;

set<string> st;
int n;
string s, srr[200005];

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    srr[i] = s;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (st.find(srr[i]) == st.end()) {
      cout << srr[i] << endl;
      st.insert(srr[i]);
    }
  }
  return 0;
}
