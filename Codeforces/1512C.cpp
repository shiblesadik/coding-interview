#include <bits/stdc++.h>
using namespace std;

int test, n, m, arr[200005] = {0}, low = 0, high = 0, a, b;
string s;

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> test;
  while (test--) {
    cin >> a >> b;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') --a;
      else if (s[i] == '1') --b;
    }
    int i = 0, j = n - 1;
    while (i <= j) {
      if ((s[i] == '0' && s[j] == '?' && i != j) || (s[i] == '?' && s[j] == '0' && i != j)) {
        s[i] = '0';
        s[j] = '0';
        --a;
      } else if ((s[i] == '1' && s[j] == '?' && i != j) || (s[i] == '?' && s[j] == '1' && i != j)) {
        s[i] = '1';
        s[j] = '1';
        --b;
      }
      ++i, --j;
    }
    i = 0, j = n - 1;
    while (i <= j) {
      if (s[i] == '?' && s[j] == '?' && i != j) {
        if (a >= 2) {
          s[i] = '0';
          s[j] = '0';
          a -= 2;
        } else if (b >= 2) {
          s[i] = '1';
          s[j] = '1';
          b -= 2;
        }
      } else if (s[i] == '?' && i == j) {
        if (a >= 1) {
          s[i] = '0';
          --a;
        } else if (b >= 1) {
          s[i] = '1';
          --b;
        }
      }
      ++i, --j;
    }
    i = 0, j = n - 1;
    while (i <= j) {
      if (s[i] != s[j] || s[i] == '?' || s[j] == '?') {
        a = -1;
        b = -1;
        break;
      }
      ++i, --j;
    }
    if (a != 0 || b != 0) {
      cout << -1 << endl;
    } else {
      cout << s << endl;
    }
  }
  return 0;
}

