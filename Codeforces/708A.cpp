#include <bits/stdc++.h>
using namespace std;

string s;
int n, m, k;

int main (void) {
  cin >> s;
  n = s.length();
  int start_pos = -1, end_pos = -1, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'a' && start_pos == -1) {
      start_pos = i;
    } else if (s[i] == 'a' && start_pos != -1) {
      end_pos = i;
      break;
    }
  }
  if (end_pos == -1 && start_pos != -1) {
    end_pos = n;
  } else if (start_pos == -1){
    start_pos = n - 1;
    end_pos = n;
  }
  cerr << start_pos << " " << end_pos << endl;
  for (int i = start_pos; i < end_pos; ++i) {
    if (s[i] == 'a') {
      s[i] = 'z';
    } else {
      s[i] = s[i] - 1;
    }
  }
  cout << s << endl;
  return 0;
}
