#include <bits/stdc++.h>
using namespace std;

int n, arr[10] = {0}, brr[10] = {0}, a = 0, b = 0;
string s, m;
string pattern_s = "0123456789";
string pattern_m = "1234567890";

int main (void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> s;
  cin >> m;
  sort(s.begin(), s.end());
  sort(m.begin(), m.end());
  int pos = 0, i = 0;
  char temp;
  i = 0, pos = 0;
  while (i < n) {
    if (s[pos] >= m[pos]) {
      temp = m[pos];
      m.erase(pos, 1);
      m = m + temp;
    } else {
      ++pos;
    }
    ++i;
  }
  for (i = 0; i < n; ++i) if (s[i] < m[i]) b++;
  sort(m.begin(), m.end());
  i = 0, pos = 0;
  while (i < n) {
    if (s[pos] > m[pos]) {
      temp = m[pos];
      m.erase(pos, 1);
      m = m + temp;
    } else {
      ++pos;
    }
    ++i;
  }
  for (i = 0; i < n; ++i) if (s[i] > m[i]) a++;
  cout << a << endl << b << endl;
  return 0;
}


