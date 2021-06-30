#include <bits/stdc++.h>
using namespace std;

int test, n, k, m, total = 0, x, r;
char s[200005], a[1000];

int main (void) {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  gets(s);
  gets(a);
  n = strlen(s);
  m = strlen(a);
  int i = 0, j = 0;
  while (i < n) {
    x = i;
    j = 0;
    k = 0;
    while (s[x] == a[j] && j < m && x < n) {
      ++k;
      ++x;
      ++j;
    }
    if (k == m) {
      ++total;
      i += m;
    } else {
      ++i;
    }
  }
  printf("%d\n", total);
  return 0;
}
